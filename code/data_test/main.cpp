#include <iostream>
#include "Singly_linked_list.h"
template <typename T>
void get_data(const Singly_linked_list<T> &list) {
    std::cout << "Enter index\n";
    int index{};
    std::cin >> index;
    try {
        std::cout << list[index] << '\n';
    } catch (std::out_of_range &ex) {
        std::cerr << ex.what() << '\n';
    }
}


int main() {
    Singly_linked_list<std::string> list{"1", "2", "3", "4", "5"};
    try {
        list.remove_last();
    } catch (std::out_of_range &ex) {
        std::cerr << ex.what() << '\n';
    }
    std::cout << list;
    std::cout << list.search("3");
    std::cout << list.count("5");
    list.insert_at(1, "10");
    std::cout << list;
    std::cout << list.is_empty() << '\n';
    list.insert_at_end("3");
    list.which("3");
    return 0;
}