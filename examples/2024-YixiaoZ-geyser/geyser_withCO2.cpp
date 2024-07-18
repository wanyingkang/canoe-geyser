/* -------------------------------------------------------------------------------------
 * SNAP Example Program
 *
 * Contributer:
 * Cheng Li, University of Michigan
 *
 * Year: 2023
 * Contact: chengcli@umich.edu
 * Reference: Bryan and Fritsch, 2002
 * -------------------------------------------------------------------------------------
 */

// athena
#include <athena/athena.hpp>
#include <athena/athena_arrays.hpp>
#include <athena/bvals/bvals.hpp>
#include <athena/coordinates/coordinates.hpp>
#include <athena/eos/eos.hpp>
#include <athena/field/field.hpp>
#include <athena/hydro/hydro.hpp>
#include <athena/mesh/mesh.hpp>
#include <athena/parameter_input.hpp>

// application
#include <application/application.hpp>
#include <application/exceptions.hpp>

// canoe
#include <impl.hpp>
#include <index_map.hpp>

// climath
#include <climath/core.h>
#include <climath/interpolation.h>

#include <climath/root.hpp>

// snap
#include <snap/thermodynamics/atm_thermodynamics.hpp>

// special includes
#include "geyser_vapor_functions.hpp"

int iH2O, iH2Oc, iCO2, iCO2c;
Real p0, grav;
Real Rd;
Real Ptriple1, Ttriple1;
Real tau;
Real gammad;
Real massflux_H2ratio, massflux_CO2ratio;
Real Tm, Ts;
Real x1min, x1max, x2min, x2max;

Real wall1_corner_x2;
Real wall1_corner_x1;
Real wall2_corner_x2;
Real wall2_corner_x1;

void MeshBlock::InitUserMeshBlockData(ParameterInput *pin) {
  AllocateUserOutputVariables(5);
  SetUserOutputVariableName(0, "temp");
  SetUserOutputVariableName(1, "h2o");
  SetUserOutputVariableName(2, "h2oc");
  SetUserOutputVariableName(3, "co2");
  SetUserOutputVariableName(4, "co2c");
}

void MeshBlock::UserWorkBeforeOutput(ParameterInput *pin) {
  auto pthermo = Thermodynamics::GetInstance();

  for (int k = ks; k <= ke; ++k)
    for (int j = js; j <= je; ++j)
      for (int i = is; i <= ie; ++i) {
        user_out_var(0, k, j, i) = pthermo->GetTemp(this, k, j, i);
        auto &&air = AirParcelHelper::gather_from_primitive(this, k, j, i);
        user_out_var(1, k, j, i) = air.w[iH2O];
        user_out_var(2, k, j, i) = air.c[iH2Oc];
        user_out_var(3, k, j, i) = air.w[iCO2];
        user_out_var(4, k, j, i) = air.c[iCO2c];
      }
}



