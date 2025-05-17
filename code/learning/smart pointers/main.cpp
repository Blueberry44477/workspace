#include <memory>
#include <iostream>
#include <vector>
int main() {
    std::unique_ptr<int> p1{new int{10}};
    std::cout << *p1 << '\n';
    std::cout << p1.get() << '\n';
    p1.reset();
    if(p1)
        std::cout << *p1 << '\n';    
    std::vector<std::unique_ptr<int>> vec;
    std::unique_ptr<int> p2{new int{20}};
    vec.push_back(std::move(p2));
    std::cout << vec.size();
    
    return 0;
}