#include <iostream>
#include <fstream>

using namespace std;
int main() {
	//ofstream fout("text.txt"); скорочено
	ofstream fout;
	fout.open("text.txt"); //, ios_base::app); 

	fout << "Hello, World!";
	fout << endl;
	fout << " Hello, World!";
	fout << endl;
	fout.close();

	ifstream fin("text.txt");
	if (fin.is_open() == 0) {
		cout << "No file";
	}
	else {
		char str[100];
		while (!fin.eof()) {
			fin.getline(str, 100);
			cout << str;
		}
		
	}
	


	


	return 0;
}
