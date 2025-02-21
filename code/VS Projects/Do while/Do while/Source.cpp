#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	int c, d;
	
	do
	{
		cout << "Input right range c and d \n";
		cin >> c >> d;
	}
	while (c>d);
	cout << "Range" << endl << c << endl << d << endl;
	cout << "Right!" << endl;
	cout << "\n";
	system("pause");
	return 0;
}

