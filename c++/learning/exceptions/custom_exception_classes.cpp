#include <iostream>
#include <string>
using namespace std;
class DivideByZeroException {
public:
   string m_message;

   DivideByZeroException(string message) : m_message{message} {}
};
class NegativeValueException {
private:
    string m_msg;
public:
    NegativeValueException(string msg = "negative value exception"): m_msg{msg} {}
    const string get_msg() const { return m_msg; }
};

double averageSpeedCalculation(double distance, double time) {
   if (time == 0)
       throw DivideByZeroException("weqeweqewe");
   if (distance < 0 || time < 0)
       throw NegativeValueException();

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
   } catch (const DivideByZeroException &ex) {
//        cerr << "Division by zero detected!" << endl;
       cerr << ex.m_message << endl;
   } catch (const NegativeValueException &ex) {
    //    cerr << "Negative values are not allowed!" << endl;
        cerr << ex.get_msg() << '\n';
   }
}

int main() {
   calculate3();
}