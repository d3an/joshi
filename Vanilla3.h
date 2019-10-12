#ifndef VANILLA_3_H_
#define VANILLA_3_H_
#include "PayOffBridge.h"

class VanillaOption {
    double Expiry;
    PayOffBridge ThePayOff;

    public:
    VanillaOption(const PayOffBridge & thePayOff_, double Expiry_);
    double OptionPayOff(double Spot) const;
    double GetExpiry() const;
}

#endif

