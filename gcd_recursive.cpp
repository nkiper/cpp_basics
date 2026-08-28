// Calculate the greatest common divisor (gcd) of two numbers using Euclid's algorithm and a recursive function call

#include <iostream>

int gcd(int a, int b){
    if (a == b){
        return a;
    }
    else if (a > b) {
        return gcd(a-b, b);
    }
    else {
        return gcd(a, b-a);
    }
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
    return 0;
}