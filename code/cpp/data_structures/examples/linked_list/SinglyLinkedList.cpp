#include "SinglyLinkedList.h"

//SinglyLinkedList::~SinglyLinkedList() {
//    Node *current = head;
//    while (current != nullptr) {
//        Node *next = current->next;
//        delete current;
//        current = next;
//    }
//    head = nullptr;
//}

void SinglyLinkedList::checkIndex(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
}

void SinglyLinkedList::insertAtBeginning(int value) {
    unique_ptr<Node> newNode = make_unique<Node>(value);
    newNode->next = std::move(head);
    head = std::move(newNode);
    size++;
}

void SinglyLinkedList::insertAtEnd(int value) {
    unique_ptr<Node> newNode = make_unique<Node>(value);
    Node *current = head.get();
    if (!current) {
        head = std::move(newNode);
        size++;
        return;
    }
    while (current->next) {
        current = current->next.get();
    }
    current->next = std::move(newNode);
    size++;
}

ostream &operator<<(ostream &os, SinglyLinkedList &obj) {
    Node *current = obj.head.get();
    os << "List data: " << endl;
    while (current != nullptr) {
        os << current->data << " ";
        current = current->next.get();
    }
    os << endl;
    return os;
}

void SinglyLinkedList::insertAtIndex(int index, int value) {
    checkIndex(index);

    if (index == 0) {
        insertAtBeginning(value);
        return;
    } else if (index == size) {
        insertAtEnd(value);
        return;
    } else {
        unique_ptr<Node> newNode = make_unique<Node>(value);
        Node *current = head.get();
        for (int i = 0; i < index - 1; i++) {
            current = current->next.get();
        }
        newNode->next = std::move(current->next);
        current->next = std::move(newNode);
        size++;
    }
}

int SinglyLinkedList::operator[](int index) const {
    checkIndex(index);
    Node *current = head.get();
    for (int i = 0; i < index; i++) {
        current = current->next.get();
    }
    return current->data;
}

void SinglyLinkedList::removeFromBeginning() {
    if (!head) {
        throw std::out_of_range("List is empty!");
    }
    head = std::move(head->next);
    --size;
}

void SinglyLinkedList::removeFromEnd() {
    if (!head) {
        throw std::out_of_range("List is empty!");
    }
    if (size == 1) {
        head.reset();
        --size;
        return;
    }
    Node *current = head.get();
    while (current->next->next) {
        current = current->next.get();
    }
    current->next.reset();
    --size;
}

void SinglyLinkedList::removeAtIndex(int index) {
    checkIndex(index);
    if (index == 0) {
        removeFromBeginning();
        return;
    } else if (index == size - 1) {
        removeFromEnd();
        return;
    }

    Node *current = head.get();
    for (int i = 0; i < index - 1; i++) {
        current = current->next.get();
    }
    current->next = std::move(current->next->next);
    --size;

}

bool SinglyLinkedList::search(int value) const {
    Node *current = head.get();
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next.get();
    }
    return false;
}

int SinglyLinkedList::getSize() const {
    return size;
}

bool SinglyLinkedList::isCircularList() {
    if (!head) {
        return false;
    }
    Node* slow = head.get();
    Node* fast = head.get();
    while (fast && fast->next) {
        slow = slow->next.get();
        fast = fast->next->next.get();
        if (slow == fast) {
            return true;
        }
    }
    return false;
}