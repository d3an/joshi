#include "PayOffBridge.h"

inline double PayOffBridge::operator() (double Spot) const {
    return ThePayOffPtr->operator()(Spot);
}

PayOffBridge::PayOffBridge(const PayOffBridge & original) : ThePayOffPtr{original.ThePayOffPtr->clone()} {}

PayOffBridge::PayOffBridge(const PayOff & innerPayOff) : ThePayOffPtr{innerPayOff.clone()} {}

PayOffBridge::~PayOffBridge() {
    delete ThePayOffPtr;
}

PayOffBridge & PayOffBridge::operator=(const PayOffBridge & original) {
    if (this == &original) return *this;
    delete ThePayOffPtr;
    ThePayOffPtr = original.ThePayOffPtr->clone();
    return *this;
}
