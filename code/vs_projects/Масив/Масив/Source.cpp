#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	const int n = 10;
	int arr[n];
	int sum = 0;
	int i = 0;
	for (int k = 0;k <= n;k++)
	{
		arr[i] = rand() % 10;
		cout << arr[i] << " ";
		sum += arr[i];
	}
	cout << endl << sum << endl;
	system("pause");
	return 0;
}