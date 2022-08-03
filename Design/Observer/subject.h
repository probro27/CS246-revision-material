#ifndef _SUBJECT_H
#define _SUBJECT_H

#include <iostream>
#include <vector>
#include "observer.h"

template<typename StateType, typename InfoType>
class Subject {
    std::vector<Observer *> ob;
    StateType state;
    InfoType info;
    protected:
        void setState(StateType s) {
            state = s;
        }
    public:
        StateType getState() const {
            return state;
        }
        InfoType getInfo() const {
            return info;
        }

        void setInfo(Info in) {
            info = in;
        }
        void attach(Observer *observer) {
            ob.emplace_back(observer);
        }
        void detatch(Observer *observer) {
            auto it = find(ob.begin(), ob.end(), observer);
            if(it != ob.end()) {
                ob.erase(it);
            }
        }
        void notifyObservers() {
            for(auto &observer: ob) {
                observer->notify();
            }
        }
};

#endif
