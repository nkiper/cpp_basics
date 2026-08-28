// Calculate the greatest common divisor (gcd) of two numbers using Euclid's algorithm and a loop

#include <iostream>

int gcd(int a, int b){
    while (a != b){
        if (a>b) {
            a = a-b;
        }
        else {
            b = b-a;
        }
    }
    return a;
}

int main(){
    int a;
    int b;
    std::cout << "Enter two positive integers a and b to compute their greatest commoon divisor (gcd) \n";
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;
    if ((a < 1)||(b < 1)){
        std::cout << "error: a and b must be positive integers. \n";
        return 0;
    }
    else {
        std::cout << "gcd(a,b) = " << gcd(a,b) << "\n";
         return 0;
    }
}