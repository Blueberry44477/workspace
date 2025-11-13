#ifndef DATA_STRUCTURES_DOUBLELINKEDLIST_H
#define DATA_STRUCTURES_DOUBLELINKEDLIST_H

#include "../node/DoubleNode.h"
#include <ostream>
using namespace std;

class DoubleLinkedList {
private:
    shared_ptr<double_node::Node> head;
    shared_ptr<double_node::Node> tail;
    int size;
    void checkIndex(int index) const;
public:
    DoubleLinkedList() : head{nullptr}, tail{nullptr}, size{0} {};
    DoubleLinkedList(int value) : head{make_shared<double_node::Node>(value)}, tail{head}, size{1} {};
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAtIndex(int index, int value);
    int operator[](int index) const;
    void removeFromBeginning();
    void removeFromEnd();
    void removeAtIndex(int index);
    bool search(int value) const;
    int getSize() const;
    friend ostream &operator<<(ostream &os, DoubleLinkedList &obj);
};


#endif
