#include "divide.h"

using namespace std;

DivDecorator::DivDecorator(Sequence *sq, int n): Decorator{sq} {
    val = n;
}

void DivDecorator::setValue(int n) {
    Decorator::setValue(n);
}

int DivDecorator::getValue() const {
    return Decorator::getValue();
}

void DivDecorator::updatePrint() {
    Decorator::updatePrint();
    setValue(getValue() / val);
}
