#include <memory>
#include <iostream>

using namespace std;

int main() {
    unique_ptr<int> i {make_unique<int>(5)};
    cout << i.get() << endl; // gives memory address
    cout << *i << endl; // gives the actual value
}
