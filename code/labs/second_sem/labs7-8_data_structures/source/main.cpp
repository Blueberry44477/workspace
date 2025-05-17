#include <iostream>
#include "Singly_linked_list.h"
#include "Doubly_linked_list.h"
#include "Linked_list_queue.h"
#include "Circular_list_queue.h"
#include "Linked_list_stack.h"
#include "Circular_linked_list.h"
#include "Linked_list_input_restricted_queue.h"
#include "Linked_list_output_restricted_queue.h"
#include "Array_stack.h"
#include "Array_queue.h"
#include "Array_output_restricred_queue.h"
#include "Array_input_restricted_queue.h"

int main() {
    Linked_list_queue<std::string> queue{"Hello", "Goodbye"};
    queue.enqueue("Bye");
    std::cout << queue;
    std::string str = queue.peek();
    std::cout << str << '\n';

    // Circular_list_queue<std::string> queue{};
    // queue.enqueue("hello");
    // std::cout << queue;

    // Linked_list::Stack<std::string> stack("one");
    // stack.push("two");
    // stack.push("three");
    // stack.push("four");
    // stack.pop();
    // std::cout << stack.peek() << '\n';

    // Array::Stack<int, 5> arr_stack(0);
    // arr_stack.push(1);
    // arr_stack.push(2);
    // arr_stack.push(3);
    // arr_stack.push(4);
    // std::cout << arr_stack.peek() << '\n';
    // std::cout << arr_stack.size() << '\n';

    // Array_queue<int, 5> queue(1);
    // queue.enqueue(2);
    // queue.enqueue(3);
    // queue.enqueue(4);
    // std::cout << queue;
    // queue.dequeue();
    // std::cout << queue;

    // Circular_list list(1);
    // list.insert_at_beginning(2);
    // list.insert_at_end(3);
    // std::cout << list;
    // list.remove_first();
    // std::cout << '\n' << list;
    // std::cout << list.size();
    // list.remove_at(1);
    // std::cout << list;

    // Circular_queue queue(5);
    // queue.enqueue(6);
    // queue.dequeue();
    // std::cout << queue;
    
    // Array_output_restricted_queue<int,5> queue(5);
    // queue.insert_front(6);
    // queue.insert_rear(7);
    // std::cout << queue << '\n';
    // queue.dequeue();
    // std::cout << queue.peek();

    // Array_input_restricted_queue<int,5> queue(5);
    // queue.enqueue(6);
    // queue.enqueue(7);
    // queue.enqueue(8);
    // std::cout << queue << '\n';
    // queue.dequeue_front();
    // queue.dequeue_rear();
    // std::cout << queue << '\n';

    // Linked_list_input_restricted_queue<int> queue{1,2,3};
    // std::cout << queue << queue.size();
    // queue.enqueue(4);
    // std::cout << queue;

    // Singly_linked_list<int> list{1,2,3};
    // std::cout << list << list.size();

    return 0;
}