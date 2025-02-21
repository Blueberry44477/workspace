#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <windows.h>
using namespace std;

vector<string> splitToWords(const string& text) {
    vector<string> words;
    string word;
    istringstream stream(text); 
    while (stream >> word) {
        word.erase(remove_if(word.begin(), word.end(),
            [](char c) { return ispunct(c); }),
            word.end());
        words.push_back(word);
    }
    return words;
}

int main() {
    SetConsoleOutputCP(1251);
    string text1;
    string text2;

    cout << "¬вед≥ть перший текст: ";
    getline(cin, text1);
    cout << "¬вед≥ть другий текст: ";
    getline(cin, text2);

    vector<string> words1 = splitToWords(text1);
    vector<string> words2 = splitToWords(text2);

   set<string> wordsToRemove(words1.begin(), words1.end());
    vector<string> result;
    copy_if(words2.begin(), words2.end(), back_inserter(result),
        [&wordsToRemove](const string& word) {
            return wordsToRemove.find(word) == wordsToRemove.end();
        });

    cout << "–езультат: ";
    for (const auto& word : result) {
        cout << word << " ";
    }
    cout << '\n';

    return 0;
}
