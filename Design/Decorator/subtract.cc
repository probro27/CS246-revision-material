#include "subtract.h"

using namespace std;

SubDecorator::SubDecorator(Sequence *sq, int n): Decorator{sq} {
    val = n;
}

void SubDecorator::setValue(int n) {
    Decorator::setValue(n);
}

int SubDecorator::getValue() const {
    return Decorator::getValue();
}

void SubDecorator::updatePrint() {
    Decorator::updatePrint();
    setValue(getValue() - val);
}
