#include <iostream>
#include <thread>
#include <cmath>
#include <mutex>
#include <chrono>
#include "safe_queue.h"
using namespace std::literals;
std::mutex mut1;
std::mutex mut2;

size_t counter{};
size_t counter1{};
//2
void data_race_fcn(const int thread_id) {
    // std::lock_guard<std::mutex> lock(mut1);
    // counter+=thread_id;
    size_t temp{counter}; //зчитали
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    temp+=thread_id; // додаємо
    counter = temp; //присвоюємо
    std::cout << "thread " << thread_id <<  " - counter: " << counter << '\n';
}
//3
void no_data_race_fcn(const int thread_id) {
    std::lock_guard<std::mutex> lock(mut2);
    counter1+=thread_id;
    std::cout << "counter: " << counter1 << '\n';
}
//4 DEADLOCK
void funcA() {
    std::lock_guard<std::mutex> lockGuard1(mut1);
    std::this_thread::sleep_for(20ms);
    std::lock_guard<std::mutex> lockGuard2(mut2);
    std::this_thread::sleep_for(100ms);
    std::cout << "Function A has ended succesfully\n";
}
void funcB() {
    std::lock_guard<std::mutex> lockGuard2(mut2);
    std::this_thread::sleep_for(10ms);
    std::lock_guard<std::mutex> lockGuard1(mut1);
    std::this_thread::sleep_for(100ms);
    std::cout << "Function B has ended succesfully\n";
}

//5
void producer(Safe_queue<int> &queue) {
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    for(int i = 0; i < 100; i++) {
        queue.enqueue(i);
    }
}

void consumer(Safe_queue<int> &queue) {
    for(int i = 0; i < 50; i++) {
        std::cout << queue.dequeue() << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main() {
    //1
    int a{5};
    std::cout << a << '\n';
    auto lambda = [&a](){ 
        a = a*a; 
        std::cout << a << '\n';
    };
    std::thread th1(lambda);
    std::thread th2(lambda);
    std::thread th3(lambda);
    th1.join();
    th2.join();
    th3.join();

    //2
    std::cout << "Data race: \n";
    std::thread th4(data_race_fcn, 1);
    std::thread th5(data_race_fcn, 2);
    std::thread th6(data_race_fcn, 3);
    th4.join();
    th5.join();
    th6.join();

    //3
    std::cout << "\nNo data race: \n";
    std::thread th7(no_data_race_fcn, 1);
    std::thread th8(no_data_race_fcn, 2);
    std::thread th9(no_data_race_fcn, 3);
    th7.join();
    th8.join();
    th9.join();

    //4 DEADLOCK
    // std::thread th10(funcA);
    // std::thread th11(funcB);
    // th10.join();
    // th11.join();

    //5
    Safe_queue<int> q(100); 
    std::thread th11(consumer, std::ref(q));
    std::thread th10(producer, std::ref(q));
    th10.join();
    th11.join();
    return 0;
}