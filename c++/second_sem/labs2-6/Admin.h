#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"
#include "Rental_system.h"
class Admin: public User {
private:
public:
    Admin(const std::string &username, const std::string &password, 
    const std::string &name, const std::string &contact_information);
    virtual void show_menu(Rental_system &rental_system, const std::string &username) override;
    virtual void add_vehicle_to_rented(std::shared_ptr<Vehicle> vehicle) override;
    virtual void write_data_to_file(std::ostream &file) override;
    virtual ~Admin() {}
};
#endif