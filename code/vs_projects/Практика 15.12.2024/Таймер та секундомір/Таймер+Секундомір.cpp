#include <iostream>
#include <chrono>
#include <thread>// Для затримки виконання
#include <conio.h>
#include <Windows.h>
using namespace std;
void timer(int seconds) {
    system("cls");
    for (int i = seconds; i > 0; --i) {
        cout << "Залишилось: " << i << " секунд\n";
        this_thread::sleep_for(chrono::seconds(1)); // Затримка на 1 секунду
        system("cls");
        if (_kbhit()) {
            system("cls");
            break;
        }
    }
    Beep(1000, 500);
    cout << "Час вийшов!\n";
}
void stopwatch() {
    system("cls");
    cout << "Натисніть Enter, щоб запустити";
    cin.ignore();
    auto start_time = chrono::high_resolution_clock::now();
    cout << "Секундомір запущено! Натисніть Enter, щоб зупинити...\n";
    for (int i = 0; ;i++) {
        cout << i << "\n";
        this_thread::sleep_for(chrono::seconds(1));
        if (_kbhit()) {
            system("cls");
            break;
        }
        system("cls");
    }
    auto end_time = chrono::high_resolution_clock::now(); // Фіксація часу завершення
    auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time);
    cout << "Час: " << duration.count() << " секунд\n";
}

int main() {
    SetConsoleOutputCP(1251);
    int k = 0;
    int duration;
    do {
        cout << "Виберіть пункт меню:\n1. Таймер\n2. Секундомір\n3. Вихід\nВибір: ";
        cin >> k;
        switch (k) {
        case 1:
            system("cls");
            cout << "Введіть кількість секунд для таймера: ";
            cin >> duration;
            timer(duration);
            system("pause");
            system("cls");
            break;
        case 2:
            cin.ignore();
            stopwatch();
            break;
        case 3:
            system("cls");
            cout << "До побачення!\n";
            return 0;
        }
    } while (k);
    return 0;
}
