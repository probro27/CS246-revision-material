#include <memory>
#include <iostream>

class List {
    class Node {
        int _data;
        std::shared_ptr<Node> _next;

    public:
        Node(int data): _data{data}, _next{nullptr} {}

        Node(int data, std::shared_ptr<Node> next): _data{data}, _next{next} {}

        friend class List;

    };
    std::shared_ptr<Node> theList;
public:

    void addToFront(int n) {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(n, theList);
        theList = newNode;
    }
    
    void plusData(int n) {
        std::shared_ptr<Node> list = theList;
        while(list != nullptr) {
            list->_data = list->_data + n;
            list = list->_next;
        }
    }

    void printList() {
        std::shared_ptr<Node> list = theList;

        while(list != nullptr) {
            std::cout << list->_data << std::endl;
            list = list->_next;
        }
    }
};
