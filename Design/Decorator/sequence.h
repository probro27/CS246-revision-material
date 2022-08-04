#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

class Sequence {
public:
    virtual void updatePrint() = 0;
    virtual void setValue(int n) = 0;
    virtual int getValue() const = 0;
    virtual ~Sequence() {}
};

#endif
