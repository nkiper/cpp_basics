// machineepsilon.cpp
// This program calculates the machine epsilon for double precision floating point numbers.
#include <iostream>

template <typename T>
T MachineEpsilon() {
    const T one {1.0}; // brace init needed to convert 1.0 to float or long double
    T epsilon {1.0};

    // Keep halving epsilon until 1.0 + epsilon is equal to 1.0
    while ((one + epsilon) != one) {
        epsilon /= 2.0;
    }

    return epsilon*2.0; // return the last epsilon that was not equal to 1.0
}

int main() {
    // Output the machine epsilon
    std::cout << "Machine epsilon for float precision: " << MachineEpsilon<float>() << std::endl;
    std::cout << "Machine epsilon for double precision: " << MachineEpsilon<double>() << std::endl;
    std::cout << "Machine epsilon for long double precision: " << MachineEpsilon<long double>() << std::endl;
    return 0;
}