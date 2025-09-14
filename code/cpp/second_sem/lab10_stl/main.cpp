#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <map>
#include <iterator>
#include <functional>
#include <sstream>

template<typename T>
void show(const std::vector<T> &vec) {
    for (const auto x : vec)
        std::cout << x << ' ';
    std::cout << '\n';
}

template<typename T, const size_t size>
void show(const std::array<T,size> &arr) {
    for (const auto x : arr)
        std::cout << x << ' ';
    std::cout << '\n';
}

template<typename T>
void show(const std::deque<T> &deq) {
    for (const auto x : deq)
        std::cout << x << ' ';
    std::cout << '\n';
}

//1
template<typename T, const size_t size1, const size_t size2>
std::array<T, size1+size2> sorted_merge(const std::array<T, size1> &arr1, const std::array<T, size1> &arr2) {
    std::array<T, size1+size2> result{};
    auto it1 = arr1.begin();
    auto it2 = arr2.begin();
    auto it_r = result.begin();
    while(it1 != arr1.end() && it2 != arr2.end()) {
        if(*it1 < *it2)
            *it_r++ = *it1++;
        else
            *it_r++ = *it2++;
    }
    while(it1 != arr1.end())
        *it_r++ = *it1++;
    while(it2 != arr2.end())
        *it_r++ = *it2++;
    return result;
}

//2
template<typename T>
void split(std::vector<T> &input, std::vector<T> &odd, std::vector<T> &even) {
    for(auto x : input) {
        if (x % 2 == 0) 
            even.emplace_back(x);
        else
            odd.emplace_back(x);
    }
}

//3
template<typename T>
bool is_palindrome(const std::deque<T> &deque) {
    if(deque.empty())
        return false;
    auto front = deque.begin();
    auto back = deque.end();
    back--;
    while(front < back) {
        if(*front != *back)
            return false;
        front++;
        back--;
    }
    return true;
}

//4 Зсув елементів
template<typename T, size_t N>
void rotate(std::array<T, N>& arr, size_t shift) {
    shift %= N;
    for (size_t i = 0; i < shift; ++i) {
        T temp = arr.back(); //запам'ятовуємо останній елемент
        for (size_t j = N - 1; j > 0; --j) //переміщаємо усі елементи на одну позицію вперед
            arr[j] = arr[j - 1]; 
        arr[0] = temp; // переміщаємо останній елемент на першу позицію
    }
}

//5 Вставка діапазону
template<typename T>
void insert_at(std::vector<T> &giver, std::vector<T> &receiver, const size_t pos) {
    auto it_giv = giver.begin();
    auto it_rec = receiver.begin() + pos;
    while(it_giv != giver.end() && it_rec != receiver.end()) {
        *it_rec++ = *it_giv++;
    }

}

//6 Видалити середній елемент
template<typename T>
void remove_middle(std::deque<T> &deque) {
    if(deque.size() == 0) 
        return;
    if(deque.size() < 3)
        deque.clear();
    if(deque.size() % 2 == 0)
        deque.erase(deque.begin() + deque.size() / 2 - 1, deque.begin() + deque.size()/2 + 1); //діапазон
    else
        deque.erase(deque.begin() + deque.size() / 2);
}

