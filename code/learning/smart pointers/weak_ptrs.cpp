#include <memory>
#include <iostream>
using namespace std;

class B;

class A {
    shared_ptr<B> bPtr;

public:
    void setB(shared_ptr<B> &b) {
        bPtr = b;
    }

    A() { cout << "A constructor" << endl; }
    ~A() { cout << "A destructor" << endl; }
};


class B {
    shared_ptr<A> aPtr;
    // weak_ptr<A> aPtr;

public:
    void setA(shared_ptr<A> &a) {
        aPtr = a;
    }

    B() { cout << "B constructor" << endl; }
    ~B() { cout << "B destructor" << endl; }
};

int main() {
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    a->setB(b);
    b->setA(a);
}
