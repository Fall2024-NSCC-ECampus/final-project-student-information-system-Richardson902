//
// Created by nick on 11/23/2024.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <utility>

struct Student {
    int id;
    std::string firstName;
    std::string lastName;
    double midtermMarkOne;
    double midtermMarkTwo;
    double finalMark;

    Student() : id(0), midtermMarkOne(0.0), midtermMarkTwo(0.0), finalMark(0.0) {}

    Student(const int id, std::string firstName, std::string lastName, const double midtermGradeOne, const double midtermGradeTwo, const double finalGrade)
        : id(id), firstName(std::move(firstName)), lastName(std::move(lastName)), midtermMarkOne(midtermGradeOne), midtermMarkTwo(midtermGradeTwo), finalMark(finalGrade) {}

};

#endif //STUDENT_H
