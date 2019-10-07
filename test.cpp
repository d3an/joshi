#include "TaylorApprox.h"
#include <iostream>
#include <ctime>

int main() {
    double num, number_of_paths;
    std::cin >> num >> number_of_paths;

    time_t tt;
    struct tm * ti;
    time (&tt);
    ti = localtime(&tt);
    std::cout << asctime(ti) << std::endl;
    
    std::cout << taylor(num, number_of_paths) << std::endl;
    
    ti = localtime(&tt);
    std::cout << asctime(ti) << std::endl;
    return 0;
}
