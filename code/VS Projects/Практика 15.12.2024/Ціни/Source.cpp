#include <iostream>
#include <Windows.h>
using namespace std;
int main() {
	SetConsoleOutputCP(1251);
	float price = 0;
	float cost = 0;
	int gram = 0;
	const int index = 10;
	cout << "¬вед≥ть ц≥ну за 1 кг товару: ";
	cin >> price;
	cout << "¬ага\t¬арт≥сть\n(г)\t(грн)\n";
	for (int i = 0;i < index;i++) {
		gram += 100;
		cost += price * 0.1;
		cout << gram << "\t" << cost << "\n";
	}
	system("pause");
	return 0;
}