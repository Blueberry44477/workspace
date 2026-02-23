#include <iostream>
using namespace std;
int main()
{
	int a = 20, k;
	cout << "Enter k, k[1;3] " << endl;
	cin >> k;
	cout << "Case#" << k << endl;
	cout << "a=" << a << endl;
	switch (k)
	{
	case 1:a += 5; cout << "a=a+5" << endl;break;
	case 2:a += 10;cout << "a=a+10" << endl;break;
	case 3:a += 20;cout << "a=a+20" << endl;break;
	default: cout << "You entered wrong k, k[1;3]" << endl;
	}
	cout << "a=" << a << endl;
	return 0;
}