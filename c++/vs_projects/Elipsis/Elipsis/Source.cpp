#include <iostream>
#include <cstdarg>
void print(int count, ...) {
	va_list args; // Оголошення списку аргументів
	va_start(args, count); //Ініціалізація списку зі змінною count
	for (int i = 0; i < count; i++) {
		int value = va_arg(args, int);  // Отримання наступного аргументу як int
		std::cout << i << ' ' << value << '\n';
	}
	va_end(args);
}
int main() {
	print(3, 10, 15, 20);
	return 0;
}