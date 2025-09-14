#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include <iostream>
template<typename T, size_t capacity>
class Array_queue {
private:
    T m_data[capacity];
    size_t m_head; //індекс першого елементу
    size_t m_tail; //доступне місце після останнього елементу
    size_t m_size;
public:
    Array_queue(): m_data{}, m_head{}, m_tail{}, m_size{} {};
    Array_queue(const T &data): m_head{}, m_tail{1}, m_size{1} {
        m_data[0] = data;
    }
    bool is_empty() const {return m_size == 0;}
    bool is_full() const {return m_size == capacity;}
    size_t size() const {return m_size;}

    void enqueue(const T &data) {
        if(is_full())
            throw std::overflow_error("Queue is full");
        m_data[m_tail] = data;
        m_tail = (m_tail + 1) % capacity;
        m_size++;
    }

    void dequeue() {
        if(is_empty())
            throw std::underflow_error("Queue is empty");
        m_head = (m_head + 1) % capacity;
        m_size--;
    }

    T &peek() {
        if(is_empty()) 
            throw std::underflow_error("Queue is empty");
        return m_data[m_head];
    }

    friend std::ostream &operator<<(std::ostream &os, const Array_queue &obj) {
        if(obj.is_empty())
            return os;
        size_t current = obj.m_head;
        os << '[';
        for(size_t i = 0; i < obj.m_size; i++) {
            os << obj.m_data[current];
            if(i < obj.m_size - 1)
                os << ", ";
            current = (current + 1) % capacity;
        }
        os << ']';
        return os;
    }
};

#endif