//
// Created by nick on 11/23/2024.
//

#ifndef IOHANDLER_H
#define IOHANDLER_H

#include <iostream>
#include <string>

class IOHandler {
public:
    static void printMainMenu();
    static void printMessage(const std::string& message);
    static void printStudentInfoPrompt();
    static void printStudentRemoved(int id);
    static void printStudentNotFound(int id);
    static void printUpdateOptions();
    static void printStudentDataHeader();
    [[nodiscard]] static int getIntInput();
    [[nodiscard]] static std::string getStringInput();
    // [[nodiscard]] static double getDoubleInput();

};

#endif //IOHANDLER_H
