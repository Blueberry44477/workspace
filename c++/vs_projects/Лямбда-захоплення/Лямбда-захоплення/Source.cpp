#include <iostream>
#include <vector>
#include <functional>
using namespace std;

void repeat(int repetitions, const std::function<void(int)>& fn) {
	for (int i = 0; i < repetitions; i++) {
		fn(i);
	}
}

std::function<int()> create_counter() {
	int counter = 0;
	return [counter]() mutable {
		return counter++;
	};
}
int main() {
	auto counter = create_counter();
	for (int i = 0; i < 5; i++)
		cout << counter() << '\n';	

	int a = 0;
	auto change = [a]() mutable -> int {
		a++;
		return a;
	};
	cout << "copy = " << change() << '\n';
	cout << "a = " << a << '\n';
	vector <string> vec{ "Apple, Banana, Wallnut" };
	auto found{ find_if(vec.begin(),vec.end(),[](string str) {return (str.find("nut") != string::npos); }) };
	if (found == vec.end())
		cout << "No nuts\n";
	else
		cout << "Found nuts\n";

	// Звичайний вказівник на функцію. Лямбда не може нічого захоплювати.
	double (*add_numbers)(double, double) {
		[](double a, double b) {
			return (a + b);
		}
	};
	add_numbers(1, 2);

	// std::function. Лямбда може захоплювати змінні.
	std::function<double(double, double)> add_numbers2 {
		[](double a, double b) {
			return (a + b);
		}
	};
	add_numbers2(1, 2);

	// auto. Зберігаємо лямбду з її реальним типом
	auto add_numbers3 {
		[](double a, double b) {
			return (a + b);
		}
	};
	add_numbers3(1, 2);


	// Ми не знаємо, чим буде fn. std::function працює зі звичайними функціями і лямбдами
	repeat(3, [](int i) {
		cout << i << '\n';
	});

	return 0;
}