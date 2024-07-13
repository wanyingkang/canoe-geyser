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
#include "bryan_vapor_functions.hpp"

int iH2O, iH2Oc;
Real p0, grav;
Real Rd;
Real Ptriple1, Ttriple1, Rgas, mu1;
Real tau;
Real gamma_hydro;

void MeshBlock::InitUserMeshBlockData(ParameterInput *pin) {
  AllocateUserOutputVariables(7);
  SetUserOutputVariableName(0, "temp");
  SetUserOutputVariableName(1, "theta");
  SetUserOutputVariableName(2, "theta_v");
  SetUserOutputVariableName(3, "mse");
  SetUserOutputVariableName(4, "theta_e");
  SetUserOutputVariableName(5, "rh");
  SetUserOutputVariableName(6, "qtol");
}

void MeshBlock::UserWorkBeforeOutput(ParameterInput *pin) {
  auto pthermo = Thermodynamics::GetInstance();

  for (int k = ks; k <= ke; ++k)
    for (int j = js; j <= je; ++j)
      for (int i = is; i <= ie; ++i) {
        user_out_var(0, k, j, i) = pthermo->GetTemp(this, k, j, i);
        user_out_var(1, k, j, i) = pthermo->PotentialTemp(this, p0, k, j, i);
        // theta_v
        user_out_var(2, k, j, i) =
            user_out_var(1, j, i) * pthermo->RovRd(this, k, j, i);
        // mse
        user_out_var(3, k, j, i) =
            pthermo->MoistStaticEnergy(this, grav * pcoord->x1v(i), k, j, i);
        // theta_e
        user_out_var(4, k, j, i) =
            pthermo->EquivalentPotentialTemp(this, p0, iH2O, k, j, i);
        user_out_var(5, k, j, i) =
            pthermo->RelativeHumidity(this, iH2O, k, j, i);
        // total mixing ratio
        auto &&air = AirParcelHelper::gather_from_primitive(this, k, j, i);
        user_out_var(6, k, j, i) = air.w[iH2O] + air.c[iH2Oc];
      }
}

void ForcingSource(MeshBlock *pmb, Real const time, Real const dt,
                        AthenaArray<Real> const &w, AthenaArray<Real> const &r,
                        AthenaArray<Real> const &bcc, AthenaArray<Real> &u,
                        AthenaArray<Real> &s) {
  int is = pmb->is;
  int ie = pmb->ie;

  Real p, drho;
  Real flux_water_mixing_ratio;

  flux_water_mixing_ratio = 0.9;

  Real x1s = pmb->pcoord->x1f(is);
  Real relaxation_factor;

  if (x1s < pmb->pcoord->dx1f(is)) {
      for (int k = pmb->ks; k <= pmb->ke; ++k)
        for (int j = pmb->js; j <= pmb->je; ++j) {
            p = pmb->phydro->w(IPR, k, j, is);
            drho = (
                dt * (Ptriple1 - p) / sqrt(2 * M_PI * Rgas * Ttriple1 / mu1)
                ) / pmb->pcoord->dx1f(is);
            // drho = dt * 0.0028 / pmb->pcoord->dx1f(is); // for testing
            u(iH2O, k, j, is) += flux_water_mixing_ratio * drho;
            u(IDN, k, j, is) += (1. - flux_water_mixing_ratio) * drho;
            u(IEN, k, j, is) += drho * (Rd / (gamma_hydro - 1.)) * Ttriple1;
        }
  }

  relaxation_factor = exp(-dt/tau);

  // if (x1e > pmb->pmy_mesh->mesh_size.x1max - pmb->pcoord->dx1f(ie)) {
  // for (int i = pmb->is; i <= pmb->ie; ++i) {
  //     if (pmb->pcoord->x1f(i) > 0.9 * pmb->pmy_mesh->mesh_size.x1max) {
  //         for (int k = pmb->ks; k <= pmb->ke; ++k)
  //           for (int j = pmb->js; j <= pmb->je; ++j) {
  //               u(IDN, k, j, i) *= relaxation_factor;
  //               u(iH2O, k, j, i) *= relaxation_factor;
  //               u(IEN, k, j, i) *= relaxation_factor;
  //               u(IVX, k, j, i) *= relaxation_factor;
  //               u(IVY, k, j, i) *= relaxation_factor;
  //               u(IVZ, k, j, i) *= relaxation_factor;
  //           }
  //     }
  // }
}

void Mesh::InitUserMeshData(ParameterInput *pin) {
  auto pindex = IndexMap::GetInstance();

  tau = pin->GetReal("problem", "tau");

  Ptriple1 = pin->GetReal("thermodynamics", "Ptriple1");
  Ttriple1 = pin->GetReal("thermodynamics", "Ttriple1");
  Rgas = pin->GetReal("thermodynamics", "Rgas");
  mu1 = pin->GetReal("thermodynamics", "mu1");
  Rd = pin->GetReal("thermodynamics", "Rd");

  gamma_hydro = pin->GetReal("hydro", "gamma");
  // rcp1 = pin->GetReal("thermodynamics", "rcp1");

  grav = -pin->GetReal("hydro", "grav_acc1");
  p0 = pin->GetReal("problem", "p0");

  // index
  iH2O = pindex->GetVaporId("H2O");
  iH2Oc = pindex->GetCloudId("H2O(c)");

  EnrollUserExplicitSourceFunction(ForcingSource);
}

void MeshBlock::ProblemGenerator(ParameterInput *pin) {

    Real rho = 0.01f*Ptriple1*mu1/(Rgas*Ttriple1);

    for (int k = ks; k <= ke; ++k) {
        for (int j = js; j <= je; ++j) {
            for (int i = is; i <= ie; ++i) {
                this->phydro->w(IDN, k, j, i) = rho;
                this->phydro->w(iH2O, k, j, i) = 0.1;
                for (int n = iH2O + 1; n < IPR; ++n) {
                    this->phydro->w(n, k, j, i) = 0.f;
                }
                this->phydro->w(IPR, k, j, i) = Ttriple1 * rho * Rgas / mu1;
            }
        }
    }
    peos->PrimitiveToConserved(phydro->w, pfield->bcc, phydro->u, pcoord, is, ie,
                             js, je, ks, ke);
}
