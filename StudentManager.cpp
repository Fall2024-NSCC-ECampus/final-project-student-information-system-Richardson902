//
// Created by nick on 11/23/2024.
//

#include "StudentManager.h"
#include "IOHandler.h"
#include "Validator.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <filesystem>
#include <list>

#include "FileHandler.h"


StudentManager::StudentManager() = default;

void StudentManager::addStudent()
{
    try
    {
        // Validate student ID
        const int id = Validator::getValidInput<int>("Enter ID:", Validator::validateInt);

        if (std::ranges::any_of(students, [id](const Student& s) {return s.id == id; })) // Check if student with that ID already exists
        {
            throw std::runtime_error("Student with that ID already exists.");
        }

        // Validate student data
        const auto firstName = Validator::getValidInput<std::string>("Enter first name:", Validator::validateString);
        const auto lastName = Validator::getValidInput<std::string>("Enter last name:", Validator::validateString);
        const auto midtermMarkOne = Validator::getValidInput<double>("Enter midterm mark one:", Validator::validateDouble);
        const auto midtermMarkTwo = Validator::getValidInput<double>("Enter midterm mark two:", Validator::validateDouble);
        const auto finalMark = Validator::getValidInput<double>("Enter final mark:", Validator::validateDouble);

        students.emplace_back(id, firstName, lastName, midtermMarkOne, midtermMarkTwo, finalMark); // Add student to list
        IOHandler::printMessage("Student added successfully.");
    }
    catch (std::exception& e)
    {
        IOHandler::printMessage(std::string("Error adding student: ") + e.what());
    }
}

auto StudentManager::findStudentById(int id)
{

    // Find student by ID
    const auto it = std::ranges::find_if(students, [id](const Student& s)
    {
        return s.id == id;
    });

    if (it == students.end()) // If student not found
    {
        throw std::runtime_error("Student not found");
    }

    return it; // Return iterator to student
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
            students.erase(it); // Remove student
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

        IOHandler::printStudentDataHeader(); // Print header
        if (const auto it = findStudentById(id); it != students.end())
        {
            const auto& student = *it; // Get student
            printStudent(student);
        }
    }
    catch (const std::exception& e)
    {
        IOHandler::printMessage(std::string("Error displaying student data: ") + e.what());
    }

}

void StudentManager::printStudent(const Student& student)
{
    // Print student data with formatting
    std::cout << std::left
              << std::setw(10) << student.id
              << std::setw(20) << student.firstName
              << std::setw(20) << student.lastName
              << std::setw(10) << student.midtermMarkOne
              << std::setw(10) << student.midtermMarkTwo
              << std::setw(10) << student.finalMark << '\n';
}

void StudentManager::printAllStudentData()
{
    try
    {
        checkStudents();
        IOHandler::printStudentDataHeader();
        for (const auto& student : students) // for each student print data
        {
            printStudent(student);

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
            if (a.lastName == b.lastName) // If last names are the same, sort by first name
            {
                return a.firstName < b.firstName;
            }
            return a.lastName < b.lastName;
        });

        IOHandler::printStudentDataHeader();
        for (const auto& student: students) // Print sorted students
        {
            printStudent(student);
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
            // Calculate weighted average and letter grade
            const double weightedAverage = gradeCalculator.calculateWeightedAverage(student.midtermMarkOne, student.midtermMarkTwo, student.finalMark);
            const char letterGrade = GradeCalculator::calculateLetterGrade(weightedAverage);

            // Print student data with letter grade formatted
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
        if (const auto response = IOHandler::getCharInput(); response == 'y' || response == 'Y') // prompt user to confirm deletion
        {
            students.clear(); // clear the list of students
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
    if (students.empty()) // if list empty, throw exception
    {
        throw std::runtime_error("No students found.");
    }
}

void StudentManager::saveNewClass() const
{
    try
    {
        checkStudents();
        IOHandler::printMessage("Enter class name to save:");
        const std::string className = IOHandler::getStringInput();
        FileHandler::saveClass(defaultDirectory, className, students); // save class to file
    }
    catch (std::exception& e)
    {
        IOHandler::printMessage(std::string("Error saving new class: ") + e.what());
    }
}

void StudentManager::overwriteClass() const
{

    try
    {
        FileHandler::listClassFiles(defaultDirectory);
        checkStudents();
        IOHandler::printMessage("Enter class name to overwrite:");
        const std::string className = IOHandler::getStringInput();
        FileHandler::saveClass(defaultDirectory, className, students); // overwrite class file
    }
    catch (std::exception& e)
    {
        IOHandler::printMessage(std::string("Error overwriting class: ") + e.what());
    }
}

void StudentManager::listClassFiles() const
{
    try
    {
        FileHandler::listClassFiles(defaultDirectory); // list all class files in directory
    }
    catch (const std::filesystem::filesystem_error& e)
    {
        IOHandler::printMessage(std::string("Error accessing directory: ") + e.what());
    }
}

void StudentManager::loadClass()
{
    try
    {
        FileHandler::listClassFiles(defaultDirectory); // list all class files in directory
        IOHandler::printMessage("Enter class name to load:");
        const std::string className = IOHandler::getStringInput();
        students = FileHandler::loadClass(defaultDirectory, className); // load class from file
    }
    catch (std::exception& e)
    {
        IOHandler::printMessage(std::string("Error loading class: ") + e.what());
    }
}





