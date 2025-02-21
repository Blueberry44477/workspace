#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
struct Student {
	string name;
	int mark;
};
int main() {
    vector <Student> vec = { 
    { "Albert", 3 },
    { "Ben", 5 },
    { "Christine", 2 },
    { "Dan", 8 }, // Dan לא÷ םאיב³כüרו באכ³ג (8)
    { "Enchilada", 4 },
    { "Francis", 1 },
    { "Greg", 3 },
    { "Hagrid", 5 }
    };
    auto max_mark = std::max_element(vec.begin(), vec.end(), [](auto& a, auto& b) {
        return (a.mark < b.mark);
        }); 
    cout << max_mark->name;

    struct Season
    {
        string name{};
        double averageTemperature{};
    };
        array<Season, 4> seasons{
          { { "Spring", 285.0 },
            { "Summer", 296.0 },
            { "Fall", 288.0 },
            { "Winter", 263.0 } }
        };

        std::sort(seasons.begin(), seasons.end(), [](const auto &a, const auto &b) {
            return (a.averageTemperature < b.averageTemperature);
            });

        for (const auto& season : seasons)
        {
            std::cout << season.name << '\n';
        }

        return 0;
 }