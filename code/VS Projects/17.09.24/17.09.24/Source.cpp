#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//for (ініціалізація;умова;приріст)
	//{
		// послідовність операторів (команди)
	//}
	// for (; n<=m n+=1) - блок може бути пустим
	//Рахуємо суму чисел від нуля до введеного
	int n, s = 0;
	cout << "Enter number n=" << endl;
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		s += i;
		cout << "i = " << i << endl << "=" << endl;
		cout << "s = " << s << endl << "+" << endl;
	}
	//cout << "s = " << s << endl;
	


	system("pause");
	return 0;
}

