#include "sequence.h"

class Decorator: public Sequence {
    Sequence *sq;
public:
    void setValue(int n) override {
        sq->setValue(n);
    }
    int updatePrint() override {
        return sq->updatePrint();
    }
    
    ~Decorator() {
        delete sq;
    }
};
