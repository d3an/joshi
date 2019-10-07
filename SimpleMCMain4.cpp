/*
  requires
  PayOff2.cpp,
  Random1.cpp,
  SimpleMC2.cpp
*/

#include "SimpleMC2.h"
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

  unsigned long optionType;
  cout << "\nEnter 0 for call, otherwise put ";
  cin >> optionType;

  PayOff* thePayOffPtr;

  if (optionType == 0) {
    thePayOffPtr = new PayOffCall(Strike);
  } else {
    thePayOffPtr = new PayOffPut(Strike);
  }

  double result = SimpleMonteCarlo2(*thePayOffPtr, Expiry, Spot, Vol, r, NumberOfPaths);
  
  cout << "The prices is " << result << endl;

  delete thePayOffPtr;
  return 0;
}
