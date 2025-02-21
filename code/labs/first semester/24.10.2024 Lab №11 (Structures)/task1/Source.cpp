#include <iostream>
using namespace std;
int main()
{
	struct Student
	{
		char prizv[15];
		int p[5];
		float ser = 0;
	};
	int n, i;
	cout << "Enter number of students" << endl;
	cin >> n;
	Student* a = new Student[n];
	float m_b = 0;
	for (i = 0; i < n; i++)
	{

		cout << "Enter surename" << endl;
		cin >> a[i].prizv;
		cout << "Enter 5 marks" << endl;
		for (int j = 0; j < 5; j++)
		{
			cin >> a[i].p[j];
			a[i].ser += a[i].p[j] / 5.0;
		}
	}
	for (i = 0; i < n; i++)
		if (a[i].ser >= m_b)
			m_b = a[i].ser;
	for (i = 0; i < n; i++)
		if (a[i].ser == m_b)
			cout << a[i].prizv << "\'s grade average = " << a[i].ser <<
			endl;
	delete[] a;
	return 0;
}