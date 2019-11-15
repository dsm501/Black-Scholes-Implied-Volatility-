//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  normal.cpp 1423101
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "normal.h"
#define _USE_MATH_DEFINES
#include <cmath>

// Method returns the normal cdf for a double z
double cdf_normal(double z)
{
    static double b1 =  0.31938153;
    static double b2 = -0.356563782;
    static double b3 =  1.781477937;
    static double b4 = -1.821255978;
    static double b5 =  1.330274429;
    static double p  =  0.2316419;
    static double c2 =  0.3989423;

    if (z >  6.0) { return 1.0; };  // This guards against overflow
    if (z < -6.0) { return 0.0; };  // This is a very narrow range

    double a = std::fabs(z);
    double t = 1.0/(1.0+a*p);
    double b = c2*std::exp((-z)*(z/2.0));
    double n = ((((b5*t+b4)*t+b3)*t+b2)*t+b1)*t;

    n = 1.0 - b*n;
    if ( z < 0.0 ) n = 1.0 - n;

    return n;
}

// Method returns the normal pdf for a double z
double pdf_normal(const double x) {
    return (1.0/(std::sqrt(2*M_PI)))*exp(-0.5*x*x);
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  end of file
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
