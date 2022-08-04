#ifndef _DECORATOR_H_
#define _DECORATOR_H_
#include "sequence.h"

class Decorator: public Sequence {
    Sequence *sq;
public:
    Decorator(Sequence *s): sq{s} {}
    void setValue(int n) override {
        sq->setValue(n);
    }
    void updatePrint() override {
        sq->updatePrint();
    }
    int getValue() const override {
        return sq->getValue();
    }
    ~Decorator() {
        delete sq;
    }
};

#endif
