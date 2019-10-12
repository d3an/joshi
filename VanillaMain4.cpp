/*
  requires 
  PayOff3.cpp,
  Random1.cpp,
  SimpleMC6.cpp
  Vanilla3.cpp
  Parameters.cpp
*/

#include "SimpleMC6.h"
#include "Vanilla3.h"
#include "Parameters.h"
#include <iostream>
using namespace std;

int main() {
  double Expiry;
  double Strike; 
  double Spot;
  double Vol;
  double r;
  unsigned long NumberOfPaths;

  cout << "\nEnter expiry\n";
  cin >> Expiry;

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

  PayOffCall thePayOff(Strike);

  VanillaOption theOption(thePayOff, Expiry);
  VanillaOption secondOption(theOption);

  ParametersConstant VolParam(Vol);
  ParametersConstant rParam(r);

  double result = SimpleMonteCarlo4(theOption, Spot, VolParam, rParam, NumberOfPaths);

  cout << "The result is " << result << endl;

  return 0;
}

