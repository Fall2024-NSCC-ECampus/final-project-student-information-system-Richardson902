//
// Created by nick on 11/23/2024.
//

#include "IOHandler.h"

#include <algorithm>
#include <iomanip>
#include <limits>

void IOHandler::printMainMenu()
{
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "1) Print all Student data" << std::endl;
    std::cout << "2) Sort the list of students in alphabetical order of last name" << std::endl;
    std::cout << "3) Add a new student" << std::endl;
    std::cout << "4) Calculate the letter grade of all students" << std::endl;
    std::cout << "5) Change the information of a previous student" << std::endl;
    std::cout << "6) Print the data of a specific student" << std::endl;
    std::cout << "7) Remove a student from the list" << std::endl;
    std::cout << "8) Delete ALL student data" << std::endl;
    std::cout << "9) Change grading scheme" << std::endl;
    std::cout << "10) Save class" << std::endl;
    std::cout << "11) Overwrite current class" << std::endl;
    std::cout << "12) Load class" << std::endl;
    std::cout << "13) Exit" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
}


void IOHandler::printMessage(const std::string& message)
{
    std::cout << message << std::endl;
}

void IOHandler::waitForEnter()
{
    std::cin.clear();
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void IOHandler::printStudentRemoved(const int id)
{
    std::cout << "Student with ID: " << id << " has been removed." << std::endl;
}

void IOHandler::printUpdateOptions()
{
    std::cout << "What would you like to update?" << std::endl;
    std::cout << "1) First Name" << std::endl;
    std::cout << "2) Last Name" << std::endl;
    std::cout << "3) Midterm Mark One" << std::endl;
    std::cout << "4) Midterm Mark Two" << std::endl;
    std::cout << "5) Final Mark" << std::endl;
    std::cout << "6) Back" << std::endl;
}

void IOHandler::printStudentDataHeader()
{
    std::cout << std::left
          << std::setw(10) << "ID"
          << std::setw(20) << "Name"
          << std::setw(20) << "Lastname"
          << std::setw(10) << "Midterm1"
          << std::setw(10) << "Midterm2"
          << std::setw(10) << "Final" << '\n';
}

void IOHandler::printGradeHeader()
{
    std::cout << std::left
            << std::setw(10) << "ID"
            << std::setw(20) << "Name"
            << std::setw(20) << "Lastname"
            << std::setw(10) << "Grade" << '\n';
}


int IOHandler::getIntInput()
{
    int input;
    while (true)
    {
        if (std::cin >> input) // check if the input is an integer
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return input;
        }

        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the input
        throw std::invalid_argument("Invalid input. Please enter a number.");
    }
}

double IOHandler::getDoubleInput()
{
    double input;
    while (true)
    {
        if (std::cin >> input && input >= 1.0 && input <= 100.0) // check if the input is a double between 1 and 100
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return input;
        }

        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the input
        throw std::out_of_range("Invalid input. Please enter a number between 1 and 100.");
    }
}

std::string IOHandler::getStringInput()
{
    std::string input;
    std::getline(std::cin >> std::ws, input);

    // Convert input to lowercase
    std::ranges::transform(input, input.begin(), [](const unsigned char c){ return std::tolower(c); });
    return input;
}

char IOHandler::getCharInput()
{
    char input;
    while (true)
    {
        if (std::cin >> input) // check if the input is a char
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return input;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Invalid input. Please enter y/n.");
    }
}







