#ifndef _STATION_H
#define _STATION_H

#include "subject.h"
#include "state.h"
#include "info.h"

class Station: public Subject<State, Info> {
    double temprature;
    double humidity;
    void calculateTemp();
    void calculateHumidity();
    public:
        void changeData();
};

#endif
