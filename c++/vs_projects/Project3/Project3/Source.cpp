#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "Enter n = ";
	cin >> n;
	int factorial = 1;
	int i = 1;
	while (i<=n)
	{
		factorial *= i;
		i++;
	}
	cout << "Factorial = " << factorial << endl;
	return 0;
}