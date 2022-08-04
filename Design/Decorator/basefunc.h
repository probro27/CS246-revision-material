#include "sequence.h"

class BaseFunc: public Sequence {
    int value;
public:
    BaseFunc(int n);
    void setValue(int n) override;
    int updatePrint() override;
};
