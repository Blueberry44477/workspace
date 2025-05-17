#ifndef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE

#include "Circular_node.h"
#include <memory>
#include <iostream>
#include <stdexcept>

template<typename T>
class Circular_queue {
private:
    std::shared_ptr<circular_node::Node<T>> m_head;
    std::shared_ptr<circular_node::Node<T>> m_tail;
    size_t m_size;
    void check_index(const size_t index) const {
        if(index < 0 || index > m_size)
            throw std::out_of_range("Index is out of range");
    }
public:
    Circular_queue(): m_head{nullptr}, m_tail{nullptr}, m_size{} {};
    Circular_queue(const T &data): m_head{std::make_shared<circular_node::Node<T>>(data)}, m_tail{m_head}, m_size{1} {};
    bool is_empty() const {
        return !m_head;
    }
    size_t size() const {
        return m_size;
    }
    void enqueue(const T &data) {
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
    void dequeue() {
        if(is_empty())
            throw std::underflow_error("Queue is empty");
        if(m_head == m_tail) {
            m_head = m_tail = nullptr;
        } else {
            m_head = m_head->m_next;
            m_tail->m_next = m_head;
        }
        m_size--;
    }
    T &peek() {
        if(is_empty())
            throw std::underflow_error("Queue is empty");
        return m_head->m_data;
    }
    friend std::ostream &operator<<(std::ostream &os, const Circular_queue &obj) {
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