void WallInteraction(MeshBlock *pmb, Real const time, Real const dt,
                        AthenaArray<Real> const &w, AthenaArray<Real> const &r,
                        AthenaArray<Real> const &bcc, AthenaArray<Real> &u,
                        AthenaArray<Real> &s) {
  int js = pmb->js;
  int je = pmb->je;
  int is = pmb->is;
  int ie = pmb->ie;
  int jw; // index of j at the wall

  auto pthermo = Thermodynamics::GetInstance();

  Real p_H2O, drhoH2O, drhoH2, drhoCO2;
  Real Tw, Pw, Ta, z, csw, csa, KE;

  Real x2f_left, x2f_right, x1f_left, x1f_right, x1f_center, x2f_center;


  // remove water vapor
  for (int jj = 0; jj <= 1; ++jj) {
    jw = (jj == 0) ? js : je;
    x2f_left = pmb->pcoord->x2f(jw);
    x2f_right = pmb->pcoord->x2f(jw+1);
    x2f_center = (x2f_left+x2f_right)/2;
    x1f_left = pmb->pcoord->x1f(is);
    x1f_right = pmb->pcoord->x1f(ie+1);
    x1f_center = (x1f_left+x1f_right)/2;

    if ( (x2f_center < wall1_corner_x2) || (x2f_center > wall2_corner_x2) ) {
              continue;
          }
    if ( (x1f_center > wall1_corner_x1) ) { // assume wall1_corner_x1 == wall2_corner_x1
              continue;
          }
    if ( (x2f_left - wall1_corner_x2 < pmb->pcoord->dx2f(js)) || (wall2_corner_x2 - x2f_right < pmb->pcoord->dx2f(je))) {
       for (int k = pmb->ks; k <= pmb->ke; ++k)
          for (int i = pmb->is; i <= pmb->ie; ++i) {

          Ta = pthermo->GetTemp(pmb, k, jw, i);

          p_H2O = (
            pmb->phydro->w(IDN, k, jw, i) * pmb->phydro->w(iH2O, k, jw, i)
            * Rd * Ta / pthermo->GetMuRatio(iH2O)
          );
          z = pmb->pcoord->x1f(i);
          Tw = Tm * pow(Ts/Tm, (z-x1min)/(x1max-x1min));
          Pw = sat_vapor_p_H2O(Tw);

          csw = sqrt(2 * M_PI * Rd * Tw / pthermo->GetMuRatio(iH2O));
          csa = sqrt(2 * M_PI * Rd * Ta / pthermo->GetMuRatio(iH2O));

          drhoH2O = dt * (Pw/csw - p_H2O/csa) / pmb->pcoord->dx2f(jw);


          u(iH2O, k, jw, i) += drhoH2O;

          if (drhoH2O<0) {
              KE= 0.5f*(pmb->phydro->w(IVX,k,jw,i)*pmb->phydro->w(IVX,k,jw,i)
                      + pmb->phydro->w(IVY,k,jw,i)*pmb->phydro->w(IVY,k,jw,i)
                      + pmb->phydro->w(IVZ,k,jw,i)*pmb->phydro->w(IVZ,k,jw,i));
              u(IEN, k, jw, i) += drhoH2O * (
                KE + (Rd / (gammad - 1.)) * pthermo->GetCvRatioMass(iH2O) * Ta
              );
              u(IVZ, k, jw, i) += drhoH2O * pmb->phydro->w(IVZ, k, jw, i);
              u(IVY, k, jw, i) += drhoH2O * pmb->phydro->w(IVY, k, jw, i);
              u(IVX, k, jw, i) += drhoH2O * pmb->phydro->w(IVX, k, jw, i);
          } else {
              u(IEN, k, jw, i) += drhoH2O * (
                (Rd / (gammad - 1.)) * pthermo->GetCvRatioMass(iH2O) * Tw
              );
          }
       }
    }
  }
}


void BottomInjection(MeshBlock *pmb, Real const time, Real const dt,
                        AthenaArray<Real> const &w, AthenaArray<Real> const &r,
                        AthenaArray<Real> const &bcc, AthenaArray<Real> &u,
                        AthenaArray<Real> &s) {
  int is = pmb->is;
  int ie = pmb->ie;

  auto pthermo = Thermodynamics::GetInstance();

  Real p, drhoH2O, drhoH2, drhoCO2;

  Real x1s = pmb->pcoord->x1f(is);

  if (x1s < x1min+pmb->pcoord->dx1f(is)) {
      for (int k = pmb->ks; k <= pmb->ke; ++k)
        for (int j = pmb->js; j <= pmb->je; ++j) {
          //std::cout << pmb->pcoord->x2v(j) << std::endl;
          // inject at the center of the bottom boundary
          if ((pmb->pcoord->x2v(j) < wall1_corner_x2) || pmb->pcoord->x2v(j) > wall2_corner_x2) {
              continue;
          }
            
	    p = pmb->phydro->w(IPR, k, j, is);

	    // add water vapor
        drhoH2O = (
            dt * (Ptriple1 - p) / sqrt(2 * M_PI * Rd * Ttriple1 / pthermo->GetMuRatio(iH2O))
            ) / pmb->pcoord->dx1f(is);
        u(iH2O, k, j, is) += drhoH2O;
        u(IEN, k, j, is) += drhoH2O * (Rd / (gammad - 1.)) * pthermo->GetCvRatioMass(iH2O) * Ttriple1;
	    // add dry air (H2)
	    drhoH2=drhoH2O*massflux_H2ratio;
        u(IDN, k, j, is) += drhoH2;
        u(IEN, k, j, is) += drhoH2 * (Rd / (gammad - 1.)) * Ttriple1;
	    // add CO2
	    drhoCO2=drhoH2O*massflux_CO2ratio;
	    u(iCO2, k, j, is) += drhoCO2;
        u(IEN, k, j, is) += drhoCO2 * (Rd / (gammad - 1.)) * pthermo->GetCvRatioMass(iCO2) * Ttriple1;
        }
  }

}

