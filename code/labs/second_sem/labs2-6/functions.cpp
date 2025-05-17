#include "functions.h"
#include <iostream>
#include <algorithm>
int valid_int_input(const std::string &hint) {
    std::string input{};
    do {
        std::cout << hint;
        std::cin >> input;
    } while(input.empty() || input.size() > 4 || !std::all_of(input.begin(), input.end(), ::isdigit));
    return std::stoi(input);
}
bool is_valid_double(const std::string& str) {
    if (str.empty()) return false;
    bool has_decimal = false, has_digit = false;
    for (int i = 0; i < str.size(); i++) {
        if (std::isdigit(str[i])) {
            has_digit = true;
        } else if (str[i] == '.' && !has_decimal) {
            has_decimal = true;
        } else if ((str[i] == '-' || str[i] == '+') && i == 0) {
            continue;
        } else {
            return false;
        }
    }
    return has_digit;
}
double valid_double_input(const std::string &hint) {
    std::string input{};
    double result{0.0};
    do {
        std::cout << hint;
        std::cin >> input;
    } while(!is_valid_double(input));
    return std::stod(input);
}
