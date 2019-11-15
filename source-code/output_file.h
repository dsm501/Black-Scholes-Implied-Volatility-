//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  output_file.h 1423101
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#ifndef PROJECT_2_OUTPUT_FILE_H
#define PROJECT_2_OUTPUT_FILE_H

#include<fstream>
#include "black_scholes_option.h"

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  output_file struct to hold the data that will be sent to output.txt
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

struct output_file
{
    BlackScholesOption bso; // BlackScholesOption object

    double ivol_cn; // Implied volatility of call under newton method
    double ivol_cs; // Implied volatility of call under secant method
    double ivol_pn; // Implied volatility of put under newton method
    double ivol_ps; // Implied volatility of put under secant method

    friend std::ofstream &operator << (std::ofstream & os, output_file & o); // overload operator <<
};

#endif //PROJECT_2_OUTPUT_FILE_H

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  end of file
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
