#include<iostream>
using namespace std;

int get_integer() {
	cout << "Enter an integer number: ";
	int a{};
	cin >> a;
	return a;
}
char get_math_operation() {
	char op{};
	do {
		cout << "Enter an operation ('+','-','*','/'): ";
		cin >> op;
	} while (op != '+' && op != '-' && op != '*' && op != '/');
	return op;
}
int add(int a, int b) {
	return a + b;
}
int substract(int a, int b) {
	return a - b;
}
int multiply(int a, int b) {
	return a * b;
}
int divide(int a, int b) {
	return a / b;
}
typedef int (*arithmetic_fcn)(int, int);
struct Arithmetic_struct {
	char operation;
	arithmetic_fcn fcn;
};
static Arithmetic_struct arithmetic_array[]{ {'+',add},{'-',divide},{'*',multiply},{'/',divide} };
arithmetic_fcn get_arithmetic_function(const char op) {
	for (auto& arith : arithmetic_array)
		if (arith.operation == op)
			return arith.fcn;
	return add;
}
int main() {
	int int_a = get_integer();
	int operation = get_math_operation();
	int int_b = get_integer();
	get_arithmetic_function(operation);
	arithmetic_fcn fcn = get_arithmetic_function(operation);
	std::cout << int_a << ' ' << operation << ' ' << int_b << " = " << fcn(int_a, int_b) << '\n';
	return 0;
}