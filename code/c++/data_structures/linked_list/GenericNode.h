#ifndef DATA_STRUCTURES_GENERICNODE_H
#define DATA_STRUCTURES_GENERICNODE_H

#include <memory>

namespace generic_node {
    template<typename T>
    struct Node {
        T data;
        std::shared_ptr<Node<T>> next;

        Node(const T& value) : data{value}, next{nullptr} {};
    };
}

#endif
