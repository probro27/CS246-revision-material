#include "add.h"

using namespace std;

void AddDecorator::setValue(int n) {
    Decorator::setValue(n);
}

int AddDecorator::updatePrint() {
    return val + Decorator::updatePrint();
}
