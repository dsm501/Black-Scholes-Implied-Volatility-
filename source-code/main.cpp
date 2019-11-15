//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  main.cpp 1423101
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "black_scholes_option.h"
#include "newton_raphson.h"
#include "option_price.h"
#include "data.h"
#include "output_file.h"
#include "time.h"

#include <chrono>
#include <iostream>
#include <fstream>

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  main()
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

int main(int argc, char **argv) {

    auto start = std::chrono::steady_clock::now(); // Start clock to time run-time

    // Newton Raphson and Secant parameters
    double init1 = 0.3; // First initial guess for implied volatility
    double init2 = 0.2; // Second initial guess for implied volatility used for the secant method
    double tol = 0.001; // Tolerance
    double implied_vol_call [2]; // Array to hold the call implied vols for the output file
    double implied_vol_put [2]; // Array to hold the put implied vols for the output file
    double sigma; // Implied volatility (dependent on user input data)

    // try-catch block to calculate implied volatility
    try
    {
        data data; // Struct to hold the input file data
        std::ifstream file("input.txt"); // Input file stream
        file >> data; // Read in the data from the file into the struct data
        BlackScholesOption bso(data.S, data.K, data.r, data.T); // Black-Scholes option functor

        // If-else statements depening on whether the input is call or put
        if(data.option_type == "call")
        {
            sigma = newton_raphson<BlackScholesOption,
                    &BlackScholesOption::call_option_price,
                    &BlackScholesOption::option_vega>
                    (data.F, init1, init2, tol, bso, data.i); // Calculate implied volatility using template
        }
        else if(data.option_type == "put")
        {
            sigma = newton_raphson<BlackScholesOption,
                    &BlackScholesOption::put_option_price,
                    &BlackScholesOption::option_vega>
                    (data.F, init1, init2, tol, bso, data.i); // Calculate implied volatility using template
        }

        std::cout << "Implied Vol: " << sigma << std::endl; // Output implied volatility to the console


        // Output the file, note CLion has to have it's working directory set to the project directory in order for
        // the file to output in the projects directory otherwise the output file will be sent to the "cmake-build-debug"
        // folder
        BlackScholesOption bso_output(1157.86, 1125, 0.02,0.0602739726); // Black Scholes option object holding the required output data

        // Loop to calculate the implied volatility under the newton method and secant method for output file
        for(int i = 1; i<=2; i++)
        {
            double sigma_put = newton_raphson<BlackScholesOption,
                    &BlackScholesOption::put_option_price,
                    &BlackScholesOption::option_vega>
                    (19.7, init1, init2, tol, bso_output, i);

            implied_vol_put[i-1] = sigma_put; // Insert the put implied volatility into the implied_vol_put array

            double sigma_call = newton_raphson<BlackScholesOption,
                    &BlackScholesOption::call_option_price,
                    &BlackScholesOption::option_vega>
                    (43, init1, init2, tol, bso_output, i);

            implied_vol_call[i-1] = sigma_call; // Insert the call implied volatility into the implied_vol_call array
        }

        output_file of {bso_output,implied_vol_call[0],implied_vol_call[1],implied_vol_put[0],implied_vol_put[1]};
        std::ofstream output;
        output << of;
    }
    catch(const std::runtime_error & f)
    {
        std::cout << f.what() << std::endl; // Throw a run-time error
    }
    catch(const std::invalid_argument & e)
    {
        std::cout << e.what() << std::endl; // Throw an invalid argument error
    }
    catch(...)
    {
        std::cout << "Unknown error" << std::endl; // Catch any other errors
    }

    auto end = std::chrono::steady_clock::now(); // end time

    std::cout << "Elapsed time in nanoseconds : "
         << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
         << " ns" << std::endl; // Output to the console the run-time of the algorithm in nanoseconds

    return 0;
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  end of file
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX