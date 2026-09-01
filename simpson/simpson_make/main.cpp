// main.cpp
// calculate integral of sin(x) using Simpson numerical integration

#include <cmath>
#include <iostream>
#include "lib/simpson.hpp"

int main() {
    unsigned N = 1; // starting number of intervals for integration
    double start = 0; // integration lower bound
    double end = M_PI; // integration upper bound (polynomial)
    while (N <= 20) {
        std::cout << N << " " << simpson(sin, start, end, N) << std::endl;
        N += 1; // double the number of intervals for next iteration
    }
    return 0;
}

