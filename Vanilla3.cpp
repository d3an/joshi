#include "Vanilla3.h"

VanillaOption::VanillaOption(PayOff& ThePayOff_, double Expiry_) : 
    ThePayOffPtr{ThePayOff_}, Expiry{Expiry_} {}

double VanillaOption::GetExpiry() const {
    return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const {
    return ThePayOff(Spot);
}

