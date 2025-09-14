#include <iostream>
#include <windows.h>
using namespace std;
bool IsIcecreamSandwich(const char* word) {
	int length = strlen(word);
	if (length < 3) {
		cout << "Довжина менша за три";
		return false;
	}
	int left = 0;
	int right = length-1;
	cout << "\nДо: Left: " << left << "Right: " << right << "\n";
	while (left < right && word[left] == word[right]) {
		++left;
		--right;
	}
	cout << "Після: Left: " << left << "Right: " << right << "\n";
	//Якщо центр не знайдено або центр пустий
	if (left >= right) {
		cout << "центр не знайдено або центр пустий\n";
		return false;
	}
		
	char centerChar = word[left];
	for (int i = 0;i <= right;++i) {
		if (word[i] != centerChar)
			return false;
	}
	return true;
}
int main() {
	SetConsoleOutputCP(1251);
	const int c = 100;
	char* a = new char[c] {};
	cin >> a;
	cout << "Ваше слово: ";
	for (int i = 0;i < c;i++)
		cout << a[i];
	if (IsIcecreamSandwich(a) == true)
		cout << " є сендвічем з морозивом";
	else
		cout << " не є сендвічем з морозивом\n";
	const char* test1 = "CDC";
	const char* test2 = "AAABB";
	const char* test3 = "AA";
	const char* test4 = "AABBBAA";

	std::cout << std::boolalpha;
	std::cout << "isIcecreamSandwich(\"CDC\") -> " << IsIcecreamSandwich(test1) << std::endl;
	std::cout << "isIcecreamSandwich(\"AAABB\") -> " << IsIcecreamSandwich(test2) << std::endl;
	std::cout << "isIcecreamSandwich(\"AA\") -> " << IsIcecreamSandwich(test3) << std::endl;
	std::cout << "isIcecreamSandwich(\"AABBBAA\") -> " << IsIcecreamSandwich(test4) << std::endl;
	delete[]a;
	system("pause");
	return 0;
	
}