//part2 var11-20
//1 Підрядок мінімального діапазону
//Знайти найменший діапазон символів в рядку, який містить всі символи іншого рядка.
std::string find_min_string(const std::string &given, const std::string &to_search) {
    if(given.empty() || to_search.empty())
        throw std::invalid_argument("One or more strings are empty");

    //словник потрібних символів(ключ - кількість).
    std::unordered_map<char, int> frequency; 
    std::for_each(to_search.begin(), to_search.end(), [&frequency](char symbol) {
        frequency[symbol]++; 
    });

    std::unordered_map<char,int> window;
    size_t required = frequency.size(); //кількість необхідних символів-ключів
    size_t formed = 0; //сформовано необхідну кількість ключів
    size_t left = 0; //ітератор по рядку
    size_t right = 0;
    //мінімальна довжина валідного вікна.
    //Спочатку - максимальне значення
    size_t min_length = std::numeric_limits<size_t>::max(); 
    size_t min_left = 0; //індекс початку валідного вікна

    while(right < given.size()) {
        char symbol = given[right];
        window[symbol]++;
        //якщо це потрібний символ та кількість його зустрічань збігаються з необхідними то formed++
        if(frequency.count(symbol) && window[symbol] == frequency[symbol]) { 
            formed++;
        }
        //поки поточне вікно задовольняє умову та коректне по межах(left<=right)
        //намагаємося звузити його зліва, щоб зробити мінімальним
        //справа немає звужувати, адже воно не може стати меншим з того краю
        //блок закінчується як тільки перевірили повністю, чи може валідне вікно стати меншим.
        while(left <= right && formed == required) {
            //якщо довжина поточного вікна менша за останню збережену, то оновлюємо
            if (right - left + 1 < min_length) {
                min_length = right - left + 1; //нова найменша довжина валідного вікна
                min_left = left; //індекс початку валідного вікна
            }

            char left_char = given[left]; //зберігаємо символ який будемо вилучати з вікна 
            window[left_char]--; //видаляємо символ з вікна зліва
            //якщо цікавий символ то перевіряємо чи зменшилась його кількість після видалення
            //умова window[left_char] < frequency[left_char] потрібна, адже кількість цікавих символів
            //може бути надлишкова

            //якщо ж кількість цікавих слів так і не збільшилась, то нового мінімального рядку
            //було не знайдено, і ми його просто виводимо
            if (frequency.count(left_char) && window[left_char] < frequency[left_char]) {
                formed--;
            }
            left++;
        }
        right++;
    }
    //якщо мінімальний рядок не було змінено, отже валідного вікна не було знайдено, значить повертаємо ""
    //інакше повертаємо найкоротший валідний рядок.
    if(min_length == std::numeric_limits<size_t>::max())
        throw std::logic_error("No valid window was found");
    else
        return given.substr(min_left, min_length);
}



//2 Планувальник завдань
class Task_scheduler {
private:
    std::unordered_map<std::string, int> m_last_execution;
    int m_cooldown_period;
    int m_current_time = 0;
public:
    Task_scheduler(const int cooldown): m_cooldown_period(cooldown) {}

    bool schedule_task(const std::string& task_name) {
        // Перевіряємо, чи минув період cooldown для цього завдання
        auto can_execute = [this](const std::string& task) {
            auto it = m_last_execution.find(task);
            return it == m_last_execution.end() || (m_current_time - it->second) >= m_cooldown_period;
        };

        if (can_execute(task_name)) {
            m_last_execution[task_name] = m_current_time;
            m_current_time++;
            std::cout << "Виконується завдання: " << task_name << " у час " << m_current_time - 1 << '\n';
            return true;
        } else {
            std::cout << "Завдання " << task_name << " відхилено (період cooldown)" << '\n';
            return false;
        }
    }

    // Спланувати послідовність завдань
    void schedule_tasks(const std::vector<std::string>& tasks) {
        for (const auto& task : tasks) {
            schedule_task(task);
        }
    }
};
//3 Розташовування гравців в рейтинговій таблиці
void show_rating(const std::map<int, std::string, std::greater<int>> &players) {
    std::cout << "\n\nPlayers rating\n" 
            << "Player \tRate\n";
    for(const auto [score, name] : players) {
        std::cout << name << '\t' << score << '\n';
    }
}
//4 Подібність речень
int count_common_words(const std::string& s1, const std::string& s2) {
    auto build_freq = [](const std::string& text) {
        std::unordered_map<std::string, int> freq;
        std::istringstream iss(text);
        std::for_each(std::istream_iterator<std::string>(iss),
                      std::istream_iterator<std::string>(),
                      [&freq](const std::string& word) { 
                        freq[word]++; 
                    });
        return freq;
    };

    auto freq1 = build_freq(s1);
    auto freq2 = build_freq(s2);

    int count = 0;
    for (const auto &[word, freq_in_first] : freq1) {
        if (freq2.count(word)) {
            count += std::min(freq_in_first, freq2[word]);
        }
    }

    return count;
}

