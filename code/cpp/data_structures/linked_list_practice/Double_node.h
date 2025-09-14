#ifndef DOUBLE_NODE_H
#define DOUBLE_NODE_H

#include <memory>
namespace double_node{
    template<typename T>
    struct Node {
        std::weak_ptr<Node<T>> m_previous;
        T m_data;
        std::shared_ptr<Node<T>> m_next;
        Node(const T &value): m_data{value} {}
    };
}


#endif