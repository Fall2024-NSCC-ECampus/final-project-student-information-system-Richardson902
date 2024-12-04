# Student Information System

## Overview
The Student Information System is a C++ application designed to manage student data, including adding, updating, removing, and displaying student information. It allows for saving and loading class data from files and calculating final grades based on customizable weighted averages.

## Features
- Add, update, and remove student information
- Display individual or all student data
- Sort students by last name
- Save and load class data to/from files
- Calculate final grades based on weighted averages
- Change weights for midterms and final exams

## Usage
1. **Start the Application:** Run the application to start the Student Information System.
2. **Main Menu:** Choose from the following options:
    - '1' -> Print all Student data
    - '2' -> Sort Students by Last Name
    - '3' -> Add Student
    - '4' -> Calculate letter grade of all students
    - '5' -> Update information of student
    - '6' -> Print data of specific student
    - '7' -> Remove student
    - '8' -> Delete ALL student data
    - '9' -> Change grading scheme
    - '10' -> Save class data to file
    - '11' -> Overwrite class data to file
    - '12' -> Load class data from file
    - '13' -> Quit

## How to Run

### Prerequisites
- A C++ compiler
- CMake (for building the project)

### Building the Project
1. Clone the repository:
    ```bash
   git clone https://github.com/Fall2024-NSCC-ECampus/final-project-student-information-system-Richardson902
    cd final-project-student-information-system-Richardson902
    ```
2. Create a build directory and navigate to it:
    ```bash
    mkdir build
    cd build
    ```
3. Run CMake to configure the project:
    ```bash
    cmake ..
    ```
4. Build the project:
    ```bash
    make
    ```

### Running the Application

After building the project, you can run the application from the build directory:
```bash
./student_information_system
```