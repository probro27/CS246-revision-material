#include "observer.h"
#include <iostream>

class Display: public Observer {
    double humidity;
    double temperature;

    public:
        Display(Subject<State, Info>* c): Observer{c} {}

        void notify() {
            Info of = c->getInfo();
            humidity = of.humidity;
            temperature = of.temperature;
        }

        friend std::ostream &operator<<(std::ostream &out, Display *td) {
            out << "Humidity: " << td->humidity << "\n";
            out << "Temperatur: " << td->temperature << "\n";
            return out;
        }
};