void Forcing(MeshBlock *pmb, Real const time, Real const dt,
                        AthenaArray<Real> const &w, AthenaArray<Real> const &r,
                        AthenaArray<Real> const &bcc, AthenaArray<Real> &u,
                        AthenaArray<Real> &s) {
  BottomInjection(pmb, time, dt, w, r, bcc, u, s);
  WallInteraction(pmb, time, dt, w, r, bcc, u, s);
}

void reflecting_x2_left(MeshBlock *pmb, Coordinates *pco,
                     AthenaArray<Real> &prim, FaceField &b,
                     Real time, Real dt,
                     int il, int iu, int jl, int ju, int kl, int ku, int ngh)
{
  // copy hydro variables into ghost zones, reflecting v2
  for (int n=0; n<=NHYDRO; ++n) {
    if (n == IVY) {
      for (int k=kl; k<=ku; ++k) {
        for (int j=1; j<=ngh; ++j) {
          for (int i=il; i<=iu; ++i) {
            prim(IVY,k,jl-j,i) = -prim(IVY,k,jl+j-1,i);  // reflect 2-velocity
          }
        }
      }
    } else {
      for (int k=kl; k<=ku; ++k) {
        for (int j=1; j<=ngh; ++j) {
          for (int i=il; i<=iu; ++i) {
            prim(n,k,jl-j,i) = prim(n,k,jl+j-1,i);
          }
        }
      }
    }
  }
}

void reflecting_x2_right(MeshBlock *pmb, Coordinates *pco,
                      AthenaArray<Real> &prim, FaceField &b,
                      Real time, Real dt,
                      int il, int iu, int jl, int ju, int kl, int ku, int ngh)
{
  // copy hydro variables into ghost zones, reflecting v2
  for (int n=0; n<=NHYDRO; ++n) {
    if (n == (IVY)) {
      for (int k=kl; k<=ku; ++k) {
        for (int j=1; j<=ngh; ++j) {
#pragma omp simd
          for (int i=il; i<=iu; ++i) {
            prim(IVY,k,ju+j,i) = -prim(IVY,k,ju-j+1,i);  // reflect 2-velocity
          }
        }
      }
    } else {
      for (int k=kl; k<=ku; ++k) {
        for (int j=1; j<=ngh; ++j) {
#pragma omp simd
          for (int i=il; i<=iu; ++i) {
            prim(n,k,ju+j,i) = prim(n,k,ju-j+1,i);
          }
        }
      }
    }
  }

}

void reflecting_x1_left(MeshBlock *pmb, Coordinates *pco,
                     AthenaArray<Real> &prim, FaceField &b,
                     Real time, Real dt,
                     int il, int iu, int jl, int ju, int kl, int ku, int ngh)
{
  for (int n=0; n<=NHYDRO; ++n) {
    if (n == IVX) {
      for (int k=kl; k<=ku; ++k) {
        for (int j=jl; j<=jl; ++j) {
          for (int i=1; i<=ngh; ++i) {
            prim(n,k,j,il-i) = -prim(n,k,j,il+i-1);
          }
        }
      }
    } else {
      for (int k=kl; k<=ku; ++k) {
        for (int j=jl; j<=jl; ++j) {
          for (int i=1; i<=ngh; ++i) {
            prim(n,k,j,il-i) = prim(n,k,j,il+i-1);
          }
        }
      }
    }
  }
}

void reflecting_x1_right(MeshBlock *pmb, Coordinates *pco,
                      AthenaArray<Real> &prim, FaceField &b,
                      Real time, Real dt,
                      int il, int iu, int jl, int ju, int kl, int ku, int ngh)
{
  for (int n=0; n<=NHYDRO; ++n) {
    if (n == (IVX)) {
      for (int k=kl; k<=ku; ++k) {
        for (int j=jl; j<=ju; ++j) {
#pragma omp simd
          for (int i=1; i<=ngh; ++i) {
            prim(n,k,j,iu + i) = -prim(n,k,j,iu-i+1);
          }
        }
      }
    } else {
      for (int k=kl; k<=ku; ++k) {
        for (int j=jl; j<=ju; ++j) {
#pragma omp simd
          for (int i=1; i<=ngh; ++i) {
            prim(n,k,j,iu + i) = prim(n,k,j,iu-i+1);
          }
        }
      }
    }
  }

}
bool fclose(Real x, Real x0) {
  return std::abs(x - x0) < 1.e-6;
}

void Mesh::InitUserMeshData(ParameterInput *pin) {
  auto pindex = IndexMap::GetInstance();

  tau = pin->GetReal("problem", "tau");

  Ptriple1 = pin->GetReal("thermodynamics", "Ptriple1");
  Ttriple1 = pin->GetReal("thermodynamics", "Ttriple1");
  Rd = pin->GetReal("thermodynamics", "Rd");
  x1min = pin->GetReal("mesh","x1min");
  x1max = pin->GetReal("mesh","x1max");
  x2min = pin->GetReal("mesh","x2min");
  x2max = pin->GetReal("mesh","x2max");

  gammad = pin->GetReal("hydro", "gamma");
  // rcp1 = pin->GetReal("thermodynamics", "rcp1");

  grav = -pin->GetReal("hydro", "grav_acc1");
  p0 = pin->GetReal("problem", "p0");

  massflux_H2ratio = pin->GetReal("thermodynamics", "massflux_H2ratio");
  massflux_CO2ratio = pin->GetReal("thermodynamics", "massflux_CO2ratio");
  Tm = pin->GetReal("problem", "Tm");
  Ts = pin->GetReal("problem", "Ts");

  // index
  iH2O = pindex->GetVaporId("H2O");
  iH2Oc = pindex->GetCloudId("H2O(c)");
  iCO2 = pindex->GetVaporId("CO2");
  iCO2c = pindex->GetCloudId("CO2(c)");

  wall1_corner_x1 = pin->GetReal("problem", "wall1_corner_x1");
  wall1_corner_x2 = pin->GetReal("problem", "wall1_corner_x2");
  wall2_corner_x1 = pin->GetReal("problem", "wall2_corner_x1");
  wall2_corner_x2 = pin->GetReal("problem", "wall2_corner_x2");

  EnrollUserExplicitSourceFunction(Forcing);
}

