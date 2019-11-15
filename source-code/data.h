//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  data.h 1423101
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#ifndef PROJECT_2_DATA_H
#define PROJECT_2_DATA_H

#include<istream>
#include "black_scholes_option.h"

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  data struct used to hold the input data
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

struct data
{
    double S; // Spot price
    double K; // Strike price
    double r; // Risk-free rate
    double T; // Maturity
    double F; // Option price
    int i;    // The root finding method 1 = Newton, 2 = Secant
    std::string option_type; // Option type, can be either "call" or "put"

    friend std::istream &operator >> (std::istream &is, data &s); // overload >> operator for input stream
};

#endif //PROJECT_2_DATA_H

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  end of file
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
