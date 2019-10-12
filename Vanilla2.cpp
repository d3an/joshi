#include "Vanilla2.h"

VanillaOption::VanillaOption(PayOff& ThePayOff_, double Expiry_) : 
    Expiry(Expiry_) ThePayOffPtr{ThePayOff_.clone()} {}

VanillaOption::VanillaOption(const VanillaOption & original) : 
    Expiry{original.Expiry}, ThePayOffPtr{original.ThePayOffPtr->clone()} {}

VanillaOption & operator=(const VanillaOption& original) {
    if (*this == original) return *this;
    Expiry = original.Expiry;
    delete ThePayOffPtr;
    ThePayOffPtr = original.ThePayOffPtr;
    return *this;
}

VanillaOption::~VanillaOption() {
    delete ThePayOffPtr;
}

double VanillaOption::GetExpiry() const {
    return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const {
    return (*thePayOff)(Spot);
}

