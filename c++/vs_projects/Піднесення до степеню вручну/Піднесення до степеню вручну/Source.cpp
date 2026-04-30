#include <iostream>
#include <Windows.h>
using namespace std;

int main() 
{
    SetConsoleOutputCP(1251);
    double base;
    int exp;
    double result = 1; 
    cout << "¬вед≥ть число: ";
    cin >> base;
    cout << "¬вед≥ть степ≥нь: ";
    cin >> exp;
    int counter = 0;
    while (counter < exp) 
    {
        result *= base;
        counter++;
    }
    cout << base << "^" << exp << " = " << result << endl;
    return 0;
}
