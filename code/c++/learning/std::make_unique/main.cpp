#include <iostream>
#include <memory>
#include <array>
class Item {
private:
    int m_num;
public:
    Item(int num = 0): m_num{num} {}
};

int main () {
    std::unique_ptr<int[]> arr = std::make_unique<int[]>(5);
    for (int i = 0; i < 5; i++)
        std::cout << arr[i] << '\n';

    std::shared_ptr<
    return 0;
}