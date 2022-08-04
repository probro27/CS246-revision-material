#include "multiply.h"

using namespace std;

MultDecorator::MultDecorator(Sequence *sq, int n):Decorator{sq} {
    val = n;
}

void MultDecorator::setValue(int n) {
    Decorator::setValue(n);
}

int MultDecorator::getValue() const {
    return Decorator::getValue();
}

void MultDecorator::updatePrint() {
    Decorator::updatePrint();
    setValue(getValue() * val);
}
