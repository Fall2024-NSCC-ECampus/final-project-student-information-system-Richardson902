//
// Created by nick- on 11/23/2024.
//

#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <vector>
#include "Student.h"

class StudentManager {
public:
    StudentManager();

    void addStudent();
    void removeStudent();
    void updateStudent();
    void deleteAllStudentData();
    void printAllStudentData();
    void printStudentData();

private:
    std::vector<Student> students;
    auto findStudentById(int id);
};



#endif //STUDENTMANAGER_H
