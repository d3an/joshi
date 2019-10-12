#ifndef VANILLA_2_H_
#define VANILLA_2_H_
#include "PayOff3.h"

class VanillaOption {
    double Expiry;
    PayOff* ThePayOffPtr;

  public:
    VanillaOption(const PayOff& ThePayOff_, double Expiry_);
    VanillaOption(const VanillaOption& original);
    VanillaOption& operator=(const VanillaOption & original);
    ~VanillaOption();

    double GetExpiry() const;
    double OptionPayOff(double Spot) const;
};


#endif
