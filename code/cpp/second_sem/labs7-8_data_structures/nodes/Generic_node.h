#ifndef GENERIC_NODE_H
#define GENERIC_NODE_H

#include <memory>

namespace generic_node {
    template<typename T>
    struct Node {
        T m_data;
        std::unique_ptr<Node<T>> m_next;

        Node(const T& value) : m_data{value}, m_next{nullptr} {};
        Node(T&& value): m_data{std::move(value)}, m_next{nullptr} {};
    };
}

#endif