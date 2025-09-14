#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "User.h"
class Customer: public User {
private:
    std::vector<std::shared_ptr<Vehicle>> m_rented_vehicles;
public:
    Customer(const std::string &username, const std::string &password, 
        const std::string &name, const std::string &contact_information);
    void show_rented_vehicles() const;
    int get_rented_vehicles_size() const;
    virtual void add_vehicle_to_rented(std::shared_ptr<Vehicle> vehicle) override;
    void remove_vehicle_from_rented(const int index);
    std::shared_ptr<Vehicle> get_rented_vehicle(const int index);
    const std::vector<std::shared_ptr<Vehicle>> &get_rented_vehicles() const {
        return m_rented_vehicles;
    }
    virtual void show_menu(Rental_system &rental_system, const std::string &username) override;
    virtual void write_data_to_file(std::ostream &file) override;
};
#endif