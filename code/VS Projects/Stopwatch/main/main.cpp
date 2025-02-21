#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <thread>// Для затримки виконання
#include <conio.h>
#include <ctime>
#include <Windows.h>
#include <iomanip>
using namespace std;

void maximizeConsoleWindow() {
    HWND hwnd = GetConsoleWindow(); // Отримання дескриптора вікна консолі
    ShowWindow(hwnd, SW_MAXIMIZE);  // Розгортаємо вікно на весь екран
}

void IncreaseConsoleFontSize(int increment) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) {
        std::cerr << "Не вдалося отримати хендл консолі." << std::endl;
        return;
    }
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    if (!GetCurrentConsoleFontEx(hConsole, FALSE, &cfi)) {
        std::cerr << "Не вдалося отримати інформацію про шрифт." << std::endl;
        return;
    }
    // Збільшення висоти шрифту
    cfi.dwFontSize.Y += increment;
    if (!SetCurrentConsoleFontEx(hConsole, FALSE, &cfi)) {
        std::cerr << "Не вдалося змінити шрифт консолі." << std::endl;
    }
}

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
    Beep(2000, 1500);
    cout << "Час вийшов!\n";
}

void stopwatch() {
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    system("cls");
    //cout << "Натисніть Enter, щоб запустити...";
    //cin.ignore();
    auto start_time_point = chrono::system_clock::now(); // Час початку
    auto start_time = chrono::system_clock::to_time_t(start_time_point);
    auto steady_start = chrono::steady_clock::now(); // Для вимірювання проміжку часу
    while (true) {
        if (_kbhit()) { // Очікуємо натискання клавіші
            system("cls");
            break;
        }
        // Обчислення часу, що минув
        auto current_time = chrono::steady_clock::now();
        auto duration = chrono::duration_cast<chrono::seconds>(current_time - steady_start);
        auto current_time_point = chrono::system_clock::now();
        auto clock = chrono::system_clock::to_time_t(current_time_point);

        int total_seconds = duration.count();
        hours = total_seconds / 3600;
        minutes = (total_seconds % 3600) / 60;
        seconds = total_seconds % 60;

        system("cls");
        cout << "Time: " << put_time(localtime(&clock), "%H:%M:%S") << "\n";
        cout << "Start: " << put_time(localtime(&start_time), "%H:%M:%S") << "\n";
        cout << "Passed: ";
        if (hours < 10) cout << 0;
        cout << hours << ":";
        if (minutes < 10) cout << 0;
        cout << minutes << ":";
        if (seconds < 10) cout << 0;
        cout << seconds << "\n";
        cout << "Натисніть Enter, щоб зупинити...\n";
        this_thread::sleep_for(chrono::seconds(1));
    }
    // Час завершення
    auto end_time_point = chrono::system_clock::now();
    auto end_time = chrono::system_clock::to_time_t(end_time_point);
    // Результат
    auto steady_end = chrono::steady_clock::now();
    auto total_duration = chrono::duration_cast<chrono::seconds>(steady_end - steady_start);
    cout << "Секундомір увімкнено: " << put_time(localtime(&start_time), "%H:%M:%S") << "\n";
    cout << "Секундомір зупинено: " << put_time(localtime(&end_time), "%H:%M:%S") << "\n";
    cout << "Загальний час: ";
        if (hours < 10) cout << 0;
    cout << hours << ":";
    if (minutes < 10) cout << 0;
    cout << minutes << ":";
    if (seconds < 10) cout << 0;
    cout << seconds << "\n";
}

int main() {
    maximizeConsoleWindow();
    SetConsoleOutputCP(1251);
    IncreaseConsoleFontSize(20);
    int k = 0;
    int duration;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    do {
        cout << "Виберіть пункт меню:\n1. Таймер\n2. Секундомір\n3. Вихід\nВибір: ";
        cin >> k;
        switch (k) {
        case 1:
            system("cls");
            cout << "Введіть час для таймера у форматі ## ## ##: ";
            cin >> hours >> minutes >> seconds;
            duration = hours * 3600 + minutes * 60 + seconds;
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
            cout << "До побачення!";
            return 0;
        }
    } while (k);
    return 0;
}
