#include "matrix.h"

using namespace std;

int main() {

    Matrix<int> m;
    m.resize(3, 3);
    int value = 1;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            m.set(i, j, value);
            ++value;
        }
    }

    cout << m + 3 << endl;

    Matrix<int> n = m + 3;

    for(auto it = m.begin(); it != m.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}
