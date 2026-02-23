#include <iostream>
#include <Windows.h>
#include <random>
#include <iomanip>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int n = 3;
    int A[n][n]{};
    bool Y[n];
    int number = 0;
    int sum = 0;
    cout << "Enter number ";
    cin >> number;

    for (int i = 0; i < n; i++) //переходимо на наступний рядок
    {
        int count_negative = 0;
        int count_positive = 0;
        for (int j = 0; j < n; j++) //перевіряємо кожен елемент рядка
        {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> distrib(-50, 50);
            int random_number = distrib(gen); //генерація рандомних чисел

            A[i][j] = random_number;
            cout << setw(4) << A[i][j];
        }
        cout << endl;
       
    }
    for (int j = 0;j < n;j++)
    {
        sum += A[number][j];
    }
    cout << "Sum = " << sum << endl;
    
    return 0;
}