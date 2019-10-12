/*
  requires 
  PayOff3.cpp,
  Random1.cpp,
  SimpleMC4.cpp
  Vanilla2.cpp
*/

#include "SimpleMC4.h"
#include "Vanilla2.h"
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

  double result = SimpleMonteCarlo3(theOption, Spot, Vol, r, NumberOfPaths);
  double result2 = SimpleMonteCarlo3(secondOption, Spot, Vol, r, NumberOfPaths);

  cout << "The prices is " << result << endl;
  cout << "The second price is " << result2 << endl;

  PayOffPut otherPayOff(Strike);
  VanillaOption thirdOption(otherPayOff, Expiry);

  double result3 = SimpleMonteCarlo3(thirdOption, Spot, Vol, r, NumberOfPaths);
  cout << "The third price is " << result3 << endl;

  return 0;
}

