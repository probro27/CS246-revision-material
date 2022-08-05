#include "node.h"

using namespace std;

Node operator*(const Node &n, int k) {
    Node temp{n};
    temp.data = n.data * k;
    Node *curr = n.next;
    Node *tempCurr = temp.next;
    while(curr) {
        tempCurr->data = curr->data * k;
        curr = curr->next;
        tempCurr = tempCurr->next;
    }
    return temp;
}

Node operator*(int k, const Node &n) {
    return n * k;
}
w
