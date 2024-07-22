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
#include "lava_vapor_functions.hpp"

int iNa, iNac, iSiO, iSiOc;
int INA, ISIO;
Real p0, grav;
Real Rd;
Real Ptriple1, Ttriple1;
Real tau;
Real gammad;
Real massflux_dryratio;
Real Ts, Ps1, Ps2, Achem1, Achem2, Bchem1, Bchem2;
Real x1min, x1max, x2min, x2max;


void MeshBlock::InitUserMeshBlockData(ParameterInput *pin) {
  AllocateUserOutputVariables(5);
  SetUserOutputVariableName(0, "temp");
  SetUserOutputVariableName(1, "Na");
  SetUserOutputVariableName(2, "Nac");
  SetUserOutputVariableName(3, "SiO");
  SetUserOutputVariableName(4, "SiOc");
}

void MeshBlock::UserWorkBeforeOutput(ParameterInput *pin) {
  auto pthermo = Thermodynamics::GetInstance();

  for (int k = ks; k <= ke; ++k)
    for (int j = js; j <= je; ++j)
      for (int i = is; i <= ie; ++i) {
        user_out_var(0, k, j, i) = pthermo->GetTemp(this, k, j, i);
        auto &&air = AirParcelHelper::gather_from_primitive(this, k, j, i);
        user_out_var(1, k, j, i) = air.w[iNa];
        user_out_var(2, k, j, i) = air.c[iNac];
        user_out_var(3, k, j, i) = air.w[iSiO];
        user_out_var(4, k, j, i) = air.c[iSiOc];
      }
}


void BottomInjection(MeshBlock *pmb, Real const time, Real const dt,
                        AthenaArray<Real> const &w, AthenaArray<Real> const &r,
                        AthenaArray<Real> const &bcc, AthenaArray<Real> &u,
                        AthenaArray<Real> &s) {
  int is = pmb->is;
  int ie = pmb->ie;

  auto pthermo = Thermodynamics::GetInstance();
  Real rhoNa, rhoSiO, Tmix, pNa, pSiO;
  Real drhoNa, drhodry, drhoSiO;

  Real x1s = pmb->pcoord->x1f(is);

  if (x1s < x1min+pmb->pcoord->dx1f(is)) {
      for (int k = pmb->ks; k <= pmb->ke; ++k)
        for (int j = pmb->js; j <= pmb->je; ++j) {
            
	    rhoNa=pmb->phydro->u(INA, k, j, is);
	    rhoSiO=pmb->phydro->u(ISIO, k, j, is);
	    Tmix=pthermo->GetTemp(pmb, k, j, is);

	    // add Na
	    pNa = rhoNa*Rd/pthermo->GetMuRatio(iNa)*Tmix;
	    drhoNa = (
            dt * (Ps1 - pNa) / sqrt(2 * M_PI * Rd * Ts / pthermo->GetMuRatio(iNa))
            ) / pmb->pcoord->dx1f(is);
        u(iNa, k, j, is) += drhoNa;
        u(IEN, k, j, is) += drhoNa * (Rd / (gammad - 1.)) * pthermo->GetCvRatioMass(iNa) * Ts;
	    
	    // add SiO
	    pSiO = rhoSiO*Rd/pthermo->GetMuRatio(iSiO)*Tmix;
	    drhoSiO = (
            dt * (Ps1 - pSiO) / sqrt(2 * M_PI * Rd * Ts / pthermo->GetMuRatio(iSiO))
            ) / pmb->pcoord->dx1f(is);
        u(iSiO, k, j, is) += drhoSiO;
        u(IEN, k, j, is) += drhoSiO * (Rd / (gammad - 1.)) * pthermo->GetCvRatioMass(iSiO) * Ts;
	    

	    // add dry air
	    drhodry=drhoNa*massflux_dryratio;
	    u(IDN, k, j, is) += drhodry;
	    u(IEN, k, j, is) += drhodry * (Rd / (gammad - 1.)) * Ts;
        }
  }

}

void Forcing(MeshBlock *pmb, Real const time, Real const dt,
                        AthenaArray<Real> const &w, AthenaArray<Real> const &r,
                        AthenaArray<Real> const &bcc, AthenaArray<Real> &u,
                        AthenaArray<Real> &s) {
  BottomInjection(pmb, time, dt, w, r, bcc, u, s);
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

  massflux_dryratio = pin->GetReal("thermodynamics", "massflux_dryratio");
  Achem1 = pin->GetReal("thermodynamics", "Achem1");
  Achem2 = pin->GetReal("thermodynamics", "Achem2");
  Bchem1 = pin->GetReal("thermodynamics", "Bchem1");
  Bchem2 = pin->GetReal("thermodynamics", "Bchem2");
  Ts = pin->GetReal("problem", "Ts");
  Ps1 = Achem1*exp(-Bchem1/Ts);
  Ps2 = Achem2*exp(-Bchem2/Ts);

  // index
  iNa = pindex->GetVaporId("Na");
  iNac = pindex->GetCloudId("Na(c)");
  iSiO = pindex->GetVaporId("SiO");
  iSiOc = pindex->GetCloudId("SiO(c)");

  EnrollUserExplicitSourceFunction(Forcing);
}

void MeshBlock::ProblemGenerator(ParameterInput *pin) {

    auto pthermo = Thermodynamics::GetInstance();
    Real rho = 2.0e-5;
    Real dryratio,Naratio, SiOratio;

    Naratio=0.8f;
    SiOratio=0.15f;
    dryratio=1.0f-Naratio-SiOratio;

    for (int k = ks; k <= ke; ++k) {
        for (int j = js; j <= je; ++j) {
            for (int i = is; i <= ie; ++i) {
                this->phydro->w(IDN, k, j, i) = rho;
                this->phydro->w(iNa, k, j, i) = Naratio;
                this->phydro->w(iSiO, k, j, i) = SiOratio;
                for (int n = IVX; n < IPR; ++n) {
                    this->phydro->w(n, k, j, i) = 0.f;
                }
                this->phydro->w(IPR, k, j, i) = Ts * dryratio * rho * Rd;
                this->phydro->w(IPR, k, j, i) += Ts * Naratio * rho * Rd / pthermo->GetMuRatio(iNa);
                this->phydro->w(IPR, k, j, i) += Ts * SiOratio * rho * Rd / pthermo->GetMuRatio(iSiO);
                //std::cout << "IDN"<<IDN<<" iNa"<<iNa<<" iSiO"<<iSiO<<" iNac"<<iNac<<" iSiOc"<< iSiOc<< std::endl;
            }
        }
    }
    peos->PrimitiveToConserved(phydro->w, pfield->bcc, phydro->u, pcoord, is, ie,
                             js, je, ks, ke);
}
