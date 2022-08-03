#include "station.h"

using namespace std;

void Station::calculateHumidity() {
    humidity = humidity + 1;
}

void Station::calculateTemp() {
    temprature = temprature + 1;    
}

void Station::changeData() {
    calculateHumidity();
    calculateTemp();
    Info in = Info{humidity, temprature};
    this->setInfo(in);
    notifyObservers();
}
