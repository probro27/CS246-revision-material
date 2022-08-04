#include "orc.h"
#include <iostream>

using namespace std;

Orc::Orc(string name, int battlesWon, int murdersCommitted): Creature{name}, _battlesWon{battlesWon}, _murdersCommitted{murdersCommitted} {}

double Orc::calculateSalary() const {
    double battleMoney = 500 * _battlesWon;
    double murderMoney = 100 * _murdersCommitted;
    double salary = battleMoney - murderMoney;
    return salary;
}

void Orc::printSalary() const {
    const double amount = calculateSalary();
    string message = _name + " the Orc earned " + to_string(amount);
    cout << message << endl;
}
