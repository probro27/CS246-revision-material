#include "decorator.h"

class DivDecorator: public Decorator {
    int val;
public:
    void setValue(int n) override;
    int updatePrint() override;
};
