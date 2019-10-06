#include "PayOff1.h"
#include "MinMax.h"

PayOff::PayOff(double Strike_, OptionType TheOptionsType_) :
  Strike(Strike_), TheOptionsType(TheOptionsType_) {}

double PayOff::operator()(double Spot) const {
  switch(TheOptionsType) {
  case call:
    return max(Spot - Strike, 0.0);
  case put:
    return max(Strike - Spot, 0.0);
  default:
    throw ("Unknown option type found.");
  }
}
