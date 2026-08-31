// fibonacci.cpp
// Read in non-negative n and print n-th number in Fibonacci sequence using recursive function call and loop

#include <iostream>

//declare type alias
using fib_t = unsigned long long int; //will cause overflow for n > 93.

fib_t fibonacci_recursive(fib_t n);
fib_t fibonacci_loop(fib_t n);

int main(){
    int n;
    std::cout << "Enter a non-negative integer n to compute the n-th number in the Fibonacci sequence F(n) \n";
    std::cout << "n: ";
    std::cin >> n;
    std::cout << "recursive implementation: F(n) = " << fibonacci_recursive(n) << "\n"
              << "loop implementation: F(n) = " << fibonacci_loop(n) << "\n";
    return 0;
}

fib_t fibonacci_recursive(fib_t n){
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

fib_t fibonacci_loop(fib_t n){
    if (n == 0) return 0;
    fib_t previous = 0;
    fib_t current = 1;
    for (fib_t i = 1; i < n; ++i){
        fib_t next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}
