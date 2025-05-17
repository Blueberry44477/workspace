#include <iostream>
#include <vector>
#include <memory>

using namespace std;

//class Account {
//    //функції-друзі не успадковуються
//    friend ostream &operator<<(ostream &os, const Account &obj);
//
//public:
//    virtual void withdraw(double amount) {
//        cout << "Account withdraw for: " << amount << endl;
//    }
//
//    virtual ~Account() {
//    };
//};
//
//ostream &operator<<(ostream &os, const Account &obj) {
//    os << "Account status " << endl;
//    return os;
//}
//
//class SavingsAccount : public Account {
//    //функції-друзі не успадковуються
//    friend ostream &operator<<(ostream &os, const SavingsAccount &obj);
//
//public:
//    virtual void withdraw(double amount) {
//        cout << "SavingsAccount withdraw for: " << amount << endl;
//    }
//
//    virtual ~SavingsAccount() {
//    };
//};
//
//ostream &operator<<(ostream &os, const SavingsAccount &obj) {
//    os << "SavingsAccount status " << endl;
//    return os;
//}
//
//class TrustAccount : public Account {
//    //функції-друзі не успадковуються
//    friend ostream &operator<<(ostream &os, const TrustAccount &obj);
//
//public:
//    virtual void withdraw(double amount) {
//        cout << "TrustAccount withdraw for: " << amount << endl;
//    }
//
//    virtual ~TrustAccount() {
//    };
//};
//
//ostream &operator<<(ostream &os, const TrustAccount &obj) {
//    os << "TrustAccount status " << endl;
//    return os;
//}
//
//class CurrentAccount : public Account {
//    //функції-друзі не успадковуються
//    friend ostream &operator<<(ostream &os, const CurrentAccount &obj);
//
//public:
//    virtual void withdraw(double amount) {
//        cout << "CurrentAccount withdraw for: " << amount << endl;
//    }
//
//    virtual ~CurrentAccount() {
//    };
//};
//
//ostream &operator<<(ostream &os, const CurrentAccount &obj) {
//    os << "CurrentAccount status " << endl;
//    return os;
//}
//
class Printable {
    friend ostream &operator<<(ostream &os, const Printable &obj);

public:
    virtual void print(ostream &os) const = 0;

    virtual ~Printable() {
    };
};
//
//ostream &operator<<(ostream &os, const Printable &obj) {
//    obj.print(os);
//    return os;
//}

class Account : public Printable {
private:
    string ownerName;
    double balance;

public:
    Account(string &&name, double balance)
        : ownerName{name}, balance{balance} {
    }

    virtual void withdraw(double amount) {
        cout << "Account withdraw for: " << amount << endl;
    }

    virtual void print(ostream &os) const override {
        os << "Account data " << endl;
    }

    virtual ~Account() {
    };
};

class SavingsAccount : public Account {
public:
    SavingsAccount(string &&name, double balance)
        : Account(std::move(name), balance) {
    }

    virtual void withdraw(double amount) {
        cout << "SavingsAccount withdraw for: " << amount << endl;
    }

    virtual void print(ostream &os) const override {
        os << "SavingsAccount data " << endl;
    }

    virtual ~SavingsAccount() {
    };
};

class TrustAccount : public Account {
public:
    TrustAccount(string &&name, double balance)
        : Account(std::move(name), balance) {
    }

    virtual void withdraw(double amount) {
        cout << "TrustAccount withdraw for: " << amount << endl;
    }

    virtual void print(ostream &os) const override {
        os << "TrustAccount data " << endl;
    }

    virtual ~TrustAccount() {
    };
};

class CurrentAccount : public Account {
public:
    CurrentAccount(string &&name, double balance)
        : Account(std::move(name), balance) {
    }

    virtual void withdraw(double amount) {
        cout << "CurrentAccount withdraw for: " << amount << endl;
    }

    virtual void print(ostream &os) const override {
        os << "CurrentAccount data " << endl;
    }

    virtual ~CurrentAccount() {
    };
};

class Dog : public Printable {
private:
    string name;

public:
    Dog(string &&dogName) : name{dogName} {
    };

    virtual ~Dog() {
    };

    virtual void print(std::ostream &os) const override {
        os << "My name is " << name << "! " << "Woof Woof!" << endl;
    }
};


void print(Printable &obj) {
    cout << obj << endl;
}

int main() {
//    vector<unique_ptr<Account>> accounts;
//    accounts.push_back(make_unique<CurrentAccount>("Bob", 100));
//    accounts.push_back(make_unique<SavingsAccount>("Jack", 150));
//    accounts.push_back(make_unique<TrustAccount>("Ivan", 120));

    shared_ptr<Account> acc1 = make_shared<CurrentAccount>("Bob", 100);
    shared_ptr<Account> acc2 = make_shared<SavingsAccount>("Jack", 150);
    shared_ptr<Account> acc3 = make_shared<TrustAccount>("Ivan", 120);

    vector<shared_ptr<Account>> accounts;
    accounts.push_back(acc1);
    accounts.push_back(acc2);
    accounts.push_back(acc3);


    for (const auto acc: accounts) {
        cout << *acc << endl;
        cout << "use count: " << acc.use_count() << endl;
    }

    return 0;
}
