#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
//	int arr[7];
	
	//int arr[7] = { 1,4,5,6,3,6,9 };
//	int arr[3]{}; занулити масив
	//arr[0] = 34;
	//arr[1] = arr[0] + 7;
	//arr[2] = 0
	//cout << arr[0] << " " << arr[1] << " " << arr[2];
	const int n = 5;// константа для кількість елементів
	int sum = 0, counter = 0;
	int arr[n];
	srand(time(NULL));//функція, яка рахує час від запуску плюсів
	//cout << "Enter array" << endl;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (20) - 10; //генерація від 0 до 19 - 10
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
		//if (i % 2 == 0)//сума елементів, які стоять на парних позиціях масиву
		if (arr[i] % 2 == 0)//сума парних елементів
			//sum += arr[i];
			//counter++;
	}
	//cout << endl << sum << endl;
	//cout << endl << counter << endl;
	system("pause");
	return 0;
}

