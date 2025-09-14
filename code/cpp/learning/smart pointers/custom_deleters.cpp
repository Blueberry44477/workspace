#include <iostream>
#include <memory>

using namespace std;

class Test {
private:
    int data;
public:
    Test() : data{0} { cout << "Test constructor" << endl; };

    Test(int data) : data{data} { cout << "Test constructor" << endl; };

    int getData() const { return data; }

    ~Test() { cout << "Test obj was destroyed." << endl; }
};

void customDeleter(Test *p) {
    cout << "I am going to custom delete my pointer" << endl;
    delete p;
}

int main(int argc, char **argv) {
    shared_ptr<Test> p1{new Test{25}};
    shared_ptr<Test> p2{new Test{35}, customDeleter};
    shared_ptr<Test> p3{new Test{45},
                        [](Test *ptr) {
                            cout << "I am going to custom delete my pointer using lambda function" << endl;
                            delete ptr;
                        }};


    return 0;
}