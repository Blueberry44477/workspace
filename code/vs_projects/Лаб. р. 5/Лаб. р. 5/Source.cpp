#include <iostream>
#include <random>
using namespace std;
int main()
{
	const int n = 10;
	int arr[n];
	for (int i = 1; i <= n; i++)
	{
		random_device rd;  // Використовується для генерації сід
		mt19937 gen(rd()); // Генератор на основі Mersenne Twister
		uniform_int_distribution <> distrib(-50, 50);
	
		int random_number = distrib(gen); // Генеруємо випадкове число в діапазоні
		arr[i] = random_number;
		cout << arr[i];

	}
	return 0;
}