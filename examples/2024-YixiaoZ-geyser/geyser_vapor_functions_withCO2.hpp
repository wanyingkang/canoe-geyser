// application
#include <application/application.hpp>

// canoe
#include <index_map.hpp>

// snap
#include <snap/thermodynamics/thermodynamics.hpp>

double sat_vapor_p_H2O(double T) {
  double betal = 22.46, gammal =0, tr = 273.16, pr = 611.7;
  return SatVaporPresIdeal(T / tr, pr, betal, gammal);
}

double sat_vapor_p_CO2(double T) {
  double betal = 14.99, gammal =0, tr = 216.59, pr = 517950;
  return SatVaporPresIdeal(T / tr, pr, betal, gammal);
}

// water svp
void enroll_vapor_Function_H2O(Thermodynamics::SVPFunc1Container &svp_func1) {
  Application::Logger app("snap");
  app->Log("Enrolling H2O vapor pressures");

  auto pindex = IndexMap::GetInstance();
  int iH2O = pindex->GetVaporId("H2O");

  svp_func1[iH2O][0] = [](AirParcel const &qfrac, int, int) {
    return sat_vapor_p_H2O(qfrac.w[IDN]);
  };
}

// co2 svp
// 1: CO2(g) -> CO2(s)
// 2: A + B -> C
void enroll_vapor_Function_CO2(Thermodynamics::SVPFunc1Container &svp_func1) {
  Application::Logger app("snap");
  app->Log("Enrolling CO2 vapor pressures");

  auto pindex = IndexMap::GetInstance();
  int iCO2 = pindex->GetVaporId("CO2");

  svp_func1[iCO2][0] = [](AirParcel const &qfrac, int, int) {
    return sat_vapor_p_CO2(qfrac.w[IDN]);
  };
}

void Thermodynamics::enrollVaporFunctions() {
  enroll_vapor_Function_H2O(svp_func1_);
  enroll_vapor_Function_CO2(svp_func1_);
}
