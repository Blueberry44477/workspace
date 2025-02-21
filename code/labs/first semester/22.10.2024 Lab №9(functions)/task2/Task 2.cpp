/* Задано натуральні n і m. Розробити програму для обчислення значень заданих 
виразів. При обчисленні виразів використати рекурсивні процедури або функції. */
#include <cmath>
#include <iostream>
using namespace std;

long f_factorial(int m) {
	if (m == 0 || m == 1)
		return 1;
	return m * f_factorial(m - 1);
}

double sqrt_sum (int n){
	if (n == 0)
		return 0;
	else
		return sqrt(pow(2, n)) + sqrt_sum(n - 1);
}

double solution(int m, int n){
	return f_factorial(m) / sqrt_sum(n);
}

int main() {
	int m,n ;
	cout << "Enter m, n: ";
	cin >> m >> n;
	cout << endl << solution(m, n) << endl;
	system("pause");
	return 0;
}