#include "add.h"

using namespace std;

AddDecorator::AddDecorator(Sequence *sq, int n): Decorator{sq} {
    val = n;
}

void AddDecorator::setValue(int n) {
    Decorator::setValue(n);
}

int AddDecorator::getValue() const {
    return Decorator::getValue();
}

void AddDecorator::updatePrint() {
    Decorator::updatePrint();
    setValue(getValue() + val);
}
