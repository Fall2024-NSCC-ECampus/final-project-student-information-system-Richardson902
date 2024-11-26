//
// Created by nick on 11/25/2024.
//

#include "SystemController.h"

void SystemController::start()
{
    while(true)
    {
        IOHandler::printMainMenu();

        switch(IOHandler::getIntInput())
        {
        case 1:
            IOHandler::printMessage("");
            studentManager.printAllStudentData();
            IOHandler::waitForEnter();
            break;
        case 2:
            IOHandler::printMessage("");
            studentManager.printStudentsByLastName();
            IOHandler::waitForEnter();
            break;
        case 3:
            IOHandler::printMessage("");
            studentManager.addStudent();
            IOHandler::waitForEnter();
            break;
        case 4:
            IOHandler::printMessage("");
            studentManager.calculateFinalGrades();
            IOHandler::waitForEnter();
            break;
        case 5:
            IOHandler::printMessage("");
            studentManager.updateStudent();
            IOHandler::waitForEnter();
            break;
        case 6:
            IOHandler::printMessage("");
            studentManager.printStudentData();
            IOHandler::waitForEnter();
            break;
        case 7:
            IOHandler::printMessage("");
            studentManager.removeStudent();
            IOHandler::waitForEnter();
            break;
        case 8:
            IOHandler::printMessage("");
            studentManager.deleteAllStudentData();
            IOHandler::waitForEnter();
            break;
        case 9:
            IOHandler::printMessage("");
            gradeCalculator.changeWeights();
            IOHandler::waitForEnter();
            break;
        case 10:
            return;
        default:
            IOHandler::printMessage("Invalid choice.");
            IOHandler::waitForEnter();
        }
    }
}

//TODO add a press enter to continue button after displaying data
//TODO mess around with format of update student
//TODO make id unique


