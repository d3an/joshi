/*
  requires
  DoubleDigital.cpp
  PayOff2.cpp,
  Random1.cpp,
  SimpleMC3.cpp
  Vanilla1.cpp
*/

#include "SimpleMC3.h"
#include "DoubleDigital.h"
#include "Vanilla1.h"
#include <iostream>
using namespace std;

int main() {
  double Expiry;
  double Low, Up;
  double Spot;
  double Vol;
  double r;
  unsigned long NumberOfPaths;

  cout << "\nEnter expiry\n";
  cin >> Expiry;

  cout << "\nEnter low barrier\n";
  cin >> Low;

  cout << "\nEnter up barrier\n";
  cin >> Up;

  cout << "\nEnter spot\n";
  cin >> Spot;

  cout << "\nEnter vol\n";
  cin >> Vol;

  cout << "\nr\n";
  cin >> r;

  cout << "\nNumber of paths\n";
  cin >> NumberOfPaths;

  PayOffDoubleDigital thePayOff(Low, Up);

  VanillaOption theOption(thePayOff, Expiry);

  double result = SimpleMonteCarlo3(theOption, Spot, Vol, r, NumberOfPaths);
  
  cout << "The prices is " << result << endl;

  return 0;
}

