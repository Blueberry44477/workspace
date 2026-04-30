/*
Дано двовимірний масив чисел A[n][n], n <= 15.Написати програму, що будує масив Y[n] за правилом:
Y[i] = true, якщо в i - му рядку масиву А кількість від’ємних елементів більша від кількості додатних,
інакше Y[i] = false .
*/
#include <iostream>
#include <Windows.h>
#include <random>
#include <iomanip>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	const int n = 5;
	int A[n][n]{};
    bool Y[n];
    
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
            if (A[i][j] < 0)
                count_negative++;
            else if (A[i][j] > 0)
                count_positive++;
            cout << setw(5) << A[i][j] << " ";
        }
        cout << "    Кількість від'ємних чисел у рядку = " << count_negative << " | Кількість додатніх чисел у рядку = " << count_positive;
        if (count_negative > count_positive) 
        {
            Y[i] = true;
            cout << " | Y [" << i << "] ---> true" << endl;
        }
        else 
        {
            Y[i] = false;
            cout << " | Y [" << i << "] ---> false" << endl;
        }
        cout << endl;
    }
    cout  << "| ";
    for (int k = 0;k < n;k++)
    {
        cout << "Y [" << k << "] = " << Y[k] << " | ";
    }
    cout << endl;
    for (int k = 0;k < n;k++)
    {
        cout << Y[k] << " ";
    }
    cout << endl;
	system("pause");
	return 0;
}
