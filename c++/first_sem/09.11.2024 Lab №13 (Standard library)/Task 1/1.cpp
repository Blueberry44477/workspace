#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <random>
#include <iomanip>
#include <Windows.h>
using namespace std;

vector<int> ArrayInit(vector<int>& A, int n, const char* name) {
    cout << "Масив " << name << ":";
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(-25,25);
    for (int i = 0; i < n; i++) {
        A[i] = distrib(gen);
        cout << setw(3) << A[i];
    }
    cout << '\n';
    return A;
}
int main() {
    SetConsoleOutputCP(1251);
    char name1[] = { "A" };
    char name2[] = { "B" };
    int n, m;
    cout << "Введіть кількість елементів у масиві A та B: ";
    cin >> n >> m;
    vector<int> A(n);
    vector<int> B(m);
    A = ArrayInit(A, n, name1);
    B = ArrayInit(B, m, name2);
    set<int> out(A.begin(), A.end()); //унікальні
    out.insert(B.begin(), B.end());
    cout << "Елементи об'єднання A та B: ";
    for (auto it = out.begin(); it != out.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    int sum = accumulate(out.begin(), out.end(), 0);
    cout << "Сума елементів об'єднання: " << sum << endl;
    system("pause");
    return 0;
}
