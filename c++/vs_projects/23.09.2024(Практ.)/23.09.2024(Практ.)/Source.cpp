#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int f = 1, e = 10, s3 = 0, s5 = 0, r;
	int sum;
	for (int i = f;i <= e;i++)
	{
		if (i % 3 == 0)
		{
			s3 += i;
		}
		if (i % 5 == 0)
		{
			s5 += i;
		}

	}
	r = fabs(s3 - s5);
	if (r % 2 == 0)
		cout << "r Парне " << r << endl;
	if (r % 3 == 0)
		cout << "r Непарне " << r << endl;

	system("pause");
	return 0;
}