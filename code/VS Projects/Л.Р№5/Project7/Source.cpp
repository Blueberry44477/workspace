/*
   Задано масив чисел A[n], n <= 300. Написати програму, яка заміняє всі
   від’ємні елементи на середнє арифметичне елементів масиву.
 */
#include <iostream>
#include <random>
#include <Windows.h>
using namespace std;
int main()
{  

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int count = 0;
    const int n = 3;
    double arr[n];

    double sum = 0;
    double СереднєАрифметичне;

    for (int i = 0; i < n; i++) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(-50, 50);
        int random_number = distrib(gen);

        arr[i] = random_number;
        cout << "Arr [" << i << "] = " << arr[i] << endl;
        sum += arr[i]; 
    }
    СереднєАрифметичне = sum / n;
    cout << endl << "Середнє арифметичне = " << СереднєАрифметичне << endl << endl;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            cout << "Arr [" << i << "] = " << arr[i] << " був від'ємним ---> ";
            arr[i] = sum / n;
            cout << "Arr [" << i << "] = " << arr[i] << endl;
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "Arr [" << i << "] = " << arr[i] << endl;
    }
    system("pause");
    return 0;
}