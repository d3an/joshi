#include "PayOff2.h"
#include "MinMax.h"

PayOffCall::PayOffCall(double Strike_) : Strike(Strike_) {}

PayOffPut::PayOffPut(double Strike_) : Strike(Strike_) {}

double PayOffCall::operator() (double Spot) const {
  return max(Spot - Strike, 0.0);
}

double PayOffPut::operator() (double Spot) const {
  return max(Strike - Spot, 0.0);
}
