//
// Created by nick on 11/25/2024.
//

#ifndef SYSTEMCONTROLLER_H
#define SYSTEMCONTROLLER_H

#include "IOHandler.h"
#include "StudentManager.h"

class SystemController {

public:
    void start();

private:
    IOHandler ioHandler;
    StudentManager studentManager;
    GradeCalculator gradeCalculator;
};

#endif //SYSTEMCONTROLLER_H
