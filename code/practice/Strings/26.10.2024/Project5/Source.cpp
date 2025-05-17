/*Ввести з клавіатури текст, в якому слова розділені пробілами і 
різними розділовими знаками. Написати програму, яка в словах 
непарної довжини початкового тексту видаляє середню літеру.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
#include <windows.h>
using namespace std;

const int words = 1000;
const int words_length = 100;

int main() {
    SetConsoleOutputCP(1251);
    char text[5000];
    char words[words][words_length];
    char delim[] = { " \t\n\r!.,;:\"'()[]{}<>" };
    int wordCount = 0;

    cout << "Введіть текст: ";
    cin.getline(text, sizeof(text));



    char* token = strtok(text, delim);
    while (token != NULL) {
        bool found = false;
        for (int i = 0; i < wordCount; ++i) {
            if (strlen(token) % 3 = 0) 
            {

            }
        }
        if (found == false) {
            strcpy(words[wordCount], token);
            wordCount++;
        }
        token = strtok(NULL, delim);
    }
    cout << "Оновлений текст: ";
    for (int i = 0; i < wordCount; ++i) {
        cout << words[i] << " ";
    }
    cout << endl;