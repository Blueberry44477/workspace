#include <iostream>
#include <iomanip>
using namespace std;
int** arrCreate(const int row, const int col) {
    int** arr = new int* [row];
    for (int i = 0; i < row; i++)
        arr[i] = new int[col];
    return arr;
}
void arrFree(int** arr, const int row) {
    for (int i = 0; i < row; i++)
        delete[] arr[i];
    delete[] arr;
}
void arrInput(int** arr, const int row, const int col) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) {
            cout << "arr[" << i << "]" << "[" << j << "] = ";
            cin >> arr[i][j];
        }
}
void arrOut(int** arr, const int row, const int col) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << setw(3) << arr[i][j];
        cout << endl;
    }
}
int main()
{
    const int r = 3;
    const int c = 3;
    int** arr = arrCreate(r, c);
    arrInput(arr, r, c);
    arrOut(arr, r, c);
    arrFree(arr, r);
    return 0;
}