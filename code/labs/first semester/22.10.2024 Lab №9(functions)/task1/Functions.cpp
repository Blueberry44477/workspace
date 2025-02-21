#include "Header.h"
#include <iostream>
#include <cctype>
using namespace std;

int countOccurrences(const char* word, char symbol) 
{
    int count = 0;
    while (*word) 
    {
        if (tolower(*word) == tolower(symbol)) 
        {
            count++;
        }
        word++;
    }
    return count;
}

void printWordsWithMaxOccurrences(char words[][MAX_WORD_LENGTH], int wordCount, char symbol) 
{
    int maxCount = 0;
    for (int i = 0; i < wordCount; ++i) 
    {
        int count = countOccurrences(words[i], symbol);
        if (count > maxCount) 
        {
            maxCount = count;
        }
    }
    cout << "Слова, що містять символ '" << symbol << "' найбільшу кількість разів (" << maxCount << " разів):\n";
    for (int i = 0; i < wordCount; ++i) {
        if (countOccurrences(words[i], symbol) == maxCount) {
            cout << words[i] << "\n";
        }
    }
}
