#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <curl/curl.h>

using namespace std;
using namespace std::chrono;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    auto* buf = static_cast<string*>(userp);
    buf->append(static_cast<char*>(contents), size * nmemb);
    return size * nmemb;
}

vector<string> update_blacklist(const string& url = "https://openphish.com/feed.txt") {
    vector<string> domains;
    CURL* curl = curl_easy_init();
    
    if (!curl) {
        cerr << "Не вдалося ініціалізувати CURL\n";
        return domains;
    }
    
    string buffer;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
    
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        cerr << "Помилка при завантаженні чорного списку: " << curl_easy_strerror(res) << "\n";
    } else {
        cout << "Чорний список оновлено успішно.\n";
        istringstream iss(buffer);
        string line;
        while (getline(iss, line)) {
            if (!line.empty()) {
                domains.push_back(line);
            }
        }
    }
    
    curl_easy_cleanup(curl);
    return domains;
}

bool is_phishing(const string& url, const vector<string>& dynamic_blacklist) {
    if (url.length() > 75) {
        return true;
    }
    
    if (url.rfind("https://", 0) != 0) {
        return true;
    }

    vector<string> suspicious = { "@", "//", "-", "%", "#" };
    for (const auto& s : suspicious) {
        if (url.find(s, 8) != string::npos) {
            return true;
        }
    }
    
    regex pattern(R"(https?://(www\.)?([^/]+))");
    smatch match;
    
    if (regex_search(url, match, pattern) && match.size() >= 3) {
        string domain = match[2].str();
            
        static const vector<string> static_blacklist = {
            "faceb00k.com",
            "micros0ft.com",
            "goggle.com"
        };
        
        if (find(static_blacklist.begin(), static_blacklist.end(), domain) != static_blacklist.end()) {
            return true;
        }
        
        if (find(dynamic_blacklist.begin(), dynamic_blacklist.end(), domain) != dynamic_blacklist.end()) {
            return true;
        }
    }
    
    return false;
}

void save_result(const string& url, const string& result) {
    auto now = system_clock::now();
    time_t now_c = system_clock::to_time_t(now);
    tm local_tm = *localtime(&now_c);
    
    ofstream file("results.txt", ios::app);
    if (file.is_open()) {
        file << "[" << put_time(&local_tm, "%Y-%m-%d %H:%M:%S") << "] "
             << "URL: " << url << " – Результат: " << result << "\n";
    }
}

int main() {
    vector<string> blacklist = update_blacklist();

    for (int i = 0; i < 20; i++) {
        std::cout << blacklist[i] << '\n';
    }
    
    while(true) {
        cout << "Введіть URL для перевірки: ";
        string url;
        getline(cin, url);
        
        bool phishing_detected = is_phishing(url, blacklist);
        string result_text = phishing_detected ? "Підозрілий" : "Безпечний";
        
        if (phishing_detected) {
            cout << "Увага! Це посилання може бути фішинговим!\n";
        } else {
            cout << "Це посилання є безпечним.\n";
        }
        
        cout << "Результат перевірки: " << result_text << "\n";
        
        save_result(url, result_text);
    }
    
    return 0;
}