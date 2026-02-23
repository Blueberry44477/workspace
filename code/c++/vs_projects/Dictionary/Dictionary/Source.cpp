#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <windows.h>
#include <regex>
using namespace std;
bool backup_file(const string& original, const string& backup);
void save_to_file(const map<string, string>& dictionary, const string& file_name);
void read_from_file(map<string, string>& dictionary, const string& filename);
void show_words(const map<string, string>& dictionar);
void display_by_alphabet(const map<string, string>& dictionary);
void find_word(const map<string, string>& dictionary);
bool valid_input(const string& word, const string& prompt);
void add_word(map<string, string>& dictionary, const string &file_name);
void delete_word(map<string, string>& dictionary, const string& file_name);
void random_word(const map<string, string>& dictionary);

void maximizeConsoleWindow();
void IncreaseConsoleFontSize(int increment);

int main() {
	maximizeConsoleWindow();
	IncreaseConsoleFontSize(25);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	map<string, string> dictionary;
	const string file_name = "Dictionary.txt";
	read_from_file(dictionary, file_name);
	int k;

	enum Menu {
		SHOW = 1,
		ADD,
		DELETE_WORD,
		FIND,
		SHOW_RANDOM_WORD,
		SAVE,
		READ,
		EXIT,
	};

	do {
		cout << "Меню:\n"
			<< SHOW << ". Вивести всі слова\n"
			<< ADD << ". Додати слово та зберегти\n\n"
			<< DELETE_WORD << ". Видалити слово\n"
			<< FIND << ". Знайти слово\n"
			<< SHOW_RANDOM_WORD << ". Випадкове слово\n\n"
			<< SAVE << ". Зберегти у файл\n"
			<< READ << ". Зчитати з файлу\n"
			<< EXIT << ". Вийти та зберегти\n"
			<< "Вибір: ";

		cin >> k;
		switch (k) {
		case ADD:
			cin.ignore();
			system("cls");
			add_word(dictionary, file_name);
			break;
		case DELETE_WORD:
			cin.ignore();
			system("cls");
			delete_word(dictionary, file_name);
			break;
		case FIND:
			system("cls");
			find_word(dictionary);
			break;
		case SHOW:
			system("cls");
			display_by_alphabet(dictionary);
			break;
		case SHOW_RANDOM_WORD:
			system("cls");
			random_word(dictionary);
			break;
		case SAVE:
			system("cls");
			if (dictionary.empty()) {
				cout << "Дані словника пусті.";
				break;
			}
			else
				save_to_file(dictionary, file_name);
			break;
		case READ:
			system("cls");
			read_from_file(dictionary, file_name);
			break;
		case EXIT:
			system("pause");
			return 0;
		default:
			cout << "Такого пункту немає.\n";
		}
	} while (k);
	system("pause");
	return 0;
}

bool backup_file(const string& original, const string& backup) {
	ifstream in(original, ios::binary); // Відкриваємо оригінальний файл для читання
	if (!in) {
		cerr << "Помилка: не вдалося відкрити оригінальний файл для резервного копіювання.\n";
		return false;
	}
	in.seekg(0, std::ios::end);
	if (in.tellg() == 0) {
		cout << "Оригінальний файл порожній. Копію не перезаписано.";
		return false;
	}
	in.seekg(0, std::ios::beg);
	ofstream out(backup, ios::binary); // Відкриваємо резервний файл для запису
	if (!out) {
		cerr << "Помилка: не вдалося створити резервний файл.\n";
		return false;
	}
	out << in.rdbuf(); // Копіюємо вміст файлу
	cout << "Резерв перезаписаний.\n";//: " << backup << "\n";
	return true;
}
void save_to_file(const map<string, string>& dictionary, const string& file_name) {
	ofstream file(file_name);
	for (const auto& pair : dictionary) {
		file << pair.first << "-" << pair.second << '\n';
	}
	file.close();
	cout << "Збережено у файл. ";
	string backup_file_name = "Backup.txt";
	if (!backup_file(file_name, backup_file_name)) {
		cerr << "\nУвага: резервне копіювання не вдалося.\n";
	}
}

void read_from_file(map<string, string>& dictionary, const string& filename) {
	ifstream file(filename);
	if (!file) {
		cout << "Файл \"" << filename << " \" не знайдено.\n";
		return;
	}
	file.seekg(0, std::ios::end);
	if (file.tellg() == 0) {
		cout << "Файл зчитано. Файл порожній.\n";
		return;
	}
	file.seekg(0, std::ios::beg);
	dictionary.clear();
	string line;
	while (getline(file, line)) {
		size_t delimiterPos = line.find("-");
		if (delimiterPos != string::npos) {
			string word = line.substr(0, delimiterPos);
			string definition = line.substr(delimiterPos + 1);
			dictionary[word] = definition;
		}
	}
	file.close();
	cout << "Словник було зчитано з файлу \"" << filename << "\"\n";
}

