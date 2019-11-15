//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  Call.cpp 1423101
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "Call.h"
#include "normal.h"
#include<cmath>

// Constructor
Call::Call(double _S, double _K, double _r, double _sigma, double _T)  : S(_S), K(_K), r(_r), sigma(_sigma), T(_T) {}

// Copy Constructor
Call::Call(const Call & source) : option_price(source)
{
    S = source.S;
    K = source.K;
    r = source.r;
    sigma = source.sigma;
    T = source.T;
}

// Assignment operator
Call & Call :: operator = (const Call & source)
{
    if(this == &source) return *this; // Exit if same object

    Call::operator = (source); // Call base class assignment

    // Copy state
    S = source.S;
    K = source.K;
    r = source.r;
    sigma = source.sigma;
    T = source.T;

    return *this;
}

// Method returns d_j for calls
double Call::d_j(const int j, const double S, const double K, const double r, const double sigma,
                 const double T) const {
    return (log(S/K) + (r + (pow(-1,j-1))*0.5*sigma*sigma)*T)/(sigma*(pow(T,0.5)));
}

// Method returns the option price for a call
double Call::OptionPrice(const double S, const double K, const double r, const double sigma, const double T) const
{
    return S * cdf_normal(d_j(1, S, K, r, sigma, T))-K*std::exp(-r*T) * cdf_normal(d_j(2, S, K, r, sigma, T));
}

// Method returns the vega of a call option
double Call::vega(const double S, const double K, const  double r, const double sigma, const double T) const
{
    return S * sqrt(T) * pdf_normal(d_j(1, S, K, r, sigma, T));
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  end of file
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX


