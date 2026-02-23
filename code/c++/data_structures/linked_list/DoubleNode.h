#ifndef DATA_STRUCTURES_DOUBLENODE_H
#define DATA_STRUCTURES_DOUBLENODE_H

#include <memory>

namespace double_node {
    struct Node {
        int data;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> previous;

        Node(int value) : data{value} {}
    };
}


#endif
