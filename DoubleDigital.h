#ifndef DOUBLE_DIGITAL_H_
#define DOUBLE_DIGITAL_H_
#include "PayOff2.h"

class PayOffDoubleDigital : public PayOff {
    private:
        double LowerLevel;
        double UpperLevel;

    public:
        PayOffDoubleDigital(double LowerLevel_, double UpperLevel_);
        virtual double operator() (double Spot) const;
        virtual ~PayOffDoubleDigital() {}
};

#endif
