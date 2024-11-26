//
// Created by nick on 11/26/2024.
//

#include "GradeCalculator.h"
#include "IOHandler.h"

double GradeCalculator::calculateWeightedAverage(const double midtermOne, const double midtermTwo, const double final) const {
    if (midtermOne < 0.0 || midtermOne > 100.0 || midtermTwo < 0.0 || midtermTwo > 100.0 || final < 0.0 || final > 100.0) {
        throw std::invalid_argument("Invalid input: Marks should be between 0 and 100.");
    }
    return (midtermOne * midtermOneWeight + midtermTwo * midtermTwoWeight + final * finalWeight);
}

char GradeCalculator::calculateLetterGrade(const double weightedAverage)
{
    if (weightedAverage < 0.0 || weightedAverage > 100.0) {
        throw std::invalid_argument("Invalid weighted average: must be between 0 and 100.");
    }

    if (weightedAverage >= 90) {
        return 'A';
    }
    if (weightedAverage >= 80) {
        return 'B';
    }
    if (weightedAverage >= 70) {
        return 'C';
    }
    if (weightedAverage >= 60) {
        return 'D';
    }
    return 'F';
}

void GradeCalculator::changeWeights()
{
    try
    {
        IOHandler::printMessage("Enter the percentage for the first midterm:");
        setMidtermOneWeight(IOHandler::getDoubleInput() / 100);
        IOHandler::printMessage("Enter the percentage for the second midterm:");
        setMidtermTwoWeight(IOHandler::getDoubleInput() / 100);
        IOHandler::printMessage("Enter the percentage for the final:");
        setFinalWeight(IOHandler::getDoubleInput() / 100);

        // Check if the total weights sum to 1.0
        if (const double totalWeight = midtermOneWeight + midtermTwoWeight + finalWeight; totalWeight != 1.0) {
            throw std::invalid_argument("Invalid weights: The total weights must sum to 1.0. Please try again.");
        }

        // Display the updated weights
        IOHandler::printMessage("Updated weights:");
        IOHandler::printMessage("First midterm weight: " + std::to_string(static_cast<int>(midtermOneWeight * 100)) + "%");
        IOHandler::printMessage("Second midterm weight: " + std::to_string(static_cast<int>(midtermTwoWeight * 100)) + "%");
        IOHandler::printMessage("Final weight: " + std::to_string(static_cast<int>(finalWeight * 100)) + "%");
    }
    catch (std::exception& e)
    {
        IOHandler::printMessage(std::string("Error changing weights: ") + e.what());
    }
}



void GradeCalculator::setMidtermOneWeight(const double weight) {
    midtermOneWeight = weight;
}

void GradeCalculator::setMidtermTwoWeight(const double weight) {
    midtermTwoWeight = weight;
}

void GradeCalculator::setFinalWeight(const double weight) {
    finalWeight = weight;
}

