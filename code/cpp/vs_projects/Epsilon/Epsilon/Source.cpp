#include <iostream>
#include <cmath> // Для використання функції fabs (модуль)
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double epsilon; // Точність
    std::cout << "Введіть точність (epsilon): ";
    std::cin >> epsilon;

    double sum = 0.0; // Початкова сума
    double term = 1.0; // Початковий член ряду (зазвичай обчислюється)
    int n = 0; // Лічильник членів ряду

    // Приклад для ряду 1/n! (наприклад, для обчислення e = exp(1))
    while (fabs(term) > epsilon)
    {
        sum += term; // Додаємо поточний член до суми
        n++; // Переходимо до наступного члена ряду
        term = 1.0 / tgamma(n + 1); // Обчислюємо наступний член ряду 1/n!
    }

    std::cout << "Сума ряду з точністю " << epsilon << " = " << sum << std::endl;
    std::cout << "Кількість доданків: " << n << std::endl;

    return 0;
}
