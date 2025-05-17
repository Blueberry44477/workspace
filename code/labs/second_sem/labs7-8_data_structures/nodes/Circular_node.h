#ifndef CIRCULAR_NODE_H
#define CIRCULAR_NODE_H

#include <memory>

namespace circular_node {
    template<typename T>
    struct Node {
        T m_data;
        std::shared_ptr<Node<T>> m_next;
        Node(const T& value) : m_data{value}, m_next{nullptr} {};
    };
}

#endif