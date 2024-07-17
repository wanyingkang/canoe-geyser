// application
#include <application/application.hpp>

// canoe
#include <index_map.hpp>

// snap
#include <snap/thermodynamics/thermodynamics.hpp>

double sat_vapor_p_Na(double T) {
  double betal = 6.04, gammal =0, tr = 2000., pr = 22.3;
  return SatVaporPresIdeal(T / tr, pr, betal, gammal);
}

double sat_vapor_p_SiO(double T) {
  double betal = 24.76, gammal =0, tr = 2000., pr = 0.066;
  return SatVaporPresIdeal(T / tr, pr, betal, gammal);
}

// water svp
void enroll_vapor_Function_Na(Thermodynamics::SVPFunc1Container &svp_func1) {
  Application::Logger app("snap");
  app->Log("Enrolling Na vapor pressures");

  auto pindex = IndexMap::GetInstance();
  int iNa = pindex->GetVaporId("Na");

  svp_func1[iNa][0] = [](AirParcel const &qfrac, int, int) {
    return sat_vapor_p_Na(qfrac.w[IDN]);
  };
}

// co2 svp
// 1: SiO(g) -> SiO(s)
// 2: A + B -> C
void enroll_vapor_Function_SiO(Thermodynamics::SVPFunc1Container &svp_func1) {
  Application::Logger app("snap");
  app->Log("Enrolling SiO vapor pressures");

  auto pindex = IndexMap::GetInstance();
  int iSiO = pindex->GetVaporId("SiO");

  svp_func1[iSiO][0] = [](AirParcel const &qfrac, int, int) {
    return sat_vapor_p_SiO(qfrac.w[IDN]);
  };
}

void Thermodynamics::enrollVaporFunctions() {
  enroll_vapor_Function_Na(svp_func1_);
  enroll_vapor_Function_SiO(svp_func1_);
}
