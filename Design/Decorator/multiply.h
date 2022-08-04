#include "decorator.h"

class MultDecorator: public Decorator {
    int val;
public:
    void setValue(int n) override;
    int updatePrint() override;
};
