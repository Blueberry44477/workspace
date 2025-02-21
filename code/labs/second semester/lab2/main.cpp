#include <iostream>
using namespace std;
class Car {
private:
    string m_mark;
    int *m_id;
    int m_year;
public:
    Car(const string &mark = "", int id = 0, int year = 0)
        :m_mark{mark}, m_year{year} { 
            m_id = new int;
            *m_id = id;
    }
    Car(const Car &other):m_mark{other.m_mark}, m_year{other.m_year} {
        m_id = new int;
        *m_id = *other.m_id;
    }
    ~Car() { delete m_id; }
    void show() {
        cout << "Mark: " << m_mark << "\nID: " << *m_id << "\nYear: " << m_year << '\n';
    }
    void set_mark(const string &mark) { m_mark = mark; }
    friend std::ostream &operator<<(std::ostream &out, const Car &car) {
        out << "Mark: " << car.m_mark << "/ ID: " << *car.m_id << "/ Year: " << car.m_year;
        return out;
    }
};

class Customer {
private:
    string m_name;
    int m_customer_id;
    double m_phone_number;
public:
    Customer(const string &name, int id, double phone_number)
        : m_name{name}, m_customer_id{id}, m_phone_number{phone_number} {}
    Customer(string name, int id): Customer(name, id, 0) {}
    Customer(string name): Customer(name, 0, 0) {}
    Customer(): Customer("",0,0) {}
    string get_name() { return m_name; }
    void set_name(const string &name) { m_name = name; }
    friend std::ostream &operator<<(std::ostream &out, const Customer &customer) {
        out << "Name: " << customer.m_name << "/ ID: " << customer.m_customer_id 
        << "/ phone number: " << customer.m_phone_number;
        return out;
    }
};

class Rental_agreement {
private:
    double m_agreement_id;
    Customer m_customer;
    Car m_car;
public:
    Rental_agreement(double id = 0, const Customer &customer = Customer(), const Car &car = Car())
        :m_agreement_id{id}, m_customer{customer}, m_car{car} {}
    void get_details() {
        cout << "Agreement ID: " << m_agreement_id << "\nCustomer: " << m_customer << "\nCar: " << m_car << '\n';
    }
};
int main() {
    Car car("Skoda", 124, 2008);
    Car car2{car};
    car2.show();
    Customer customer("Sasha", 35, 5);
    customer.set_name("Gabriel");
    cout << customer.get_name() << '\n';
    Rental_agreement agr(12, customer, car);
    agr.get_details();
    return 0;
}