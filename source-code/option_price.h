//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  option_price.h 1423101
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#ifndef PROJECT_2_OPTION_PRICE_H
#define PROJECT_2_OPTION_PRICE_H

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  option_price abstract base class
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

class option_price {

public:
    option_price() = default; // Default constructor
    option_price(const option_price & source) = default; // Copy constructor
    virtual ~option_price() = default; // Destructor
    option_price & operator = (const option_price& source); // Assignment operator

    // Pure virtual pricing functions
    virtual double OptionPrice(double S, double K, double r, double sigma, double T) const = 0; // Option price
    virtual double d_j(int j, double S, double K, double r, double sigma, double T) const = 0; // d_1 and d_2 for European puts and calls
    virtual double vega(double S, double K , double r, double sigma, double T) const = 0; // Option vega
};

#endif //PROJECT_2_OPTION_PRICE_H

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  enf of file
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX