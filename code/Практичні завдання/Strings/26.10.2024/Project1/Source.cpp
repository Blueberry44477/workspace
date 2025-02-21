#include <iostream>
#include <cctype>
#include <windows.h>
using namespace std;

void processWord(char* word) {
    int length = 0;
    while (word[length] != '\0') {
        length++;
    }
    if (length % 2 != 0) {
        int middleIndex = length / 2;
        for (int i = middleIndex; i < length - 1; i++) {
            word[i] = word[i + 1];
        }
        word[length - 1] = '\0';
    }
}

void processText(char* text) {
    char word[100];
    int wordIndex = 0;

    for (int i = 0; ; i++) {
        
        if (text[i] == '\0') {
            if (wordIndex > 0) {
                word[wordIndex] = '\0';  
                processWord(word);       
                cout << word << ' ';  
                wordIndex = 0;
            }
            if (text[i] == '\0') break;  
        }
        else {
            word[wordIndex++] = text[i];
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    char text[256];
    cout << "¬вед≥ть текст: ";
    cin.getline(text, 256);

    cout << "ќброблений текст: ";
    processText(text);
    cout << endl;

    return 0;
}
