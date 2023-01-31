#include "myui.h"

MyUi::MyUi()
{
    objectStandardCalculator = new StandardCalculator;
}
MyUi::~MyUi()
{
    delete objectStandardCalculator;
    objectStandardCalculator = nullptr;
}
void MyUi::inputnumbers()
{
    cout << "Anna luku yksi:";
    cin >> numberOne;
    cout << "Anna luku kaksi:";
    cin >> numberTwo;
    cout << endl;
}
void MyUi::showmenu()
{
    short menuVariable;
    cout << "NELILASKIN" << endl;
    cout << "==========" << endl;
    cout << "1 = summa" << endl;
    cout << "2 = erotus" << endl;
    cout << "3 = tulo" << endl;
    cout << "4 = osamaara" << endl;
    cout << "5 = lopetus" << endl;
    cout << "valitse: ";
    cin >> menuVariable;
    cout << endl;
    if (menuVariable!=5){inputnumbers();}
    switch (menuVariable){
    case 1: result = objectStandardCalculator->plus(numberOne, numberTwo);
        break;
    case 2: result = objectStandardCalculator->minus(numberOne, numberTwo);
        break;
    case 3: result = objectStandardCalculator->mult(numberOne, numberTwo);
        break;
    case 4: result = objectStandardCalculator->div(numberOne, numberTwo);
        break;
    case 5: return;
        break;
    }
    MyUi::showresults(menuVariable);
}
void MyUi::showresults(short parameter)
{
    cout << "Laskutoimitus ja tulos :" << endl;
    switch (parameter){
    case 1: cout << numberOne << "+" << numberTwo << "=" << result;
        break;
    case 2: cout << numberOne << "-" << numberTwo << "=" << result;
        break;
    case 3: cout << numberOne << "*" << numberTwo << "=" << result;
        break;
    case 4: cout << numberOne << "/" << numberTwo << "=" << result;
        break;
    }
    cout << endl;
    cout << endl;
    MyUi::showmenu();
}
