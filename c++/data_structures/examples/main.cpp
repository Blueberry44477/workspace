#include "linked_list/SinglyLinkedList.h"
#include "linked_list/DoubleLinkedList.h"
#include "linked_list/CircularList.h"
#include "examples/ClassWithFile.h"

#include <iostream>

using namespace std;

class Account {
private:
    int data;
public:
    Account(int value) : data{value} {};

    friend bool operator<(Account &lhs, Account &rhs) { return lhs.data < rhs.data; };

    bool operator>(Account &rhs) const { return this->data > rhs.data; };

    bool operator!=(Account &rhs) const { return this->data != rhs.data; };

    bool operator==(Account &rhs) const { return this->data == rhs.data; };

    friend ostream &operator<<(ostream &os, const Account &obj) {
        os << "Account with balance: " << obj.data << endl;
        return os;
    }
};

void singlylist() {
    SinglyLinkedList list;
    cout << "Inserting 3 items at end " << endl;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    cout << list << endl;

    cout << "Inserting 4 items at beginning " << endl;
    list.insertAtBeginning(0);
    list.insertAtBeginning(-1);
    list.insertAtBeginning(-2);
    list.insertAtBeginning(-3);
    cout << list << endl;

    cout << "Removing from end: " << endl;
    list.removeFromEnd();
    cout << list << endl;

    cout << "Removing from beginning: " << endl;
    list.removeFromBeginning();
    cout << list << endl;

    cout << "Inserting at index 4 value 23" << endl;
    list.insertAtIndex(4, 23);
    cout << list << endl;

    cout << "Removing at index 2 " << endl;
    list.removeAtIndex(2);
    cout << list << endl;

    cout << "Item at position 3: " << list[3] << endl;
    cout << "Does value 23 exist? " << list.search(23) << endl;
    cout << "Size of list: " << list.getSize() << endl;
    cout << "Is list circular: " << list.isCircularList() << endl;
}

void doubleLinkList() {
    DoubleLinkedList list;
    cout << "Inserting 3 items at end " << endl;
    list.insertAtEnd(7);
    list.insertAtEnd(8);
    list.insertAtEnd(9);
    cout << list << endl;

    cout << "Inserting 4 items at beginning " << endl;
    list.insertAtBeginning(0);
    list.insertAtBeginning(-7);
    list.insertAtBeginning(-8);
    list.insertAtBeginning(-9);
    cout << list << endl;

    cout << "Removing from end: " << endl;
    list.removeFromEnd();
    cout << list << endl;

    cout << "Removing from beginning: " << endl;
    list.removeFromBeginning();
    cout << list << endl;

    cout << "Inserting at index 2 value 56" << endl;
    list.insertAtIndex(2, 56);
    cout << list << endl;

    cout << "Removing at index 1 " << endl;
    list.removeAtIndex(1);
    cout << list << endl;

    cout << "Item at position 4: " << list[4] << endl;
    cout << "Does value 56 exist? " << list.search(56) << endl;
    cout << "Size of list: " << list.getSize() << endl;
}

void circularList() {
    CircularList<int> list;
    cout << "Empty list" << endl;
    cout << list << endl;

    cout << "Inserting 3 items at the beginning" << endl;
    list.insertAtBeginning(2);
    list.insertAtBeginning(4);
    list.insertAtBeginning(3);
    cout << list << endl;

    cout << "Inserting 3 items at the end of the list " << endl;
    list.insertAtEnd(-4);
    list.insertAtEnd(-2);
    list.insertAtEnd(-3);
    cout << list << endl;

    cout << "Accessing 5'th item of the list" << endl;
    cout << "list[5]: " << list[5] << endl;

    cout << "Removing one item from the end of the list" << endl;
    list.removeFromEnd();
    cout << list << endl;

    cout << "Removing one item from the beginning of the list" << endl;
    list.removeFromBeginning();
    cout << list << endl;

    cout << "Sorted list " << endl;
    list.bubleSort();
    cout << list << endl;
    cout << "Is list circular: " << list.isCircularList() << endl;
}

void trickyExample() {
    CircularList<Account> listOfAccounts;
    listOfAccounts.insertAtEnd(Account(4));
    listOfAccounts.insertAtEnd(Account(2));
    listOfAccounts.insertAtEnd(Account(3));
    listOfAccounts.bubleSort();
    cout << listOfAccounts;
}

void filesExample() {
    std::string filename = "/tmp/test.bin";
    ClassWithFile obj(2, "qweqweqw");
    obj.writeToBinaryFile(filename);
    ClassWithFile obj2;
    obj2.readFromBinaryFile(filename);
    cout << obj2 << endl;

}

int main() {
//    singlylist();
//    doubleLinkList();
//    circularList();
//    trickyExample();
cout << "size of int:  " << sizeof(int) << endl;
    cout << "size of size_t:  " << sizeof(size_t) << endl;
    filesExample();
    return 0;
}
