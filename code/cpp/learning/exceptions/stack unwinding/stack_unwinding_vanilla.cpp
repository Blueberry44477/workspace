#include <iostream>

using namespace std;

void secondFunction();

void thirdFunction();


void firstFunction() {
   cout << "First function start!" << endl;
   secondFunction();
   cout << "First function end!" << endl;
}

void secondFunction() {
   cout << "Second function start!" << endl;
   thirdFunction();
   cout << "Second function end!" << endl;
}

void thirdFunction() {
   cout << "Third function start!" << endl;
   cout << "Third function end!" << endl;
}

int main() {
   cout << "Starting main!" << endl;
   firstFunction();
   cout << "End of main!" << endl;
   return 0;
}