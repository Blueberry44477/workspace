#include <iostream>
#include <ostream>
#include <windows.h>

using namespace std;
struct Data {
    int day;
    char month[16];
    int year;
};

struct Taxi {
    int nomer;
    char marka[32];
    Data date;
};

void init(Taxi* cars, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Number" << endl;
        cin >> cars[i].nomer;
        cout << "Marka" << endl;
        cin.ignore();
        cin.getline(cars[i].marka, 32);
        cout << "Date" << endl;
        cin >> cars[i].date.day >> cars[i].date.month >> cars[i].date.year;
    }
}

void show(Taxi* cars, int n) {
    cout << "Number\tMarka\tData" << endl;
    for (int i = 0; i < n; i++) {
        cout << cars[i].nomer << "\t\t" << cars[i].marka << "\t\t";
        cout << cars[i].date.day << "." << cars[i].date.month << "." << cars[i].date.year << endl;
    }
}

void changeP(Taxi* cars, int a, int b){
    swap(cars[a], cars[b]);
}

int main() {
    SetConsoleOutputCP(1251);
    int n, k;
    cout << "enter number of cars ";
    cin >> n;
    Taxi* cars = new Taxi[n];

    enum Menu {
        EXIT,
        INIT,
        SHOW,
        CHANGE_PLACES,
    };

    do {
        cout << "Натисніть:" << endl << "0 для завершення" << endl << "1 для ініціалізації" << endl << "2 для виводу на екран" << endl;
        cout << "3, щоб поміняти місцями" << endl;
        cin >> k;

        switch (k) {
        case EXIT: return 0;
        case INIT: init(cars, n);
            break;
        case SHOW: show(cars, n);
            break;
        case CHANGE_PLACES: 
            int a, b; 
            cout << "Введіть номери двох елементів, щоб поміняти їх місцями" << endl;
            do {
                cin >> a >> b;
            } while (a > n - 1 || b > n - 1);
            changeP(cars, a, b);
            break;
        default: cout << "Введіть правильний номер";
        }
    } while (k);


}