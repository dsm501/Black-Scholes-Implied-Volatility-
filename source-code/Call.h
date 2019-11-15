//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  Call.h 1423101
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#ifndef PROJECT_2_CALL_PRICE_H
#define PROJECT_2_CALL_PRICE_H

#include "option_price.h"

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  Call class derives from base class option_price
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

class Call: public option_price {

private:
    double S;     // Asset price
    double K;     // Strike price
    double r;     // Risk-free rate
    double sigma; // Volatility
    double T;     // Maturity

public:
    Call(double _S, double _K, double _r, double _sigma, double _T); // Constructor
    Call(const Call & source); // Copy Constructor
    virtual ~Call() = default; // Destructor
    Call & operator = (const Call & source); // Assignment operator

    //Implement the call option price functions
    double OptionPrice(double S, double K, double r, double sigma, double T) const; // Call option price
    double d_j(int j, double S, double K, double r, double sigma, double T) const; // d_j for calls
    double vega(double S, double K, double r, double sigma, double T) const; // option vega
};

#endif //PROJECT_2_CALL_PRICE_H

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  end of file
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
