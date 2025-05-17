/* Дано двовимірний масив чисел A[n][n], n<=15.Написати програму, що будує масив Y[n] за правилом
за правилом: Y[i] = true, якщо в i-му рядку масиву А кількість від’ємних елементів більша від 
кількості додатних, інакше Y[i] = false. */

#include <iostream>
#include <random>
#include <windows.h>
#include <iomanip>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int n = 5;
	int dod_counter = 0, vid_counter = 0;
	int A[n][n]{};
	bool Y[n]{};
	cout << "A[" << n << "]" << "[" << n << "] = " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> distrib(-50, 50);
			int random_number = distrib(gen);
			A[i][j] = random_number;
			cout << setw(5) << A[i][j] << " ";
			
			if (A[i][j] < 0)
			{
				vid_counter++;
			}
			else (dod_counter++);
		}
		cout << " | Від'ємних елементів: " << vid_counter << " | Додатніх елементів: " << dod_counter;

		if (vid_counter > dod_counter)
		{
			Y[i] = true;
			cout << " | " << vid_counter << ">" << dod_counter;
			cout << " | Y[" << i << "] ---> true";
		}
		else
		{
			Y[i] = false;
			cout << " | " << vid_counter << "<" << dod_counter;
			cout << " | Y[" << i << "] ---> false";
		}
		cout << endl << endl;

		vid_counter = 0;
		dod_counter = 0;
	}
	cout << "Y[" << n << "]= " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(5) << Y[i] << " ";
	}
	cout << endl << endl;
	system("pause");
	return 0;
}