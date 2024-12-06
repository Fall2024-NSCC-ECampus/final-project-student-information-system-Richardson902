//
// Created by nick- on 11/26/2024.
//

#include "FileHandler.h"
#include "IOHandler.h"
#include <filesystem>
#include <fstream>
#include <iostream>

void FileHandler::saveClass(const std::string& directory, const std::string& className, const std::vector<Student>& students) {
    std::filesystem::create_directories(directory);
    std::ofstream outFile(directory + "/" + className + ".txt"); // Create file in directory
    if (!outFile) {
        throw std::runtime_error("Unable to create file: " + className + ".txt");
    }
    for (const auto& student : students) { // Write student data to file
        outFile << student.id << " "
                << student.firstName << " "
                << student.lastName << " "
                << student.midtermMarkOne << " "
                << student.midtermMarkTwo << " "
                << student.finalMark << '\n';
    }
    outFile.close();
    IOHandler::printMessage("Class saved successfully.");
}

std::vector<Student> FileHandler::loadClass(const std::string& directory, const std::string& className) {
    std::ifstream inFile(directory + "/" + className + ".txt"); // Open file in directory
    if (!inFile) {
        throw std::runtime_error("Unable to open file: " + className + ".txt");
    }
    std::vector<Student> students;
    Student student;

    // Read student data from file and add to vector
    while (inFile >> student.id >> student.firstName >> student.lastName >> student.midtermMarkOne >> student.midtermMarkTwo >> student.finalMark) {
        students.push_back(student);
    }
    inFile.close();
    IOHandler::printMessage("Class loaded successfully.");
    return students;
}

void FileHandler::listClassFiles(const std::string& directory) {
    if (!std::filesystem::exists(directory)) {
        throw std::runtime_error("Directory does not exist: " + directory);
    }

    // List all .txt files in directory
    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            std::cout << entry.path().filename().string() << std::endl;
        }
    }
}
