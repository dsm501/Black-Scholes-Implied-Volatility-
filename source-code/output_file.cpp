//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  output_file.cpp 1423101
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "output_file.h"
#include <fstream>

// Overloading the operator <<
std::ofstream & operator<<(std::ofstream & os, output_file & o)
{
    os.open("output.txt"); // Open output file stream

    os << "Strike " << o.bso.strike_price() << ", " << o.ivol_cn << ", " << o.ivol_cs << "\n"; // First line of output
    os << "Strike " << o.bso.strike_price() << ", " << o.ivol_pn << ", " << o.ivol_ps << "\n"; // Second like of output

    os.close(); // Close the output file stream

    return os; // Return the output file stream
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  end of file
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
