cmake_minimum_required(VERSION 3.29)
project(student_information_system)

set(CMAKE_CXX_STANDARD 20)

add_executable(student_information_system main.cpp
        StudentManager.h
        StudentManager.cpp
        IOHandler.h
        IOHandler.cpp
        SystemController.h
        SystemController.cpp
        Validator.h
        Validator.cpp
        GradeCalculator.h
        GradeCalculator.cpp
)
