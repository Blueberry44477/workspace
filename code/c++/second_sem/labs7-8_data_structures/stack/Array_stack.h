#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
#include <iostream>
namespace Array {
    template<typename T, size_t capacity>
    class Stack {
    private:
        T m_data[capacity];
        size_t m_top; //вказує на місце після верхнього елементу
    public:
        Stack(): m_data{}, m_top{} {}
        Stack(const T &data): m_top{1} {
            m_data[0] = data;
        }
        bool is_empty() const {return m_top == 0;}
        bool is_full() const {return m_top == capacity;}
        size_t size() const {return m_top;}
        void push(const T &data) {
            if(is_full())
                throw std::overflow_error("Stack is full");
            m_data[m_top] = data;
            m_top++;
        }
        void pop() {
            if(is_empty()) 
                throw std::underflow_error("Stack is empty");
            m_top--;
        }
        T &peek() {
            if(is_empty()) 
                throw std::underflow_error("Stack is empty");
            return m_data[m_top - 1];
        }
    };
}
#endif