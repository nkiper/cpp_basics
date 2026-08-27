// machineepsilon.cpp
// This program calculates the machine epsilon for double precision floating point numbers.
#include <iostream>

int main() {
    double epsilon = 1.0;

    // Keep halving epsilon until 1.0 + epsilon is equal to 1.0
    while ((1.0 + (epsilon / 2.0)) != 1.0) {
        epsilon /= 2.0;
    }

    // Output the machine epsilon
    std::cout << "Machine epsilon for double precision: " << epsilon << std::endl;

    return 0;
}