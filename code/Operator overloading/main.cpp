#include <iostream>
#include <cstring>
class Smth {
private:
    char *m_data;
public:
    Smth(const char *data) {
        if(data) {
            m_data = new char[strlen(data) + 1];
            std::strcpy(m_data, data);
        } else {
            m_data = nullptr;
        }
    }
    Smth(const Smth &other) {
        if (other.m_data) {
            m_data = new char[strlen(other.m_data) + 1];
            strcpy(m_data, other.m_data);
        } else {
            m_data = nullptr;
        }
    }
    ~Smth() { delete[] m_data; }
    const int get_length() const { return strlen(m_data); }
    const char *get_data() const { return m_data; }
    Smth operator+() const { return *this; }
    Smth &operator=(const Smth &rhs) {
        if(this == &rhs) 
            return *this;
        delete[] this->m_data;
        m_data = new char[strlen(rhs.m_data) + 1];
        std::strcpy(this->m_data, rhs.m_data);
        return *this;
    }
    bool operator==(const Smth &rhs) const {
        if(std::strcmp(this->m_data, rhs.m_data))
            return true;
        return false;
    }
    Smth operator+(const Smth &rhs) const {
        size_t buff_size = std::strlen(this->m_data) + std::strlen(rhs.m_data) + 1;
        char *buff = new char[buff_size];
        std::strcpy(buff, this->m_data);
        std::strcat(buff, rhs.m_data);
        Smth temp{buff};
        delete[] buff;
        return temp;
    }
    friend std::ostream &operator<<(std::ostream &os, const Smth &obj) {
        os << obj.m_data;
        return os;
    }
    friend std::istream &operator>>(std::istream &is, Smth &obj) {
        char *buff = new char[1000];
        is >> buff;
        obj = Smth{buff};
        delete[] buff;
        return is;
    }
};
class Num{
private:
    int number;
public:

};
int main() {
    Smth str{"Hello"};
    Smth str2{str};
    std::cout << str.get_data() << '\n';
    Smth str3{"Bye"};
    str2 = str3;
    std::cout << str2.get_data() << '\n';
    
    return 0;
}