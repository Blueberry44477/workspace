#ifndef CIRCULAR_LINKED_LIST
#define CIRCULAR_LINKED_LIST

#include "Circular_node.h"
#include <memory>
#include <iostream>
#include <stdexcept>

template<typename T>
class Circular_list {
private:
    std::shared_ptr<circular_node::Node<T>> m_head;
    std::shared_ptr<circular_node::Node<T>> m_tail;
    size_t m_size;
    void check_index(const size_t index) const {
        if(index < 0 || index > m_size)
            throw std::out_of_range("Index is out of range");
    }
public:
    Circular_list(): m_head{nullptr}, m_tail{nullptr}, m_size{} {};
    Circular_list(const T &data): m_head{std::make_shared<circular_node::Node<T>>(data)}, m_tail{m_head}, m_size{1} {};
    bool is_empty() const {
        return !m_head;
    }
    size_t size() const {
        return m_size;
    }
    void insert_at_beginning(const T &data) {
        auto new_node = std::make_shared<circular_node::Node<T>>(data);
        if(is_empty()) {
            m_head = new_node;
            m_head->m_next = m_head;
            m_tail = m_head;
        } else {
            new_node->m_next = m_head;
            m_head = new_node;
            m_tail->m_next = m_head;
        }
        m_size++;
    }
    void insert_at_end(const T &data) {
        auto new_node = std::make_shared<circular_node::Node<T>>(data);
        if(is_empty()) {
            m_head = new_node;
            m_tail = m_head;
            m_head->m_next = m_head;
        } else {
            m_tail->m_next = new_node;
            m_tail = new_node;
            m_tail->m_next = m_head;
        }
        m_size++;
    }
    void insert_at(const size_t index, const T &data) {
        check_index(index);
        if(index == 0) {
            insert_at_beginning(data);
        } else if (index == m_size - 1) {
            insert_at_end(data);
        } else {
            auto new_node = std::make_shared<circular_node::Node<T>>(data);
            auto current = m_head;
            for (size_t i = 0; i < m_size-1; i++)
                current = current->m_next;
            new_node->m_next = current->m_next;
            current->m_next = new_node;
            m_size++;
        }
    }
    void remove_first() {
        if(is_empty())
            throw std::underflow_error("List is empty");
        if(m_head == m_tail) {
            m_head = m_tail = nullptr;
        } else {
            m_head = m_head->m_next;
            m_tail->m_next = m_head;
        }
        m_size--;
    }
    void remove_last() {
        if(is_empty())
            throw std::underflow_error("List is empty");
        if(m_head == m_tail) {
            m_head = m_tail = nullptr;
        } else {
            auto current = m_head;
            while(current->m_next != m_tail) { //передостанній елемент(що вказує на хвіст)
                current = current->m_next;
            }
            current->m_next = m_head; //замкнули
            m_tail = current;
        }
        m_size--;
    }
    void remove_at(const size_t index) {
        if(is_empty())
            throw std::underflow_error("List is empty");
        check_index(index);
        if(index == 0) {
            remove_first();
        } else if (index == m_size - 1) {
            remove_last();
        } else {
            auto current = m_head;
            for (size_t i = 0; i < index; i++) //отримали list[index-1]
                current = current->m_next;
            current->m_next=current->m_next->m_next;
            m_size--;
        }

    }
    friend std::ostream &operator<<(std::ostream &os, const Circular_list &obj) {
        auto current = obj.m_head;
        size_t i{};
        do {
            os << "[" << i << "] = " << current->m_data << '\n';
            current = current->m_next;
            i++;
        } while(current!=obj.m_head);
        return os;
    }

    
};


#endif
