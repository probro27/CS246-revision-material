#include "basefunc.h"

using namespace std;

BaseFunc::BaseFunc(int n) {
    value = n;
}

void BaseFunc::setValue(int n) {
    value = n;
}

int BaseFunc::getValue() const {
    return value;
}

void BaseFunc::updatePrint() {}
