#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << "¬вед≥ть 1)))" << endl;
	cin >> n;
	if (n == 1)
	{
		cout << "Ќ€-н€-н€" << endl;
	}
	else 
	{
		cout << "Ќ€мочка мо€ ввела не одиничку" << endl;
	}

	system("pause");
	return 0;
}
