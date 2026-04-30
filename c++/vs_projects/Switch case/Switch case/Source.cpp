#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
int main()
{//case 1; У кейсі не можна одразу ініціліазувати змінну й одразу надати їй значення
	//int a;
	//a=1;
	//або {int a=1};
	#define_USE_MATH_DEFINES;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int task, v, a, t, s, l, P, R;
	cout <<"Input task#:"<<endl;
	cin >> task;
	switch (task)
	case 1:
		cout << "v=a*3";
		cin >> a;
		cout << "v=" << pow(a, 3);
		break;
	case 2:
		cout << "s=v*t";
		cin >> v >> t;
		cout << "s=" << v * t;
		break;
	case 3:
		cout << "1=2*M_PI*R";
		cin >> R;
		cout << "1=2*M_PI*R=" << 2 * M_PI * R;
		break;
	default:
		cout << "Wrong number";
	system("pause");
	return 0;
}

