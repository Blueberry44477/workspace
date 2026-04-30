#include "DoubleLinkedList.h"

void DoubleLinkedList::checkIndex(int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Failed to access element. Index out of range!");
    }
}

void DoubleLinkedList::insertAtBeginning(int value) {
    shared_ptr<double_node::Node> newNode = make_shared<double_node::Node>(value);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
    ++size;
}

void DoubleLinkedList::insertAtEnd(int value) {
    shared_ptr<double_node::Node> newNode = make_shared<double_node::Node>(value);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    ++size;
}

void DoubleLinkedList::insertAtIndex(int index, int value) {
    checkIndex(index);
    if (index == 0) {
        insertAtBeginning(value);
    }
    if (index == size) {
        insertAtEnd(value);
    }
    shared_ptr<double_node::Node> newNode = make_shared<double_node::Node>(value);
    shared_ptr<double_node::Node> current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    newNode->previous = current;
    current->next->previous = newNode;
    current->next = newNode;
    ++size;
}

int DoubleLinkedList::operator[](int index) const {
    checkIndex(index);
    shared_ptr<double_node::Node> current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    return current->data;
}

void DoubleLinkedList::removeFromBeginning() {
    if (!head) {
        return;
    }
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->previous.reset();
    }
    --size;
}

void DoubleLinkedList::removeFromEnd() {
    if (!tail) {
        return;
    }
    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->previous.lock();
        tail->next = nullptr;
    }
    --size;
}

void DoubleLinkedList::removeAtIndex(int index) {
    checkIndex(index);
    if (index == 0) {
        head = head->next;
        if (head) {
            head->previous.reset();
        } else {
            tail.reset();
        }
    } else if (index == size - 1) {
        tail = tail->previous.lock();
        tail->next.reset();
    } else {
        shared_ptr<double_node::Node> current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->previous.lock()->next = current->next;
        current->next->previous = current->previous;
    }
    --size;
}

bool DoubleLinkedList::search(int value) const {
    shared_ptr<double_node::Node> current = head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int DoubleLinkedList::getSize() const {
    return size;
}

ostream &operator<<(ostream &os, DoubleLinkedList &obj) {
    os << "List data: " << endl;
    shared_ptr<double_node::Node> current = obj.head;
    while (current) {
        os << current->data << " ";
        current = current->next;
    }
    os << endl;
    return os;
}
