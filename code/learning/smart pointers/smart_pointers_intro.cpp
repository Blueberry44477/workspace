#include <iostream>
#include <vector>
#include <memory>
using namespace std;
class Account {
private:
    double balance;
    string ownerName;
public:
    Account(string &ownerName, double balance = 0)
            : ownerName{ownerName}, balance{balance} {
        cout << "Account object was created" << endl;
    }
    Account(string &&ownerName, double balance = 0)
            : ownerName{ownerName}, balance{balance} {
        cout << "Account object was created" << endl;
    }
    ~Account() {
        cout << "Account object was destroyed" << endl;
    }
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
        cout << "Account deposit with: " << amount << endl;
    }
    void withdraw(double amount) {
        if (balance - amount >= 0) {
            balance -= amount;
            cout << "Account withdraw with: " << amount << endl;
        } else {
            cout << "Account not enough money for withdraw of: " << amount << endl;
        }
    }
    friend ostream &operator<<(ostream &os, const Account &rhs) {
        os << rhs.ownerName << endl << rhs.balance << endl;
        return os;
    }
};

int main() {
    unique_ptr<int> somePtr{new int{23}}; //Погана форма
    unique_ptr<int> p1 = make_unique<int>(10);
    unique_ptr<Account> pAccount = make_unique<Account>("John", 1000);

    auto somePtr1 = make_unique<Account>("Bob", 25);
    cout << *pAccount << endl;
    unique_ptr<Account> anotherAccount;
    anotherAccount = std::move(pAccount);
    cout << *anotherAccount << endl;

    shared_ptr<int> sp1 = make_shared<int>(150); // use_count: 1
    cout << "p1: " << sp1.use_count() << endl;
    shared_ptr<int> sp2{sp1};                    // use_count: 2
    cout << "p2: " << sp2.use_count() << endl;
    shared_ptr<int> sp3;
    cout << "p2: " << sp2.use_count() << endl;
    cout << "p3: " << sp3.use_count() << endl;
    sp3 = sp1;                                    // use_count: 3
    p1.reset();
    cout << "p3: " << sp3.use_count() << endl;
    cout << *sp2 << endl;

    return 0;
}
