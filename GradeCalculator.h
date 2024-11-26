//
// Created by nick on 11/26/2024.
//

#ifndef GRADECALCULATOR_H
#define GRADECALCULATOR_H



class GradeCalculator {
public:
    [[nodiscard]] double calculateWeightedAverage(double midtermOne, double midtermTwo, double final) const;
    static char calculateLetterGrade(double weightedAverage);
    void changeWeights();

    void setMidtermOneWeight(double weight);
    void setMidtermTwoWeight(double weight);
    void setFinalWeight(double weight);

private:
    double midtermOneWeight = 0.25;
    double midtermTwoWeight = 0.25;
    double finalWeight = 0.50;

};



#endif //GRADECALCULATOR_H
