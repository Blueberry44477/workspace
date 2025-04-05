#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "Generic_node.h"
#include <iostream>
using namespace generic_node;

template<typename T>
class Singly_linked_list {
private:
    std::unique_ptr<Node<T>> m_head;
    size_t m_size;
    void check_index(size_t index) const {
        if (index < 0 || index >= m_size)
            throw std::out_of_range("Index is out of range");
    };
public:
    Singly_linked_list(): m_head{nullptr}, m_size{} {};
    Singly_linked_list(const T value)
        :m_head{std::make_unique<Node<T>>(value)}, m_size{1} {};

    Singly_linked_list(const std::initializer_list<T> &init_list) {
        Node<T> *tail = nullptr;
        for (const auto &value : init_list) {
            auto new_node = std::make_unique<Node<T>>(value);
            if(!m_head) {
                m_head = std::move(new_node);
                tail = m_head.get();
            } else {
                tail->m_next = std::move(new_node);
                tail = tail->m_next.get();
            }
            m_size++;
        }
    }

    void insert_at_beginning(const T &value) {
        auto new_node = std::make_unique<Node<T>>(value);
        if(!m_head) {
            m_head = std::move(new_node);
            m_size++;
            return;
        }
        new_node->m_next = std::move(m_head);
        m_head = std::move(new_node);
        m_size++;
    }

    void insert_at_end(const T &value) {
        auto new_node = std::make_unique<Node<T>>(value);
        if (!m_head) { 
            m_head = std::move(new_node);
            m_size++;
            return;
        }
        Node<T> *current = m_head.get();
        while(current->m_next) {
            current = current->m_next.get();
        }
        current->m_next = std::move(new_node);
        m_size++;
    }

    void remove_first() {
        if (!m_head) {
            throw std::out_of_range("List is empty");
        }
        m_head = std::move(m_head->m_next);
        m_size--;
    }

    void remove_last() {
        if (!m_head) {
            throw std::out_of_range("List is empty");
        }
        if (m_size == 1) {
            m_head.reset();
            m_size--;
            return;
        }
        Node<T> *current = m_head.get();
        while (current->m_next->m_next)
            current = current->m_next.get();
        current->m_next.reset();
        m_size--;
    }

    const T& operator[](const int index) const {
        check_index(index);
        Node<T> *current = m_head.get();
        for (size_t i = 0; i < index; i++)
            current = current->m_next.get();
        return current->m_data;
    }
    
    void insert_at(const size_t index, const T &value) {
        check_index(index);
        if(index == 0) {
            insert_at_beginning(value);
            return;
        } else if (index == m_size - 1) {
            insert_at_end(value);
            return;
        } else {
            auto new_node = std::make_unique<Node<T>>(value);
            Node<T> *current = m_head.get();
            for(size_t i = 0; i < index - 1; i++) {
                current = current->m_next.get();
            }
            new_node->m_next = std::move(current->m_next);
            current->m_next = std::move(new_node);
            m_size++;
        }
    }

    void remove_at(const size_t index) {
        check_index(index);
        if(index == 0) {
            remove_first();
            return;
        } else if (index == m_size - 1) {
            remove_last();
            return;
        }
        Node<T> *current = m_head.get();
        for (size_t i = 0; i < index - 1; i++)
            current = current->m_next.get();
        current->m_next = std::move(current->m_next->m_next);
        m_size--;
    }

    bool search(const T &value) {
        auto current = m_head.get();
        while (current) {
            if(current->m_data == value)
                return true;
            current = current->m_next.get();
        }
        return false;
    }

    void which(const T &value) {
        auto current = m_head.get();
        size_t index{};
        while(current) {
            if(current->m_data == value) {
                std::cout << "[" << index << "] = " << value << '\n';
            }
            current = current->m_next.get();
            index++;
        }
    }

    bool is_empty() {
       return m_head == nullptr;
    }

    const size_t size() const {
        return m_size;
    }

    friend std::ostream &operator<<(std::ostream &os, const Singly_linked_list &obj) {
        if(!obj.m_head)
            return os;
        Node<T> *current = obj.m_head.get();
        std::cout << "List data:\n";
        size_t i{};
        while (current != nullptr) {
            os << '[' << i  << "] = " << current->m_data << '\n';
            current = current->m_next.get();
            i++;
        }
        return os;
    }

    size_t count(const T& value) const {
    size_t counter = 0;
    auto current = m_head.get();
    while (current) {
        if (current->m_data == value) {
            counter++;
        }
        current = current->m_next.get();
    }
    return counter;
    }
};


#endif