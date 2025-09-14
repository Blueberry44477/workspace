#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

#include <memory>
#include <iostream>
#include "Generic_node.h"
using namespace generic_node;

//m_next легше вважати за m_previous
namespace Linked_list {
    template<typename T>
    class Stack {
    private:
        std::unique_ptr<Node<T>> m_top;
        size_t m_size;
    public:
        Stack(): m_top{nullptr}, m_size{} {};
        Stack(const T &data): m_top{std::make_unique<Node<T>>(data)}, m_size{1} {};
        
        bool is_empty() const {
            return m_top == nullptr;
        }

        void push (const T &data) {
            auto new_node = std::make_unique<Node<T>>(data);
            new_node->m_next = std::move(m_top);
            m_top = std::move(new_node);
            m_size++;
        }

        void pop() {
            if(is_empty())
                throw std::underflow_error("Stack is empty");
            m_top = std::move(m_top->m_next);
            m_size--;
        }

        T &peek() {
            if(is_empty())
                throw std::underflow_error("Stack is empty");
            return m_top->m_data;
        }

    };
}



#endif