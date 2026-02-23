#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <climits>

std::string minWindowSubstring(const std::string& s, const std::string& t) {
    std::unordered_map<char, int> required;
    std::unordered_map<char, int> window;
    for (char c : t) 
        required[c]++;
    
    int have = 0; 
    int need = required.size();
    int left = 0;
    int minLen = INT_MAX; 
    int start = 0;

    for (int right = 0; right < s.size(); ++right) {
        window[s[right]]++;
        if (required.count(s[right]) && window[s[right]] == required[s[right]])
            ++have;

        while (have == need) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }
            window[s[left]]--;
            if (required.count(s[left]) && window[s[left]] < required[s[left]])
                --have;
            ++left;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

int main() {
    std::set<int> s1{4,5,1,3,2,10};
    for (auto x : s1)
        std::cout << x << ' ';
    return 0;
}