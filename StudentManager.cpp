//
// Created by nick- on 11/23/2024.
//

#include "StudentManager.h"
#include "IOHandler.h"
#include "Validator.h"

#include <algorithm>
#include <iostream>
#include <iomanip>


StudentManager::StudentManager() = default;

void StudentManager::addStudent()
{
    IOHandler::printStudentInfoPrompt();

    const int id = Validator::getValidInput<int>("Enter ID:", Validator::validateInt);
    const auto firstName = Validator::getValidInput<std::string>("Enter first name:", Validator::validateString);
    const auto lastName = Validator::getValidInput<std::string>("Enter last name:", Validator::validateString);
    const auto midtermMarkOne = Validator::getValidInput<double>("Enter midterm mark one:", Validator::validateDouble);
    const auto midtermMarkTwo = Validator::getValidInput<double>("Enter midterm mark two:", Validator::validateDouble);
    const auto finalMark = Validator::getValidInput<double>("Enter final mark:", Validator::validateDouble);

    students.emplace_back(id, firstName, lastName, midtermMarkOne, midtermMarkTwo, finalMark);
    IOHandler::printMessage("Student added successfully.");
}

auto StudentManager::findStudentById(int id)
{
    return std::ranges::find_if(students, [id](const Student& s)
    {
        return s.id == id;
    });
}


void StudentManager::removeStudent()
{
    IOHandler::printMessage("Enter the student's ID you would like to remove");
    const int id = IOHandler::getIntInput();

    if (const auto it = findStudentById(id); it != students.end())
    {
        students.erase(it);
        IOHandler::printStudentRemoved(id);
    } else
    {
        IOHandler::printStudentNotFound(id);
    }
}

void StudentManager::updateStudent()
{
    IOHandler::printMessage("Choose a student you would like to update");
    const int id = IOHandler::getIntInput();

    if (const auto it = findStudentById(id); it != students.end())
    {
        while (true)
        {
            IOHandler::printUpdateOptions();

            switch (IOHandler::getIntInput())
            {
            case 1:
                IOHandler::printMessage("Enter the updated first name");
                it->firstName = IOHandler::getStringInput();
                break;
            case 2:
                IOHandler::printMessage("Enter the updated last name");
                it->lastName = IOHandler::getStringInput();
                break;
            case 3:
                IOHandler::printMessage("Enter the updated midterm mark one");
                // it->midtermMarkOne = IOHandler::getDoubleInput();
                break;
            case 4:
                IOHandler::printMessage("Enter the updated midterm mark two");
                // it->midtermMarkTwo = IOHandler::getDoubleInput();
                break;
            case 5:
                IOHandler::printMessage("Enter the updated final mark");
                // it->finalMark = IOHandler::getDoubleInput();
                break;
            case 6:
                return;
            default:
                IOHandler::printMessage("Invalid choice");
                break;
            }
        }
    }
    IOHandler::printStudentNotFound(id);
}

void StudentManager::printAllStudentData()
{
    IOHandler::printStudentDataHeader();
    for (const auto& student : students)
    {
        std::cout << std::left
                      << std::setw(10) << student.id
                      << std::setw(20) << student.firstName
                      << std::setw(20) << student.lastName
                      << std::setw(10) << student.midtermMarkOne
                      << std::setw(10) << student.midtermMarkTwo
                      << std::setw(10) << student.finalMark << '\n';

    }
}


