#ifndef SIMPLEMC_H_
#define SIMPLEMC_H_
#include "PayOff2.h"

double SimpleMonteCarlo2(const PayOff& thePayOff,
			 double Expiry,
			 double Spot,
			 double Vol,
			 double r,
			 unsigned long NumberOfPaths);

#endif

