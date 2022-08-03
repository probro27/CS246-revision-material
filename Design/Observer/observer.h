#ifndef _OBSERVER_H
#define _OBSERVER_H

// #include "subject.h"
#include "info.h"
#include "state.h"

class Observer {
    public:
        virtual void notify() = 0;
        virtual ~Observer() {}
};

#endif
