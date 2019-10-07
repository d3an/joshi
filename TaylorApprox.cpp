#include "TaylorApprox.h"

double fact(int c) {
  int factorial = 1;

  for (int i = 1; i <= c; i++) {
    factorial *= i;
  }

  return factorial;
}


double taylor(double num, int term_count) {
  double approx = 0;
  double sum = 0;
  double value = 0;

  for (int i = 1; i <= term_count; i++) {
    sum = (pow(num, i) / fact(i));
    value += sum;
  }

  approx = 1 + value;
  return approx;
}
