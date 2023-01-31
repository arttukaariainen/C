#ifndef MYUI_H
#define MYUI_H

#include "standardcalculator.h"
#include <iostream>

using namespace std;


class MyUi
{
public:
    MyUi();
    ~MyUi();
    void inputnumbers();
    void showmenu();
    void showresults(short parameter);
private:
    double numberOne, numberTwo, result;
    StandardCalculator *objectStandardCalculator;
};

#endif // MYUI_H
