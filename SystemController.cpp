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
            studentManager.printAllStudentData();
            break;
        case 2:
            break;
        case 3:
            IOHandler::printMessage("");
            studentManager.addStudent();
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            return;
        default:
            IOHandler::printMessage("Invalid choice.");
        }
    }
}


