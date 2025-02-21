//Написати програму, яка: а) створює.txt файл text_1 із символьних
//рядків довільної довжини, слова в яких розділені пробілами і різними
//розділовими знаками; б) зчитує файл text_1 і записує кожне слово в
//окремий рядок файлу text_2(розділові знаки опускаються); в) зчитує
//файл text_2 і виводить його вміст по рядках.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstring>
#include <cctype>

using namespace std;

int main() {	
	SetConsoleOutputCP(1251);
	
	const int size = 200;
	const int words = 200;
	const int words_length = 100;
	
	char buff[size];
	char words_by_one[words][words_length];
	char delim[] = { " \n\t\r!.,;:\"'!?/*()[]{}<>" };
	int WordCount = 0;

	ofstream text1_out("text_1.txt");
	text1_out << "Символьні * рядки[довільної] довжини, слова в як\nих розділені!пробілами й різними ? розділовими / знаками";
	text1_out << "* рядки[довільної] довжини, слова в як\nих";
	text1_out.close();
		
	ofstream text2_out("text_2.txt");
	ifstream text1_in("text_1.txt");
	if (!text1_in.is_open())
		cout << "No file";
	else 
	{
		cout << "\"text_1.txt\":\n";
		while (text1_in.eof() == 0)
		{
			text1_in.getline(buff, sizeof(buff));
			cout << buff << endl;
			
			char* token = strtok(buff, delim);
			while (token != NULL)
			{
				strcpy(words_by_one[WordCount], token);
				text2_out << words_by_one[WordCount] << endl;
				WordCount++;
				token = strtok(NULL, delim);
			}
		}
	}
	text2_out.close();
	text1_in.close();
	
	//в)
	ifstream text2_in("text_2.txt");
	if (!text2_in.is_open())
		cout << "No file";
	else
	{
		cout << "\n\"text_2.txt\":\n";
		while (!text2_in.eof())
		{
			text2_in.getline(buff, sizeof(buff));
			cout << buff << "\n";
		}
	}
	text2_in.close();

	system("pause");
	return 0;
}