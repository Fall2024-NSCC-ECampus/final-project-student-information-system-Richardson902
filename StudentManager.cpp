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
    try
    {
        const int id = Validator::getValidInput<int>("Enter ID:", Validator::validateInt);

        if (std::ranges::any_of(students, [id](const Student& s) {return s.id == id; }))
        {
            throw std::runtime_error("Student with that ID already exists.");
        }

        const auto firstName = Validator::getValidInput<std::string>("Enter first name:", Validator::validateString);
        const auto lastName = Validator::getValidInput<std::string>("Enter last name:", Validator::validateString);
        const auto midtermMarkOne = Validator::getValidInput<double>("Enter midterm mark one:", Validator::validateDouble);
        const auto midtermMarkTwo = Validator::getValidInput<double>("Enter midterm mark two:", Validator::validateDouble);
        const auto finalMark = Validator::getValidInput<double>("Enter final mark:", Validator::validateDouble);

        students.emplace_back(id, firstName, lastName, midtermMarkOne, midtermMarkTwo, finalMark);
        IOHandler::printMessage("Student added successfully.");
    }
    catch (std::exception& e)
    {
        IOHandler::printMessage(std::string("Error adding student: ") + e.what());
    }
}

auto StudentManager::findStudentById(int id)
{

    const auto it = std::ranges::find_if(students, [id](const Student& s)
    {
        return s.id == id;
    });

    if (it == students.end())
    {
        throw std::runtime_error("Student not found");
    }

    return it;
}


void StudentManager::removeStudent()
{
    try
    {
        checkStudents();
        IOHandler::printMessage("Enter the student's ID you would like to remove");
        const int id = IOHandler::getIntInput();

        if (const auto it = findStudentById(id); it != students.end())
        {
            students.erase(it);
            IOHandler::printStudentRemoved(id);
        }
    }
    catch (const std::exception& e)
    {
        IOHandler::printMessage(std::string("Error removing student: ") + e.what());
    }
}

void StudentManager::updateStudent()
{
    try
    {
        checkStudents();
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
                    it->midtermMarkOne = IOHandler::getDoubleInput();
                    break;
                case 4:
                    IOHandler::printMessage("Enter the updated midterm mark two");
                    it->midtermMarkTwo = IOHandler::getDoubleInput();
                    break;
                case 5:
                    IOHandler::printMessage("Enter the updated final mark");
                    it->finalMark = IOHandler::getDoubleInput();
                    break;
                case 6:
                    return;
                default:
                    IOHandler::printMessage("Invalid choice");
                    break;
                }
            }
        }
    }
    catch (const std::exception& e)
    {
        IOHandler::printMessage(std::string("Error updating student: ") + e.what());
    }
}

void StudentManager::printStudentData()
{
    try
    {
        checkStudents();
        IOHandler::printMessage("Enter the student's ID you would like to view");
        const int id = IOHandler::getIntInput();

        IOHandler::printStudentDataHeader();
        if (const auto it = findStudentById(id); it != students.end())
        {
            const auto& student = *it;
            std::cout << std::left
                      << std::setw(10) << student.id
                      << std::setw(20) << student.firstName
                      << std::setw(20) << student.lastName
                      << std::setw(10) << student.midtermMarkOne
                      << std::setw(10) << student.midtermMarkTwo
                      << std::setw(10) << student.finalMark << '\n';
        }
    }
    catch (const std::exception& e)
    {
        IOHandler::printMessage(std::string("Error displaying student data: ") + e.what());
    }

}


void StudentManager::printAllStudentData()
{
    try
    {
        checkStudents();
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
    catch (std::exception& e)
    {
        IOHandler::printMessage(std::string("Error displaying student data: ") + e.what());
    }
}

void StudentManager::printStudentsByLastName()
{
    try
    {
        checkStudents();
        std::ranges::sort(students, [](const Student& a, const Student& b)
        {
            if (a.lastName == b.lastName)
            {
                return a.firstName < b.firstName;
            }
            return a.lastName < b.lastName;
        });

        IOHandler::printStudentDataHeader();
        for (const auto& student: students)
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
    catch (std::exception& e)
    {
        IOHandler::printMessage(std::string("Error ordering students: ") + e.what());
    }
}

void StudentManager::calculateFinalGrades()
{
    try
    {
        checkStudents();
        IOHandler::printGradeHeader();
        for (const auto& student : students)
        {
            const double weightedAverage = gradeCalculator.calculateWeightedAverage(student.midtermMarkOne, student.midtermMarkTwo, student.finalMark);
            const char letterGrade = GradeCalculator::calculateLetterGrade(weightedAverage);

            std::cout << std::left
                    << std::setw(10) << student.id
                    << std::setw(20) << student.firstName
                    << std::setw(20) << student.lastName
                    << std::setw(10) << letterGrade << '\n';
        }
    }
    catch (std::exception& e)
    {
        IOHandler::printMessage(std::string("Error calculating final grades: ") + e.what());
    }
}

void StudentManager::deleteAllStudentData()
{
    try
    {
        checkStudents();
        IOHandler::printMessage("Are you sure you want to delete all students? (y/n)");
        if (const auto response = IOHandler::getCharInput(); response == 'y' || response == 'Y')
        {
            students.clear();
            IOHandler::printMessage("All students have been deleted.");
        }
        else
        {
            IOHandler::printMessage("Operation canceled.");
        }
    }
    catch (std::exception& e)
    {
        IOHandler::printMessage(std::string("Error deleting all student data: ") + e.what());
    }
}

void StudentManager::checkStudents() const
{
    if (students.empty())
    {
        throw std::runtime_error("No students found.");
    }
}




