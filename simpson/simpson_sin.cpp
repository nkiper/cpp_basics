// simpson_sin.cpp
// calculate integral of sin(x) for x in [0, pi] using Simpson numerical integration

#include <cmath>
#include <iostream>

double func_sin(double x);
double func_poly(double x);
double simpson(double (*integrand)(double), double start, double end, unsigned N);

int main() {
    unsigned N = 100; // number of intervals for integration
    double start = 0; // integration lower bound
    double end = 1; // integration upper bound (polynomial)
    std::cout << "Integrating polynomial: " << simpson(func_poly, start, end, N) << std::endl;
    end = M_PI; // integration upper bound (sine)
    std::cout << "Integrating sine: " << simpson(func_sin, start, end, N) << std::endl;
    return 0;
}

double func_poly(double x) {
    return x*(1-x);
}

double func_sin(double x) {
    return sin(x);
}

double simpson(double (*integrand)(double), double start, double end, unsigned N){
    double summand = 0;
    double dx = (end-start)/N;
    for (int i = 0; i < N; ++i) {
        // apply Simpson rule to each interval
        summand += integrand(start+i*dx) + 4*integrand(start+(i+0.5)*dx) + integrand(start+(i+1)*dx);
    }
    summand *= dx/6;
    return summand;
}