#ifndef LINKED_LIST_OUTPUT_RESTRICTED_QUEUE_H
#define LINKED_LIST_OUTPUT_RESTRICTED_QUEUE_H

#include "Generic_node.h"

using namespace generic_node;
template<typename T>
class Linked_list_output_restricted_queue {
private:
    std::unique_ptr<Node<T>> m_head;
    Node<T> *m_tail; //не володіє пам'яттю
    size_t m_size{};
public:
    Linked_list_output_restricted_queue(): m_head{nullptr}, m_tail{nullptr}, m_size{} {}
    Linked_list_output_restricted_queue(const T &data)
        : m_head{std::make_unique<Node<T>>(data)}, m_tail{m_head.get()}, m_size{1} {}
    Linked_list_output_restricted_queue(const std::initializer_list<T> &init_list) {
        for (const auto &value : init_list) {
            auto new_node = std::make_unique<Node<T>>(value);
            if(!m_head) {
                m_head = std::move(new_node);
                m_tail = m_head.get();
            } else {
                m_tail->m_next = std::move(new_node);
                m_tail = m_tail->m_next.get();
            }
            m_size++;
        }
    }

    bool is_empty() {
        return m_head == nullptr;
    }

    const size_t size() const {
        return m_size;
    }

    void insert_front(const T &data) {
        auto new_node = std::make_unique<Node<T>>(data);
        if(is_empty()) {
            m_head = std::move(new_node);
        } else {
            new_node->m_next = std::move(new_node);
            m_head = std::move(new_node);
        }
        m_size++;
    }

    void insert_rear(const T &data) {
        auto new_node = std::make_unique<Node<T>>(data);
        if(!m_head) {
            m_head = std::move(new_node);
            m_tail = m_head.get();
        } else {
            m_tail->m_next = std::move(new_node);
            m_tail = m_tail->m_next.get();
        }
        m_size++;
    }

    void dequeue() {
        if (!m_head)
            throw std::runtime_error("Queue is empty");
        m_head = std::move(m_head->m_next);
        m_size--;
        if(!m_head)
            m_tail = nullptr;
    }

    T peek() const {
        if(!m_head)
            throw std::runtime_error("Queue is empty");
        return m_head->m_data;
    }

    friend std::ostream &operator<<(std::ostream &os, const Linked_list_output_restricted_queue &obj) {
        if(!obj.m_head)
            return os;
        auto current = obj.m_head.get();
        size_t i{};
        while(current) {
            os << '[' << i  << "] = " << current->m_data << '\n';
            current = current->m_next.get();
            i++;
        }
        return os;
    }
};

#endif