void MeshBlock::ProblemGenerator(ParameterInput *pin) {

    auto pthermo = Thermodynamics::GetInstance();
    Real rho = 2.0e-3;
    Real dryratio,H2Oratio, CO2ratio;

    H2Oratio=0.8f;
    CO2ratio=0.15f;
    dryratio=1.0f-H2Oratio-CO2ratio;

    for (int k = ks; k <= ke; ++k) {
        for (int j = js; j <= je; ++j) {
            for (int i = is; i <= ie; ++i) {
                this->phydro->w(IDN, k, j, i) = rho;
                this->phydro->w(iH2O, k, j, i) = H2Oratio;
                this->phydro->w(iCO2, k, j, i) = CO2ratio;
                for (int n = IVX; n < IPR; ++n) {
                    this->phydro->w(n, k, j, i) = 0.f;
                }
                this->phydro->w(IPR, k, j, i) = Ttriple1 * dryratio * rho * Rd;
                this->phydro->w(IPR, k, j, i) += Ttriple1 * H2Oratio * rho * Rd / pthermo->GetMuRatio(iH2O);
                this->phydro->w(IPR, k, j, i) += Ttriple1 * CO2ratio * rho * Rd / pthermo->GetMuRatio(iCO2);
                //std::cout << "IDN"<<IDN<<" iH2O"<<iH2O<<" iCO2"<<iCO2<<" iH2Oc"<<iH2Oc<<" iCO2c"<< iCO2c<< std::endl;
            }
        }
    }
    peos->PrimitiveToConserved(phydro->w, pfield->bcc, phydro->u, pcoord, is, ie,
                             js, je, ks, ke);

  Real x1min = block_size.x1min;
  Real x1max = block_size.x1max;
  Real x1c = (x1min + x1max) / 2;
  Real x2min = block_size.x2min;
  Real x2max = block_size.x2max;
  Real x2c = (x2min + x2max) / 2;

  if (fclose(x2min, wall1_corner_x2) && (x1c < wall1_corner_x1)) {
    pmy_mesh->mesh_bcs[BoundaryFace::inner_x2] = BoundaryFlag::user;
    pbval->block_bcs[BoundaryFace::inner_x2] = BoundaryFlag::user;
    pbval->apply_bndry_fn_[BoundaryFace::inner_x2] = true;
    std::cout << "Boundary left enrolled" << std::endl;
    pmy_mesh->EnrollUserBoundaryFunction(BoundaryFace::inner_x2, reflecting_x2_left);
  }

  if (fclose(x2max, wall1_corner_x2) && (x1c < wall1_corner_x1)) {
    pmy_mesh->mesh_bcs[BoundaryFace::outer_x2] = BoundaryFlag::user;
    pbval->block_bcs[BoundaryFace::outer_x2] = BoundaryFlag::user;
    pbval->apply_bndry_fn_[BoundaryFace::outer_x2] = true;
    std::cout << "Boundary right enrolled" << std::endl;
    pmy_mesh->EnrollUserBoundaryFunction(BoundaryFace::outer_x2, reflecting_x2_right);
  }

  if ((x2c < wall1_corner_x2) && fclose(x1max, wall1_corner_x1)) {
    pmy_mesh->mesh_bcs[BoundaryFace::outer_x1] = BoundaryFlag::user;
    pbval->block_bcs[BoundaryFace::outer_x1] = BoundaryFlag::user;
    pbval->apply_bndry_fn_[BoundaryFace::outer_x1] = true;
    pmy_mesh->EnrollUserBoundaryFunction(BoundaryFace::outer_x1, reflecting_x1_right);
  }

  if ((x2c < wall1_corner_x2) && fclose(x1min, wall1_corner_x1)) {
    pmy_mesh->mesh_bcs[BoundaryFace::inner_x1] = BoundaryFlag::user;
    pbval->block_bcs[BoundaryFace::inner_x1] = BoundaryFlag::user;
    pbval->apply_bndry_fn_[BoundaryFace::inner_x1] = true;
    pmy_mesh->EnrollUserBoundaryFunction(BoundaryFace::inner_x1, reflecting_x1_left);
  }

  // add a block
  if (fclose(x2min, wall2_corner_x2) && (x1c < wall2_corner_x1)) {
    pmy_mesh->mesh_bcs[BoundaryFace::inner_x2] = BoundaryFlag::user;
    pbval->block_bcs[BoundaryFace::inner_x2] = BoundaryFlag::user;
    pbval->apply_bndry_fn_[BoundaryFace::inner_x2] = true;
    std::cout << "Boundary left enrolled" << std::endl;
    pmy_mesh->EnrollUserBoundaryFunction(BoundaryFace::inner_x2, reflecting_x2_left);
  }

  if (fclose(x2max, wall2_corner_x2) && (x1c < wall2_corner_x1)) {
    pmy_mesh->mesh_bcs[BoundaryFace::outer_x2] = BoundaryFlag::user;
    pbval->block_bcs[BoundaryFace::outer_x2] = BoundaryFlag::user;
    pbval->apply_bndry_fn_[BoundaryFace::outer_x2] = true;
    std::cout << "Boundary right enrolled" << std::endl;
    pmy_mesh->EnrollUserBoundaryFunction(BoundaryFace::outer_x2, reflecting_x2_right);
  }

  if ((x2c > wall2_corner_x2) && fclose(x1max, wall2_corner_x1)) {
    pmy_mesh->mesh_bcs[BoundaryFace::outer_x1] = BoundaryFlag::user;
    pbval->block_bcs[BoundaryFace::outer_x1] = BoundaryFlag::user;
    pbval->apply_bndry_fn_[BoundaryFace::outer_x1] = true;
    pmy_mesh->EnrollUserBoundaryFunction(BoundaryFace::outer_x1, reflecting_x1_right);
  }

  if ((x2c > wall2_corner_x2) && fclose(x1min, wall2_corner_x1)) {
    pmy_mesh->mesh_bcs[BoundaryFace::inner_x1] = BoundaryFlag::user;
    pbval->block_bcs[BoundaryFace::inner_x1] = BoundaryFlag::user;
    pbval->apply_bndry_fn_[BoundaryFace::inner_x1] = true;
    pmy_mesh->EnrollUserBoundaryFunction(BoundaryFace::inner_x1, reflecting_x1_left);
  }

}
