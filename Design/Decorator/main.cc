#include "add.h"
#include "subtract.h"
#include "multiply.h"
#include "divide.h"
#include "basefunc.h"
#include <iostream>

using namespace std;

int main() {
    Sequence *sq = new BaseFunc(0);
    char command;
    bool ended = false;
    while(cin >> command) {
        
        int newVal = 0;
        switch(command) {
            case 's':
                cin >> newVal;
                sq->setValue(newVal);
                break;
            case 'n':
                sq->updatePrint();
                cout << sq->getValue() << endl;
                break;
            case '+':
                cin >> newVal;
                sq = new AddDecorator{sq, newVal};
                break;
            case '-':
                cin >> newVal;
                sq = new SubDecorator{sq, newVal};
                break;
            case '*':
                cin >> newVal;
                sq = new MultDecorator{sq, newVal};
                break;
            case '/':
                cin >> newVal;
                sq = new DivDecorator{sq, newVal};
                break;
            default:
                ended = true;
                break;
        }
        if(ended) {
            break;
        }
    }
    return 0;
}
