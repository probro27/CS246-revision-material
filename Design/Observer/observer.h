#ifndef _OBSERVER_H
#define _OBSERVER_H

#include "subject.h"
#include "info.h"
#include "state.h"

class Observer {
    protected:
        Subject<State, Info>* c;
    public:
        Observer(Subject<State, Info> *c): c{c} {}
        virtual void notify() = 0;
};

#endif
