#include "decorator.h"

class AddDecorator: public Decorator {
    int val;
public:
    void setValue(int n) override;
    int updatePrint() override;
};
