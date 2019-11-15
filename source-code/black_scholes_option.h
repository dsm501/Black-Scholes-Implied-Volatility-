//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  black_scholes_option.h 1423101
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#ifndef PROJECT_2_BLACK_SCHOLES_H
#define PROJECT_2_BLACK_SCHOLES_H

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  BlackScholesOption class
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

class BlackScholesOption {
private:
    double S; // Asset price
    double K; // Strike price
    double r; // Risk-free rate
    double T; // Maturity Time

public:
    BlackScholesOption(double _S, double _K, double _r, double _T); // Constructor

    double call_option_price(double sigma) const; // Method to return the call option price
    double put_option_price(double sigma) const; // Method to return the put option price
    double option_vega(double sigma) const; // Method to return the vega of the option

    // Selector
    double strike_price() const; // Method to return the strike price of the option
};

#endif //PROJECT_2_BLACK_SCHOLES_H

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  end of file
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX