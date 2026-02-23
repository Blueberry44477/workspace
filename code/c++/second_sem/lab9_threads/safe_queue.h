#ifndef SAFE_QUEUE_H
#define SAFE_QUEUE_H

#include <condition_variable>
#include <mutex>
#include <queue>
template<typename T>
class Safe_queue {
private:
    std::queue<T> m_queue;
    std::mutex mtx;
    std::condition_variable not_full;
    std::condition_variable not_empty;
    size_t m_capacity;
public:
    Safe_queue(const size_t max_size): m_capacity{max_size} {}
    void enqueue(const T& data) {
        std::unique_lock<std::mutex> lock(mtx);
        not_full.wait(lock, [this]() {return m_queue.size() < m_capacity; });
        m_queue.push(data);
        not_empty.notify_one();
    }
    T dequeue() {
        std::unique_lock<std::mutex> lock(mtx);
        not_empty.wait(lock, [this]() { return !m_queue.empty(); });
        T data{m_queue.front()};
        m_queue.pop();
        not_full.notify_one();
        return data;
    }
};

#endif