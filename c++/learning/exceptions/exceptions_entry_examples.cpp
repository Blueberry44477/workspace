#include <iostream>
using namespace std;
void calculate() {
   int firstNumber{0};
   int secondNumber{0};
   double result{0};
   cout << "Enter first number" << endl << "first number: ";
   cin >> firstNumber;
   cout << "Enter second number" << endl << "second number: ";
   cin >> secondNumber;
   try {
       if (secondNumber == 0) {
           throw 0;
       }
       result = static_cast<double> (firstNumber) / secondNumber;
       cout << "Result: " << result << endl;
   } catch (int &ex) {
       cerr << "Can't divide by zero" << endl;
   }
}

double divide(int sum, int total) {
   if (total == 0) {
       throw 0;
   }
   return static_cast<double>(sum) / total;
}

void calculate2() {
   int firstNumber{0};
   int secondNumber{0};
   cout << "Enter first number" << endl << "first number: ";
   cin >> firstNumber;
   cout << "Enter second number" << endl << "second number: ";
   cin >> secondNumber;

   double result{};
   try {
       result = divide(firstNumber, secondNumber);
       cout << "Average value: " << result << endl;
   } catch (int &ex) {
       cerr << "Can't divide by zero" << endl;
   }
}

double averageSpeedCalculation(double distance, double time) {
   if (time == 0)
       throw 0;
   if (distance < 0 || time < 0)
       throw string{"Distance or time are negative values. Please, verify your inputs!"};

   return distance / time;
}

void calculate3() {
   double distance{0};
   double time{0};
   double averageSpeed{0};

   cout << "Enter total distance" << endl << "distance: ";
   cin >> distance;

   cout << "Enter total time" << endl << "time: ";
   cin >> time;

   try {
       averageSpeed = averageSpeedCalculation(distance, time);
       cout << "Your average speed was: " << averageSpeed << endl;
   }
   catch(int &ex) {
       cerr << "Division by zero detected!" << endl;
   } catch (string &ex) {
       cerr << ex << endl;
   } catch (...) {
       cerr << "Unknown exception detected" << endl;
   }
}

int main() {
// calculate();
//    calculate2();
// calculate3();

   cout << "Finish" << endl;
   return 0;
}