//5 Мнемотехніка номера телефону
std::vector<std::string> mnemonic_combinations(const std::string& digits) {
    if (digits.empty()) 
        throw std::invalid_argument("Input is empty");
    // T9-мапінг
    const std::unordered_map<char, std::string> digit_to_letters = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };
    for (char ch : digits) {
        if (!digit_to_letters.count(ch))
            throw std::invalid_argument("Digits must be in range 2–9");
    }
    std::vector<std::string> result;
    std::string current;
    //не auto бо рекурсія
    //сходи вперед - повернися назад
    std::function<void(size_t)> backtrack = [&](size_t index) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        const std::string &letters = digit_to_letters.at(digits[index]);
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(index + 1);
            current.pop_back(); //щоб отримати всі можливі варіації
        }
    };
    backtrack(0);
    return result;
}


int main() {
   
    
    //1
    // std::cout << "\nTask1:\n";
    // std::array<int, 5> arr1{2,4,5,6,9};
    // std::array<int, 5> arr2{7,9,10,11, 13};
    // auto arr3 = sorted_merge<int,5,5>(arr1,arr2);
    // for(const auto x : arr3)
    //     std::cout << x << ' ';
    // //2
    // std::cout << "\n\nTask2:\n";
    // std::vector<int> vector{1,2,3,4,5,6,7,8,9,10};
    // std::vector<int> even;
    // std::vector<int> odd;
    // split(vector, odd, even);
    // std::cout << "vector: ";
    // show(vector);
    // std::cout << "even: ";
    // show(even);
    // std::cout << "odd: ";
    // show(odd);
    
    // //3
    // std::cout << "\nTask3:\n";
    // std::deque<char> deq1{'a','b','a'};
    // std::cout << "Deque is a palindrome? - " << std::boolalpha << is_palindrome(deq1) << '\n';
    
    //4
    const int rotation_number{2};
    std::cout << "\nTask4:\n";
    std::array<int,5> arr{0,1,2,3,4};
    std::cout << "Before rotation: ";
    show(arr);
    rotate(arr, rotation_number);
    std::cout << "After " << rotation_number << " rotations: ";
    show(arr);
    
    //5
    std::cout << "\nTask5:\n";
    std::vector<int> giver{1,2,3,4,5};
    std::vector<int> receiver(5);
    insert_at(giver,receiver, 3);
    std::cout << "Giver: ";
    show(giver);
    std::cout << "Receiver: ";
    show(receiver);

    //6
    std::cout << "\nTask6:\n";
    std::deque<std::string> deq2{"one", "two", "three", "four"};
    show(deq2);
    remove_middle(deq2);
    show(deq2);


     //part 2
    //1
    std::string given{"HELLO, HE"};
    std::string to_search{"HEHE"};
    std::cout << "Given: " << given << '\n';
    std::cout << "To search: " << to_search << '\n';
    try {
        std::cout << find_min_string(given, to_search);
    } catch (std::invalid_argument &ex) {
        std::cerr << "One or more strings are empty\n";
    } catch (std::logic_error &ex) {
        std::cout << "No valid window was found\n";
    }
    //2
    

    //3
    show_rating(std::map<int, std::string, std::greater<int>>{{100, "Max"}, {300, "Tolya"}, { 200, "Anya"}});
    //4
    std::string sentence1 = "Кіт сидить на килимі";
    std::string sentence2 = "Килим лежить на килимі";
    int common_words = count_common_words(sentence1, sentence2);
    std::cout << "Кількість однакових слів: " << common_words << '\n';

    //5
    auto show = [](const std::vector <std::string> vec) {
        for (const auto x : vec)
            std::cout << x << ' ';
    };
    show(mnemonic_combinations("5324"));

    return 0;
}