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

void ForcingSource(MeshBlock *pmb, Real const time, Real const dt,
                        AthenaArray<Real> const &w, AthenaArray<Real> const &r,
                        AthenaArray<Real> const &bcc, AthenaArray<Real> &u,
                        AthenaArray<Real> &s) {
  int is = pmb->is;
  int ie = pmb->ie;

  auto pthermo = Thermodynamics::GetInstance();

  Real p, drhoH2O, drhoH2, drhoCO2;
  Real massflux_CO2ratio, massflux_H2ratio;


  Real x1s = pmb->pcoord->x1f(is);
  Real relaxation_factor;

  if (x1s < pmb->pcoord->dx1f(is)) {
      for (int k = pmb->ks; k <= pmb->ke; ++k)
        for (int j = pmb->js; j <= pmb->je; ++j) {
            
	    p = pmb->phydro->w(IPR, k, j, is);
	    massflux_H2ratio=0.1;
	    massflux_CO2ratio=0.01;

	    // add water vapor
        drhoH2O = (
            dt * (Ptriple1 - p) / sqrt(2 * M_PI * Rd * Ttriple1 / pthermo->GetMuRatio(iH2O))
            ) / pmb->pcoord->dx1f(is);
        u(iH2O, k, j, is) += drhoH2O;
        u(IEN, k, j, is) += drhoH2O * (Rd / (gammad - 1.)) * pthermo->GetCvRatioMass(iH2O) * Ttriple1;
        std::cout << "H2O Cv" << Rd / (gammad - 1.)*pthermo->GetCvRatioMass(iH2O)  << std::endl;
	    // add dry air (H2)
	    drhoH2=drhoH2O*massflux_H2ratio;
        u(IDN, k, j, is) += drhoH2;
        u(IEN, k, j, is) += drhoH2 * (Rd / (gammad - 1.)) * Ttriple1;
        std::cout << "H2 Cv" << Rd / (gammad - 1.)  << std::endl;
	    // add CO2
	    drhoCO2=drhoH2O*massflux_CO2ratio;
	    u(iCO2, k, j, is) += drhoCO2;
        u(IEN, k, j, is) += drhoCO2 * (Rd / (gammad - 1.)) * pthermo->GetCvRatioMass(iCO2) * Ttriple1;
        std::cout << "CO2 Cv" << Rd / (gammad - 1.)*pthermo->GetCvRatioMass(iCO2)  << std::endl;
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
  Rd = pin->GetReal("thermodynamics", "Rd");

  gammad = pin->GetReal("hydro", "gamma");
  // rcp1 = pin->GetReal("thermodynamics", "rcp1");

  grav = -pin->GetReal("hydro", "grav_acc1");
  p0 = pin->GetReal("problem", "p0");

  // index
  iH2O = pindex->GetVaporId("H2O");
  iH2Oc = pindex->GetCloudId("H2O(c)");
  iCO2 = pindex->GetVaporId("CO2");
  iCO2c = pindex->GetCloudId("CO2(c)");

  EnrollUserExplicitSourceFunction(ForcingSource);
}

void MeshBlock::ProblemGenerator(ParameterInput *pin) {

    auto pthermo = Thermodynamics::GetInstance();
    Real rho = 1.0e-5;
    Real dryratio,H2Oratio, CO2ratio, H2Ocratio, CO2cratio;

    H2Oratio=0.1f;
    H2Ocratio=0.001f;
    CO2ratio=0.1f;
    CO2cratio=0.001f;
    dryratio=1.0f-H2Oratio-H2Ocratio-CO2ratio-CO2cratio;

    for (int k = ks; k <= ke; ++k) {
        for (int j = js; j <= je; ++j) {
            for (int i = is; i <= ie; ++i) {
                this->phydro->w(IDN, k, j, i) = rho;
                this->phydro->w(iH2O, k, j, i) = H2Oratio;
                this->phydro->w(iCO2, k, j, i) = CO2ratio;
                this->phydro->w(iH2Oc, k, j, i) = H2Ocratio;
                this->phydro->w(iCO2c, k, j, i) = CO2cratio;
                for (int n = IVX; n < IPR; ++n) {
                    this->phydro->w(n, k, j, i) = 0.f;
                }
                this->phydro->w(IPR, k, j, i) = Ttriple1 * dryratio * rho * Rd;
                this->phydro->w(IPR, k, j, i) += Ttriple1 * H2Oratio * rho * Rd / pthermo->GetMuRatio(iH2O);
                this->phydro->w(IPR, k, j, i) += Ttriple1 * CO2ratio * rho * Rd / pthermo->GetMuRatio(iCO2);
                std::cout << "P" << this->phydro->w(IPR, k, j, i)  << std::endl;
                std::cout << "Ttriple1" << Ttriple1 << "dryratio" << dryratio<<"rho"<<rho<<"Rd"<<Rd  << std::endl;
                //std::cout << "rho" << rho << "P" << this->phydro->w(IPR, k, j, i) << std::endl;
                //std::cout << "muratio" << pthermo->GetMuRatio(iCO2) << std::endl;
            }
        }
    }
    peos->PrimitiveToConserved(phydro->w, pfield->bcc, phydro->u, pcoord, is, ie,
                             js, je, ks, ke);
}
