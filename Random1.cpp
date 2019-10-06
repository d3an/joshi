#include "Random1.h"
#include <cstdlib>
#include <cmath>

// the basic math functions should be in namespace
// std but aren’t in VCPP6
#if !defined(_MSC_VER)
using namespace std;
#endif

double getOneGaussianBySummation() {
    double result = 0;

    for (unsigned long i = 0; i < 12; i++) {
        result += rand() / static_cast<double>(RAND_MAX);
    }

    result -= 6.0;
    return result;
}

double getOneGaussianByBoxMuller() {
    double result;
    double x;
    double y;
    double sizeSquared;

    do {
        x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1.0;
        y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1.0;
        sizeSquared = x*x + y*y;
    } while (sizeSquared >= 1.0);

    result = x * sqrt(-2 * log(sizeSquared) / sizeSquared);
    return result;
}

