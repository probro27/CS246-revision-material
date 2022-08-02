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
