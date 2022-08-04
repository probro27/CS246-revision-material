#include "decorator.h"

class SubDecorator: public Decorator {
    int val;
public:
    void setValue(int n) override;
    int updatePrint() override;
};
