#include "elf.h"
#include <iostream>

using namespace std;

Elf::Elf(string name, int songsSung): Creature{name}, _songsSung{songsSung} {}

double Elf::calculateSalary() const {
    return 500 * _songsSung;
}

void Elf::printSalary() const {
    const double amount = calculateSalary();
    string message = _name + "the Elf has earned " + to_string(amount);
    cout << message << endl;
}
