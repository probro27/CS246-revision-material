#include "decorator.h"

class AddDecorator: public Decorator {
    int val;
public:
    AddDecorator(Sequence *sq, int n);
    void setValue(int n) override;
    void updatePrint() override;
    int getValue() const override;
};
