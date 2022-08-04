#include "decorator.h"

class MultDecorator: public Decorator {
    int val;
public:
    MultDecorator(Sequence *sq, int n);
    void setValue(int n) override;
    void updatePrint() override;
    int getValue() const override;
};
