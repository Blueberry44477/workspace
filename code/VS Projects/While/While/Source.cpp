#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	char symbol = ' ';
	while (symbol != 'a')
	{
		cout << "Guess a symbol!" << endl;
		cin >> symbol;
	}
	cout << "Right! \n";
	system("pause");
	return 0;
}

