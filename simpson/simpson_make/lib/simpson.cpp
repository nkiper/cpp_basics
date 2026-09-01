// simpson.cpp
// Function for simpson integration
#include "simpson.hpp"

#include <cassert>

double simpson(double (*integrand)(double), double start, double end, unsigned N){
    assert(N > 0);
    assert(integrand != nullptr);
    double a;
    double b;
    if (start > end) {
        a = end;
        b = start;
    } else {
        a = start;
        b = end;
    }
    double summand = integrand(a);
    double dx = (b - a) / N;
    for (unsigned i = 0; i < N; ++i) {
        // apply Simpson rule to each interval
        summand += 4 * integrand(a + (i + 0.5) * dx) + 2 * integrand(a + (i + 1) * dx);
    }
    summand *= dx/6;
    return summand;
}