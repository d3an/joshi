#ifndef VANILLA_1_H_
#define VANILLA_1_H_

class VanillaOption {
    double Expiry;
    PayOff& ThePayOff;

    public:
        VanillaOption(PayOff& ThePayOff_, double Expiry_);
        double GetExpiry() const;
        double OptionPayOff(double Spot) const;
};

#endif

