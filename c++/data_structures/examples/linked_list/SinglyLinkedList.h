#ifndef DATA_STRUCTURES_SINGLYLINKEDLIST_H
#define DATA_STRUCTURES_SINGLYLINKEDLIST_H

#include "../node/SingleNode.h"
#include <iostream>
using namespace std;
using namespace single_node;

class SinglyLinkedList {
private:
    unique_ptr<Node> head;
    int size;
    void checkIndex(int index) const;
public:
    SinglyLinkedList() : head{nullptr}, size{0} {};
    SinglyLinkedList(int value) : head{make_unique<Node>(value)}, size{1} {};
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAtIndex(int index, int value);
    int operator[](int index) const;
    void removeFromBeginning();
    void removeFromEnd();
    void removeAtIndex(int index);
    bool search(int value) const;
    int getSize() const;
    friend ostream &operator<<(ostream &os, SinglyLinkedList &obj);
    bool isCircularList();
};


#endif
