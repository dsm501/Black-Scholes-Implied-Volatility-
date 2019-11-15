//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  black_scholes_option.cpp 1423101
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "black_scholes_option.h"
#include "option_price.h"
#include "Call.h"
#include "Put.h"

// Constructor
BlackScholesOption::BlackScholesOption(double _S, double _K, double _r, double _T) : S(_S), K(_K), r(_r), T(_T) {}

// Method creates a call object and returns the call price
double BlackScholesOption::call_option_price(double sigma) const {
    Call call(S, K, r, sigma, T);
    return call.OptionPrice(S, K, r, sigma, T);
}

// Method creates a put object and returns the put price
double BlackScholesOption::put_option_price(double sigma) const {
    Put put(S, K ,r, sigma, T);
    return put.OptionPrice(S, K, r, sigma, T);
}

// Method calls vega, note vega is the same for puts and calls
double BlackScholesOption::option_vega(double sigma) const {
    Call call(S, K, r, sigma, T);
    return  call.vega(S, K, r, sigma, T);
}

// Method returns the strike price of the option
double BlackScholesOption::strike_price() const
{
    return K;
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  end of file
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
