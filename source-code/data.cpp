//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  data.cpp 1423101
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX


#include "data.h"
#include<istream>
#include<string>
#include<iostream>

// Overload the extraction operator >> for input stream
std::istream & operator>>(std::istream &is, data &s)
{
    if(!is)
    {
        std::cerr << "You have not provided at input file!" << std::endl;
    }

    is >> s.option_type; // Read in the option type (call or put)
    is >> s.S;           // Read in the spot price
    is >> s.K;           // Read in the strike price
    is >> s.r;           // Read in the risk-free rate
    is >> s.T;           // Read in the expiry time (in years)
    is >> s.F;           // Read in the price of the option
    is >> s.i;           // Read in the root finding method (1 or 2)

    // If the option type is not either call or put then throw a invalid argument error
    if (s.option_type != "put" && s.option_type != "call")
    {
        throw std::invalid_argument("The option type must be specified as \"call\" or \"put\"");
    }

    return is;
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  end of file
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX


