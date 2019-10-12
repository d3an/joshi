#include "Parameters.h"

// Parameter Class Method Implementations

Parameters::Parameters(const Parameters& innerObject) : InnerObjectPtr{innerObject.clone()} {}
Parameters::Parameters(const Parameters& original) : InnerObjectPtr{original.InnerObjectPtr->clone()} {}

Parameter & Parameters::operator=(const Parameters & original) {
    if (this == &original) return *this;
    delete InnerObjectPtr;
    InnerObjectPtr = original.InnerObjectPtr->clone();
    return *this;
}

inline double Parameters::Integral(double time1, double time2) const {
    return InnerObjectPtr->Integral(time1, time2);
}

inline double Parameters::IntegralSquare(double time1, double time2) const {
    return InnerObjectPtr->IntegralSquare(time1, time2);
}

Parameters::~Parameters() {
    delete InnerObjectPtr;
}

double Parameters::Mean(double time1, double time2) const {
    double total = Integral(time1, time2);
    return total / (time2 - time1);
}

double Parameters::RootMeanSquare(double time1, double time2) const {
    double total = IntegralSquare(time1, time2);
    return total / (time2 - time1);
}

// ParametersConstant Class Method Implementations

ParametersInner* ParametersConstant::clone() const {
    return new ParametersConstant(*this);
}

ParametersConstant::ParametersConstant(double constant) : Constant{constant}, ConstantSquare{Constant * Constant} {}

double ParametersConstant::Integral(double time1, double time2) const {
    return (time2 - time1) * Constant;
}

double ParametersConstant::IntegralSquare(double time1, double time2) const {
    return (time2 - time1) * ConstantSquare;
}
