#include <string>
#include <algorithm>
#include <iostream>
#include <windows.h>

using namespace std;

// Функція видалення пробілів з початку та кінця рядка
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t");
    if (first == string::npos) return ""; // Якщо рядок повністю з пробілів

    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, last - first + 1);
}

int main() {
    SetConsoleOutputCP(1251);
    string word;
    cout << "Введіть слово: ";
    getline(cin, word);

    // Видаляємо зайві пробіли
    word = trim(word);

    cout << "Очищений текст: [" << word << "]" << endl;

    return 0;
}
