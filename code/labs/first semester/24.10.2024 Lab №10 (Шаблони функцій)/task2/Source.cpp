#include <iostream>
#include <iomanip>
#include <windows.h>
#include <random>
using namespace std;

// Шаблонна функція для побудови масиву X[i]
template <typename T>
void buildArrayX(T A[][15], T X[], int n) {
    for (int i = 0; i < n; i++) {
        T sum = 0;
        for (int j = 0; j < n; j++) {
            sum += A[i][j];  // Підсумовуємо елементи i-го рядка
        }
        X[i] = sum / n;  // Обчислюємо середнє арифметичне
    }
    cout << "Масив:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "X[" << i + 1 << "] = " << X[i] << endl;
    }
}

int main() {
    SetConsoleOutputCP(1251);
    int n;
    cin >> n;
    double A[15][15]; 
    double X[15];      
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<>distrib(-50, 50);
            int random_number = distrib(gen);
            A[i][j] = random_number;
            cout << setw(5) << A[i][j];
        }
        cout << endl;
    }

    buildArrayX(A, X, n);

    
    

    return 0;
}
