#include <iostream>
#include <fstream>
using namespace std;
int main() {

	//Створюємо файл
	ofstream fout("file.txt");
	fout << "Hello, World\n Hello, World 2";
	fout.close();
	//Читаємо з файлу
	ifstream fin("file.txt");
	if (fin.is_open() == 0)
		cout << "No file";
	else
	{
		char buff[50];
		while (fin.eof() == 0)
		{
			fin.getline(buff, 50);
			cout << buff << endl;
		}
		fin.close();
	}
	/*fin.getline(buff, 50);
	cout << buff;
	fin.close();*/
	
	/*ifstream fin("file.txt");
	fin.getline(buff, 50);
	fin.close();
	cout << buff;*/

	return 0;
}