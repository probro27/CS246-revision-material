#include "node.h"

using namespace std;

int main() {
    List l;
    l.addToFront(3);
    l.addToFront(5);
    l.printList();
    l.plusData(1);
    l.printList();
    return 0;
}
