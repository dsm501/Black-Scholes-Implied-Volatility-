//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  newton_raphson.h 1423101
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#ifndef PROJECT_2_NEWTON_RAPHSON_H
#define PROJECT_2_NEWTON_RAPHSON_H
#include<cmath>
#include <iostream>
#include <functional>

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  template function
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

template<typename T,
        double (T::*f)(double) const,
        double (T::*f_prime)(double) const> // Object of type T, 2 pointers to member functions f and f_prime

double newton_raphson(double target,    // Target option price value
                      double init1,     // Initial x value
                      double init2,     // Second Initial Value
                      double tol,       // Tolerance
                      const T& func,    // Functor
                      double method) {  // Function object

    // Set the initial option prices and volatility
    double y = (func.*f)(init1);  // Initial option price
    double x = init1; // Initial volatility - first guess
    double x2 = init2; // Second guess

    // If method == 1 do the Newton-Raphson method
    // While y and target are > tol get the vega of the option and calculate a new option price
    // based on the best approximation at that implied volatility value
    if(method == 1)
    {
        while (std::fabs(y - target) > tol) {
            double dx = (func.*f_prime)(x);
            x += (target - y) / dx;
            y = (func.*f)(x);
        }
        return x;
    }

    // If method == 2 do the Secant method
    else if(method == 2)
    {
        y = (func.*f)(init2);
        while (std::fabs(y - target) > tol) {
            double dx = ( (func.*f)(x) - (func.*f)(x2) ) / (x - x2); // approximating f' (derivative of f)
            //x2 = x;
            double x_temp = x2 + (target - y) / dx; // Calculate current vol
            x = x2; // Update first guess
            x2 = x_temp; // Update second guess
            y = (func.*f)(x2); // Calculate the current option value under the current vol value
        }
        //return x;
        return x2;
    }
    else
        // Throw a runtime error if neither 1 or 2 is input for the method choice
        throw std::runtime_error("Method must be 1 or 2 for Newton-Raphson and Secant method respectively");
}

#endif //PROJECT_2_NEWTON_RAPHSON_H

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  end of file
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX