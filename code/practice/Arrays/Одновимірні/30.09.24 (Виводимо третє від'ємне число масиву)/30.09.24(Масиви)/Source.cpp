#include <iostream>
#include <random>
#include <Windows.h>
using namespace std;
int main(){
    SetConsoleOutputCP(1251);
    const int n = 10;
    int negative_count = 0;
    int arr[n];
    int third_negative = 0;
    for (int i = 0; i < n; i++) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(-50, 50);
        int random_number = distrib(gen);
        arr[i] = random_number;
        if (arr[i] < 0) {
            negative_count++;
        }
        if (negative_count == 3) {
            third_negative = arr[i];
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    if (negative_count < 3)
        cout << "\nНемає третього від'ємного\n";
    else 
        cout << "\nТретє від'ємне = " << third_negative << endl;
	return 0;
}