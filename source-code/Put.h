//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  Put.h 1423101
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#ifndef PROJECT_2_PUT_H
#define PROJECT_2_PUT_H

#include "option_price.h"

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  Put class derives from base class option_price
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

class Put : public option_price{

private:
    double S;       // Asset price
    double K;       // Strike price
    double r;       // Risk-free rate
    double sigma;   // Volatility
    double T;       // Expiry time

public:
    Put(double _S, double _K, double _r, double _sigma, double _T); // Constructor
    Put(const Put & source); // Copy Constructor
    virtual ~Put() = default; // Destructor
    Put & operator =  (const Put & source); // Assignment operator

    // Implement the Put option price functions
    double OptionPrice(double S, double K, double r, double sigma, double T) const; // Return the price of the option
    double d_j(int j, double S, double K, double r, double sigma, double T) const;  // return d_j for puts
    double vega(double S, double K, double r, double sigma, double T) const;        // return the vega for put options
};

#endif //PROJECT_2_PUT_H

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  end of file
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX