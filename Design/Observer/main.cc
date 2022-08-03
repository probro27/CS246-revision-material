#include <iostream>
#include "display.h"

using namespace std;

int main() {
    Station* s = new Station();
    WeatherDisplay *d = new WeatherDisplay{s};
    s->attach(d);
    s->changeData();
    cout << d;
    s->changeData();
    cout << d;
    return 0;
    delete d;
    delete s;
}
