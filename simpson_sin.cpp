// simpson_sin.cpp
// calculate integral of sin(x) for x in [0, pi] using Simpson numerical integration

#include <cmath>
#include <iostream>

double func(double x) {
    return sin(x);
}

int main() {
    int N = 100; // number of intervals for integration
    double summand = 0; 
    double start = 0; // integration lower bound
    double end = M_PI; // integration upper bound
    double dx = (end-start)/N; // interval
    for (int i = 0; i < N; ++i) {
        // apply Simpson rule to each interval
        summand += func(start+i*dx) + 4*func(start+(i+0.5)*dx) + func(start+(i+1)*dx);
    }
    summand *= dx/6;
    std::cout << summand;
    return 0;
}