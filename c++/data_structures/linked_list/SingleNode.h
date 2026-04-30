
#ifndef DATA_STRUCTURES_SINGLENODE_H
#define DATA_STRUCTURES_SINGLENODE_H

#include <memory>

namespace single_node {
    struct Node {
        int data;
        std::unique_ptr<Node> next;
        Node(int value) : data{value}, next{nullptr} {};
    };
}


#endif
