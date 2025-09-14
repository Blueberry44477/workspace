/*Дано символ і текст, в якому слова розділені пробілами і різними 
розділовими знаками. Створити програму, яка знаходить і друкує всі 
слова, що містять даний символ найбільшу кількість разів. Створити і 
викликати власну функцію для підрахунку кількості входжень 
символу в слово і функцію для виводу слів.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <cctype>
#include <cstring>
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    char text[5000] = {};
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int word_number = 0;
    char symbol;

    cout << "Введіть текст: ";
    cin.getline(text, sizeof(text));

    cout << "Введіть символ для пошуку: ";
    cin >> symbol;

    char* token = strtok(text, " \t\n\r!.,;:\"'()[]{}<>");
    while (token != NULL) 
    {
        if (word_number < MAX_WORDS) 
        {
            strcpy(words[word_number], token);
            word_number++;
        }
        token = strtok(nullptr, " \t\n\r!.,;:\"'()[]{}<>");
    }
    printWordsWithMaxOccurrences(words, word_number, symbol);
    return 0;
}