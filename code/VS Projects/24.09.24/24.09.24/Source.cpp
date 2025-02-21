#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int arr[7];
	//int arr[7] = { 1,4,5,6,3,6,9 };
//	int arr[3]{}; занулити масив
	//arr[0] = 34;
	//arr[1] = arr[0] + 7;
	//arr[2] = 0
	//cout << arr[0] << " " << arr[1] << " " << arr[2];
	for (int i = 0; i < 7; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
	return 0;
}

