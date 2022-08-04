#include "decorator.h"

class DivDecorator: public Decorator {
    int val;
public:
    DivDecorator(Sequence *sq, int n);
    void setValue(int n) override;
    void updatePrint() override;
    int getValue() const override;
};
