// simpson_func_obj.cpp
// implement simpson integration using function object

#include <cmath>
#include <iostream>
#include <iomanip>

// Function object
class expfunc {
    public:
        expfunc(double l = 1.): lambda_(l) {};
        double operator() (double x) const {
            return std::exp(-lambda_*x);
        }
    private:
        const double lambda_;
};



template <typename F, typename T>
double simpson(const T start, const T end, const unsigned N, const F& integrand){
    T summand = integrand(start) - integrand(end);
    const T dx = (end-start)/N;
    for (int i = 0; i < N; ++i) {
        // apply Simpson rule to each interval
        summand += 4*integrand(start+(i+0.5)*dx) + 2*integrand(start+(i+1)*dx);
    }
    summand *= dx/6;
    return summand;
}

int main() {
    unsigned N = 128; // number of intervals for integration
    double start = 0; // integration lower bound
    double end = 1; // integration upper bound
    const double l = 2.; // decay rate
    
    expfunc func_obj(l);

    // lambda expression

    auto f = [l] (double x) { return std::exp(-l*x); };
    
    std::cout << std::fixed << std::setprecision(15);
    int width_l = 50;
    int width_r = 20;
    std::cout << std::left << std::setw(width_l) << "Integrating exp(-lambda*x), function object: " 
              << std::right << std::setw(width_r) << simpson(start, end, N, func_obj) << std::endl;
    std::cout << std::left << std::setw(width_l) << "Integrating exp(-lambda*x), lambda expression: " 
              << std::right << std::setw(width_r) << simpson(start, end, N, f) << std::endl;
    std::cout << std::left << std::setw(width_l) << "Analytic result: " 
              << std::right << std::setw(width_r) << (func_obj(start)-func_obj(end))/l << std::endl;

    return 0;
}