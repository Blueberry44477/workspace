#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <memory>
#include <stdexcept>
#include "Double_node.h"

template <typename T>
class Doubly_linked_list{
private:
    std::shared_ptr<double_node::Node<T>> m_head;
    std::shared_ptr<double_node::Node<T>> m_tail;
    size_t m_size;
    void check_index(const size_t index) const {
        if (index < 0 || index > m_size)
            throw std::out_of_range("Index is out of range");
    };
public:
    Doubly_linked_list(): m_head{nullptr}, m_tail{nullptr}, m_size{0} {}
    Doubly_linked_list(const T &value)
        : m_head{std::make_shared<double_node::Node<T>>(value)}, m_tail{m_head}, m_size{1} {}

    void insert_at_beginning(const T &value) {
        auto new_node = std::make_shared<double_node::Node<T>>(value);
        if (!m_head) {
            m_head = m_tail = new_node;
        } else {
            new_node->m_next = m_head;
            m_head->m_previous = new_node;
            m_head = new_node;
        }
        m_size++;
    }
    
    void insert_at_end(const T &value) {
        auto new_node = std::make_shared<double_node::Node<T>>(value);
        if(!m_tail) {
            m_head = m_tail = new_node;
        } else {
            m_tail->m_next = new_node;
            new_node->m_previous = m_tail;
            m_tail = new_node;
        }
        m_size++;
    }

    void remove_first() {
        if (!m_head)
            return;
        if (m_head == m_tail) {
            m_head = m_tail = nullptr;
        } else {
            m_head = m_head->m_next;
            m_head->m_previous.reset();
        }
        m_size--;
    }

    void remove_last() {
        if (!m_tail)
            return;
        if (m_head == m_tail){
            m_head = m_tail = nullptr;
        } else {
            m_tail = m_tail->m_previous.lock();
            m_tail->m_next = nullptr;
        }
        m_size--;
    }

    void insert_at(const size_t index, const T &value) {
        check_index(index);
        if (index == 0) {
            insert_at_beginning(value);
            return;
        } else if (index == m_size - 1) {
            insert_at_end(value);
            return;
        }
        auto new_node = std::make_shared<double_node::Node<T>>(value);
        auto current = m_head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->m_next;
        }
        new_node->m_next = current->m_next;
        new_node->m_previous = current;
        current->m_next->m_previous = new_node;
        current->m_next = new_node;
        m_size++;
    }

    void remove_at(const size_t index) {
        if (index == 0) {
            remove_first();
            return;
        } else if (index == m_size - 1) {
            remove_last();
            return;
        } else {
            auto current = m_head;
            for (size_t i = 0; i < index; i++) {
                current = current->m_next;
            }
            current->m_previous.lock()->m_next = current->m_next;
            current->m_next->m_previous = current->m_previous;
        }
        m_size--;

    }

    const T& operator[](const size_t index) const{
        check_index(index);
        std::shared_ptr<double_node::Node<T>> current = m_head;
        for(size_t i = 0; i < index; i++) {
            current = current->m_next;
        }
        return current->m_data;
    }

    const size_t size() const {
        return m_size;
    }

    friend std::ostream &operator<<(std::ostream &os, const Doubly_linked_list &obj) {
        auto current = obj.m_head;
        size_t i{};
        while(current) {
            os << "[" << i << "] = " << current->m_data << '\n';
            current = current->m_next;
            i++;
        }
        return os;
    }

    bool search(const size_t value) const {
    auto current = m_head;
    while (current) {
        if (current->m_data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
    }
};

#endif