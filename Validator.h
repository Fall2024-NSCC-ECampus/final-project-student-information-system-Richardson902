//
// Created by nick on 11/25/2024.
//

#ifndef VALIDATION_H
#define VALIDATION_H

#include <functional>
#include <string>

class Validator {
public:
    template <typename T>
    static T getValidInput(const std::string& prompt, std::function<void(const T&)> validate);

    static void validateInt(int i);
    static void validateString(const std::string& s);
    static void validateDouble(double d);
};

#endif //VALIDATION_H
