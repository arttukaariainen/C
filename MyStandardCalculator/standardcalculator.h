#ifndef STANDARDCALCULATOR_H
#define STANDARDCALCULATOR_H

#include <iostream>

class StandardCalculator
{
public:
    StandardCalculator();
    ~StandardCalculator();
    double plus(double a, double b);
    double minus(double a, double b);
    double mult(double a, double b);
    double div(double a, double b);

};

#endif // STANDARDCALCULATOR_H
