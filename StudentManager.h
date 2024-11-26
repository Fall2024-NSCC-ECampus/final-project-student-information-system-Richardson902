//
// Created by nick on 11/23/2024.
//

#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <vector>

#include "GradeCalculator.h"
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
    void printStudentsByLastName();
    void calculateFinalGrades();
    void checkStudents() const;
    void saveNewClass() const;
    void overwriteClass() const;
    void loadClass();
    void listClassFiles() const;
    static void printStudent(const Student& student) ;


private:
    std::vector<Student> students;
    GradeCalculator gradeCalculator;
    std::string defaultDirectory = "./classes";
    auto findStudentById(int id);
};



#endif //STUDENTMANAGER_H
