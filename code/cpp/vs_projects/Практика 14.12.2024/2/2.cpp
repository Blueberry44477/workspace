#include <iostream>
#include <windows.h>
using namespace std;
bool IsIcecreamSandwich(const char* word) {
	int length = strlen(word);
	if (length < 3) {
		//cout << " Умова 1: довжина менша за три\n";
		return false;
	}
	bool allthesame = true;
	for (int i = 1;i < length - 1;i++) {
		if (word[i] != word[0])
			allthesame = false;
	}
	if (allthesame == true)
		return false;
	int left = 0;
	int right = length - 1;
	while (left < right && word[left] == word[right]) {
		++left;
		--right;
	}
	char centerChar = word[left];
	for (int i = left;i <= right;++i) {
		if (word[i] != centerChar) {
			//cout << " Умова 3: не всі символи центральної частини однаковi\n";
			return false;
		}
	}
	return true;
}
int main() {
	SetConsoleOutputCP(1251);
	const int c = 100;
	char* a = new char[c] {};
	const char* test1 = "CDC";
	const char* test2 = "AAABB";
	const char* test3 = "AA";
	const char* test4 = "AABBBAA";
	cout << std::boolalpha;
	cout << "isIcecreamSandwich(\"CDC\") -> " << IsIcecreamSandwich(test1) << endl;
	cout << "isIcecreamSandwich(\"AAABB\") -> " << IsIcecreamSandwich(test2) << endl;
	cout << "isIcecreamSandwich(\"AA\") -> " << IsIcecreamSandwich(test3) << endl;
	cout << "isIcecreamSandwich(\"AABBBAA\") -> " << IsIcecreamSandwich(test4) << endl << endl;
	cout << "Спробуйте зробити сендвіч з морозивом: ";
	cin >> a;
	cout << "Ваше слово: ";
	for (int i = 0;i < c;i++)
		cout << a[i];
	if (IsIcecreamSandwich(a) == true)
		cout << " є сендвічем з морозивом ";
	else
		cout << " не є сендвічем з морозивом ";
	cout << "\n";
	delete[]a;
	system("pause");
	return 0;

}