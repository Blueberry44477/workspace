/*
Дано двовимірний масив чисел A[n][n], n <= 15.Написати програму, що будує масив Y[n] за правилом:
Y[i] = true, якщо в i - му рядку масиву А кількість від’ємних елементів більша від кількості додатних, 
інакше Y[i] = false . 
*/
#include <iostream>
#include <vector>
#include <windows.h>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int n = 5; // Розмір масиву, можна змінити відповідно до завдання
    int A[n][n] = {
        {1, -2, -3, 4, -5},
        {6, 7, -8, -9, 10},
        {-11, -12, -13, 14, -15},
        {16, 17, 18, 19, 20},
        {-21, -22, -23, -24, 25}
    };

    std::vector<bool> Y(n, false);  // Масив Y[n] ініціалізований значеннями false

    // Проходимо по кожному рядку матриці A
    for (int i = 0; i < n; ++i) {
        int count_negative = 0; // Лічильник від'ємних чисел
        int count_positive = 0; // Лічильник додатних чисел

        // Перевіряємо кожен елемент в i-му рядку
        for (int j = 0; j < n; ++j) {
            if (A[i][j] < 0) {
                count_negative++;
            }
            else if (A[i][j] > 0) {
                count_positive++;
            }
        }

        // Якщо кількість від'ємних елементів більше за кількість додатних, встановлюємо Y[i] = true
        if (count_negative > count_positive) {
            Y[i] = true;
        }
    }

    // Виводимо масив Y
    std::cout << "Масив Y: ";
    for (bool value : Y) {
        std::cout << (value ? "true" : "false") << " ";
    }
    std::cout << std::endl;

    return 0;
}
