#include <iostream>
using namespace std;

class Numbers {
	int m_first_number;
	int m_second_number;

public:
	void set(int a, int b) {
		m_first_number = a;
		m_second_number = b;
	}
	void print() {
		cout << "First: " << m_first_number << "\nSecond: " << m_second_number;
	}
	void copy_from(const Numbers& b) {
		m_first_number = b.m_first_number;
		m_second_number = b.m_second_number;
	}
};

int main() {
	Numbers one;
	one.set(2,3);
	cout << "one: ";
	one.print();
	Numbers two;
	two.set(3, 4);
	cout << "\ntwo: ";
	two.print();
	two.copy_from(one);
	cout << "\ncopied two: ";
	two.print();

	return 0;
}