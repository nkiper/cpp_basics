#ifndef SIMPSON_HPP
#define SIMPSON_HPP

/* 
   simpson.hpp
   
   This function implements numerical integration using Simpson's rule.
   The function takes a pointer to the integrand function, the start and end points of integration,
   and the number of intervals (N) to use for the approximation.
  
   PRECONDITIONS:
   - The integrand function must be continuous on the interval [min(start,end), max(start,end)].
   - 'N' must be a convertible to unsigned, N > 0.
   - 'start' and 'end' must be convertible to double.
  
   POSTCONDITIONS:
   - Returns the approximate value of the integral of the integrand function over the interval [start,
     end] using Simpson's rule.

   COMPLEXITY:
   number of function calls: 2*N+1.
*/

double simpson(double (*integrand)(double), double start, double end, unsigned N);

#endif // SIMPSON_HPP