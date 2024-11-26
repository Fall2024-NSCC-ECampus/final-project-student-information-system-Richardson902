//
// Created by nick on 11/26/2024.
//

#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include <string>
#include "Student.h"

class FileHandler {
public:
    static void saveClass(const std::string& directory, const std::string& className, const std::vector<Student>& students);
    static std::vector<Student> loadClass(const std::string& directory, const std::string& className);
    static void listClassFiles(const std::string& directory);
};

#endif // FILEHANDLER_H
