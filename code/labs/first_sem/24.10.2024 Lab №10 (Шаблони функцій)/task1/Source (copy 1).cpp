/*Задано матрицю A[n][n], n<=15. Розробити шаблонну функцію для
побудови масиву X(i), i = 1,2,...,n, за правилом: X[n] дорівнює
середньому арифметичному значенню елементів i-го рядка матриці.*/
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <random>
using namespace std;


const int n = 5;
template <typename T>
void buildarray(T A[][n], T X[n])
{
	for (int i = 0; i < n; i++) {
		T sum = 0;
		for (int j = 0; j < n; j++) {
			sum += A[i][j];
		}
		X[i] = sum / n;
	}
	cout << "Array X: ";
	for (int i = 0; i < n; i++) {
		cout << setw(5) << X[i] << endl;
	}
}

int main() {
	double A[n][n] = {};
	float X[n] = {};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<>distrib(-50, 50);
			int random_number = distrib(gen);
			A[i][j] = random_number;
			cout << setw(5) << A[i][j];
		}
		cout << endl;
	}
	buildarray(A, X,n);
	return 0;
}