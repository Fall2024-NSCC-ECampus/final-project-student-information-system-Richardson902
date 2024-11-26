//
// Created by nick on 11/25/2024.
//

#include "Validator.h"

#include <iostream>
#include <limits>
#include <stdexcept>

template <typename T>
T Validator::getValidInput(const std::string& prompt, std::function<void(const T&)> validate)
{
    while (true)
    {
        try
        {
            // ****Originally wanted to use cerr for the error message but ran into buffer issues so this will have to do****
            std::cout << prompt;
            T value;
            std::cin >> value;

            //  Check if input stream is in valid state
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::invalid_argument("Invalid input. Please enter a valid value.");
            }

            // Validate value using provided function
            validate(value);

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            return value;
        } catch (const std::exception& e)
        {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
}

// Explicit template instantiations
template int Validator::getValidInput<int>(const std::string&, std::function<void(const int&)>);
template std::string Validator::getValidInput<std::string>(const std::string&, std::function<void(const std::string&)>) ;
template double Validator::getValidInput<double>(const std::string&, std::function<void(const double&)>) ;

void Validator::validateInt(const int i)
{
    if (i < 0)
    {
        throw std::out_of_range("Value must be positive.");
    }
}

void Validator::validateString(const std::string& s)
{
    if (s.empty())
    {
        throw std::invalid_argument("String cannot be empty.");
    }
}

void Validator::validateDouble(const double d)
{
    if (d < 0.0 || d > 100.0)
    {
        throw std::out_of_range("Value must be a positive number and between 0 - 100.");
    }

}





