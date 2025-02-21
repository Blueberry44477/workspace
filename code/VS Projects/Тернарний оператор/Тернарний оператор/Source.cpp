#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	int a, b;
	cout << "Enter a" << endl;
	cin >> a;
	b=a > 5 ? 15 : 10; //ÿךשמ א ב³כüרו 5 - b=15, ם³- b=10
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	return 0;
	system("pause");
}