#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;
int factorial(const int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        cout << i << "*";
        result *= i;
    }
    cout << '\n';
    return result;
}
int main()
{
    SetConsoleOutputCP(1251);
    int number;
    cout << "Введіть число, щоб обчислити його факторіал: ";
    cin >> number;
    if (number < 0)
        return 0;
    else
        cout << factorial(number);
    return 0;
}
