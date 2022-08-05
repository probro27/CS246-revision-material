#ifndef _NODE_H_
#define _NODE_H_

#include <utility>

struct Node {
    int data;
    Node *next;
    swap(Node &other) noexcept {
        using std::swap;
        swap(data, other.data);
        swap(next, other.next);
    }
    Node(int data, Node *next): data{data}, next{next} {}
    Node(const Node &other): data{other.data}, next{ other.next? new Node{other.next}: nullptr} {}
    Node &operator=(const Node &other) {
        Node temp {other};
        this->swap(temp);
        return *this;
    }
};

Node operator*(const Node &n, int k);
Node operator*(int k, const Node &n);

#endif
