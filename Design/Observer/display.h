#include "observer.h"
#include "station.h"
#include <iostream>

class WeatherDisplay: public Observer {
    double humidity;
    double temperature;
    Station *s;
    public:
        WeatherDisplay(Station *s): s{s} {}

        void notify() {
            Info of = s->getInfo();
            humidity = of.humidity;
            temperature = of.temperature;
        }

        friend std::ostream &operator<<(std::ostream &out, WeatherDisplay *td) {
            out << "Humidity: " << td->humidity << "\n";
            out << "Temperatur: " << td->temperature << "\n";
            return out;
        }
};
