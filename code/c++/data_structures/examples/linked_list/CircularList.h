#ifndef DATA_STRUCTURES_CIRCULARLIST_H
#define DATA_STRUCTURES_CIRCULARLIST_H

#include "../node/GenericNode.h"
#include <memory>
#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class CircularList {
private:
    std::shared_ptr<generic_node::Node<T>> head;
    int size;
public:
    CircularList() : head{nullptr}, size{0} {}

    CircularList(const T &value) : head{make_shared<>(value)}, size{1} {}

    void insertAtBeginning(const T &value) {
        shared_ptr<generic_node::Node<T>> newNode = make_shared<generic_node::Node<T>>(value);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            newNode->next = head->next;
        }
        ++size;
    }

    void insertAtEnd(const T &value) {
        shared_ptr<generic_node::Node<T>> newNode = make_shared<generic_node::Node<T>>(value);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            newNode->next = head->next;
            head->next = newNode;
            head = newNode;
        }
        ++size;
    }

    void removeFromBeginning() {
        if (!head) {
            return;
        }
        if (head->next == head) {
            head.reset();
        }
        --size;
    }

    void removeFromEnd() {
        if (!head) {
            return;
        }
        std::shared_ptr<generic_node::Node<T>> current = head;
        while (current->next != head) {
            current = current->next;
        }
        if (current == head) {
            head.reset();
        } else {
            current->next = head->next;
            head = current;
        }
        --size;
    }

    friend ostream &operator<<(ostream &os, const CircularList<T> &obj) {
        if (!obj.head) {
            return os;
        }
        std::shared_ptr<generic_node::Node<T>> current = obj.head;
        os << "List data: " << endl;
        do {
            os << current->data << " ";
            current = current->next;
        } while (current != obj.head);
        os << endl;
        return os;
    }

    T operator[](int index) const {
        if (index < 0 || index > size) {
            throw out_of_range("Failed to access element. Index out of range!");
        }

        std::shared_ptr<generic_node::Node<T>> current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        return current->data;
    }

    int getSize() const { return size; }

    void bubleSort() {
        if (!head || !head->next) {
            return; // List is empty or has only one element, already sorted
        }

        bool swapped;
        std::shared_ptr<generic_node::Node<T>> current;

        do {
            swapped = false;
            current = head;
            do {
                if (current->data > current->next->data) {
                    std::swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            } while (current->next != head);
        } while (swapped);
    }

    bool isCircularList() {
        if (!head) {
            return false;
        }
        shared_ptr<generic_node::Node<T>> slow = head;
        shared_ptr<generic_node::Node<T>> fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};


#endif