string delete_spaces(const string& str) {
	size_t first = str.find_first_not_of(" \t");
	if (first == string::npos) return ""; // Якщо рядок повністю з пробілів

	size_t last = str.find_last_not_of(" \t");
	return str.substr(first, last - first + 1);
}
bool no_bad_symbols(const string& input) {
	regex valid_regex("^[A-Za-zА-Яа-яЁёЄєІіЇїҐґЎў,./ ()-]+$");
	return regex_match(input, valid_regex);
}
bool valid_input(string &input, const string& prompt = {}) {
	cout << prompt;
	if (!getline(cin, input)) {
		cout << "Ввід завершено\n";
		return false;
	}
	if (input.empty()) {
		cout << "Рядок порожній\n";
		return false;
	}
	if (!no_bad_symbols(input)) {
		cout << "Недозволені символи\n";
		return false;
	}
	return true;
}
void add_word(map<string, string>& dictionary, const string& file_name) {
		string word, definition;
		if (!valid_input(word, "Введіть слово (речення): \n"))
			return;
		word = delete_spaces(word);
		if (!valid_input(definition, "Введіть переклад: \n"))
			return;
		definition = delete_spaces(definition);
		dictionary[word] = definition;
		cout << "Слово додано.\n";
		save_to_file(dictionary, file_name);
}

void show_words(const map<string, string>& dictionary) {
	if (dictionary.empty() == true) {
		cout << "Словник порожній.\n";
	}
	else {
		cout << "Словник:\n";
		for (const auto& pair : dictionary)
			cout << pair.first << " - " << pair.second << "\n";
	}
}

void display_by_alphabet(const map<string, string>& dictionary) {
	if (dictionary.empty()) {
		cout << "Словник порожній.\n";
		return;
	}
	char current_letter = '\0'; // Поточна літера (ініціалізуємо порожнім значенням)
	cout << "Слова за алфавітом:\n";
	for (const auto& pair : dictionary) {
		char first_letter = tolower(pair.first[0]); // Беремо першу літеру слова (в нижньому регістрі)
		// Якщо перша літера змінюється, виводимо її
		if (current_letter != first_letter) {
			current_letter = first_letter;
			cout << current_letter << ":\n"; // Група для нової літери
		}
		// Виводимо слово
		cout << "  " << pair.first << " - " << pair.second << '\n';
	}
	cout << '\n';
}


void delete_word(map<string, string>& dictionary, const string& file_name) {
	if (dictionary.empty()) {
		cout << "Словник порожній.\n";
		return;
	}
	string word;
	if (!valid_input(word, "Введіть слово, щоб його видалити: "))
		return;
	auto it = dictionary.find(word);
	if (it != dictionary.end()) {
		dictionary.erase(word);
		save_to_file(dictionary, file_name);
		cout << "Слово \"" << word << "\" було видалено.\n";
	}
	else
		cout << "Немає такого слова: \"" << word << '\n';
}

void find_word(const map<string, string>& dictionary) {
	string word;
	cout << "Введіть слово для пошуку: ";
	cin.ignore();
	getline(cin, word);

	auto it = dictionary.find(word);
	if (it != dictionary.end())
		cout << "Переклад для слова \"" << word << "\" - " << it->second << endl;
	else
		cout << "Слова \"" << word << "\" немає.\n";
}

void random_word(const map<string, string>& dictionary) {
	if (dictionary.empty()) {
		cout << "Словник порожній.\n";
		return;
	}
	srand(time(0));  // Ініціалізація генератора випадкових чисел
	auto it = dictionary.begin();
	advance(it, rand() % dictionary.size());
	cout << "Випадкове слово: \n" << it->first << " - " << it->second << endl;
}


void maximizeConsoleWindow() {
	HWND hwnd = GetConsoleWindow(); // Отримання дескриптора вікна консолі
	ShowWindow(hwnd, SW_MAXIMIZE);  // Розгортаємо вікно на весь екран
}

void IncreaseConsoleFontSize(int increment) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE) {
		std::cerr << "Не вдалося отримати хендл консолі." << std::endl;
		return;
	}
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	if (!GetCurrentConsoleFontEx(hConsole, FALSE, &cfi)) {
		std::cerr << "Не вдалося отримати інформацію про шрифт." << std::endl;
		return;
	}
	// Збільшення висоти шрифту
	cfi.dwFontSize.Y += increment;
	if (!SetCurrentConsoleFontEx(hConsole, FALSE, &cfi)) {
		std::cerr << "Не вдалося змінити шрифт консолі." << std::endl;
	}
}
