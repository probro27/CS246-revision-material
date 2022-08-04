#include "decorator.h"

class SubDecorator: public Decorator {
    int val;
public:
    SubDecorator(Sequence *sq, int n);
    void setValue(int n) override;
    void updatePrint() override;
    int getValue() const override;
};
