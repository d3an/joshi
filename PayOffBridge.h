#ifndef PAYOFFBRIDGE_H_
#define PAYOFFBRIDGE_H_
#include "PayOff3.h"

class PayOffBridge {
  PayOff* ThePayOffPtr;

 public:
  PayOffBridge(const PayOffBridge & original);
  PayOffBridge(const PayOff & innerPayOff);

  inline double operator()(double Spot) const;
  ~PayOffBridge();
  PayOffBridge & operator=(const PayOffBridge & original);
};

#endif
