#include <iostream>
using namespace std;
void vivid(int a) {
	cout << a;
}
void showArray (int arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}
int main()
{
	vivid(5);
	int arr[] = { 5,4,3,2,1 };
	showArray(arr, 5);
	return 0;
}