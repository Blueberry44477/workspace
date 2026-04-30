#include <iostream>
#include <vector>
class Something {
private:
    int *m_data;
public:
    Something(int data): m_data{new int(data)} {}
    Something(const Something &other): m_data{new int(*other.m_data)} {}
    Something(Something &&other) noexcept: m_data {other.m_data} {
        other.m_data = nullptr;
        std::cout << "Move constructor\n";
    }
    ~Something() { delete m_data; }
    int get_value() { return *m_data; }
};
int main() {
    Something smth1(5);
    Something smth2{smth1};
    Something smth3 = std::move(smth1);
    std::cout << smth2.get_value() << '\n';
    std::cout << smth3.get_value() << '\n';
    std::vector<Something> vec;
    vec.push_back(Something{5});
    return 0;
}