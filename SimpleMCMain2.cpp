/*
  requires
  PayOff1.cpp,
  Random1.cpp,
  SimpleMC.cpp
*/

#include "SimpleMC.h"
#include <iostream>
using namespace std;

double convert_days_to_years(double days) {
    return days / 365.0;
}

extern "C"
double calculateCallPayoff(double Expiry, double Strike, double Spot, double Vol, double r, unsigned long NumberOfPaths) {
    PayOff callPayOff(Strike, PayOff::call);
    Expiry = convert_days_to_years(Expiry);
    double resultCall = SimpleMonteCarlo2(callPayOff, Expiry, Spot, Vol, r, NumberOfPaths);
    return resultCall;
}

extern "C"
double calculatePutPayoff(double Expiry, double Strike, double Spot, double Vol, double r, unsigned long NumberOfPaths) {
    PayOff putPayoff(Strike, PayOff::put);
    Expiry = convert_days_to_years(Expiry);
    double resultPut = SimpleMonteCarlo2(putPayoff, Expiry, Spot, Vol, r, NumberOfPaths);
    return resultPut;
}

int main() {
  double Expiry;
  double Strike;
  double Spot;
  double Vol;
  double r;
  unsigned long NumberOfPaths;

  cout << "\nEnter expiry\n";
  cin >> Expiry;
  Expiry = convert_days_to_years(Expiry);

  cout << "\nEnter strike\n";
  cin >> Strike;

  cout << "\nEnter spot\n";
  cin >> Spot;

  cout << "\nEnter vol\n";
  cin >> Vol;

  cout << "\nr\n";
  cin >> r;

  cout << "\nNumber of paths\n";
  cin >> NumberOfPaths;

  PayOff callPayOff(Strike, PayOff::call);
  PayOff putPayOff(Strike, PayOff::put);

  double resultCall = SimpleMonteCarlo2(callPayOff, Expiry, Spot, Vol, r, NumberOfPaths);
  double resultPut = SimpleMonteCarlo2(putPayOff, Expiry, Spot, Vol, r, NumberOfPaths);

  cout << "The prices are " << resultCall << " for the call and " << resultPut << "for the put" << endl;

  return 0;
}
