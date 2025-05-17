#ifndef USER_H
#define USER_H

#include <string>
#include "Rental_system.h"
class Rental_system;
class User {
protected:
    std::string m_username;
    std::string m_password;
    std::string m_name;
    std::string m_contact_information;
public:
    User(const std::string &username, const std::string &password, 
    const std::string &name, const std::string &contact_information)
        :m_username{username}, m_password{password}, 
        m_name{name}, m_contact_information{contact_information} {}
    virtual void show_menu(Rental_system &rental_system, const std::string &username) = 0;
    virtual void add_vehicle_to_rented(std::shared_ptr<Vehicle> vehicle) = 0;
    virtual void write_data_to_file(std::ostream &file) = 0;
    virtual ~User() {}
    void write_user_data_to_file(std::ostream &file) {
        file << m_username << " " << m_password << " " << m_name << " " << m_contact_information;
    }
    void display_user_info() const {
        std::cout << m_username << " " << m_password << " " << m_name << " " << m_contact_information; 
    }
    std::string get_username() const { return m_username; }
    std::string get_password() const { return m_password; }
    std::string get_name() const { return m_name; }
    std::string get_contact_info() const { return m_contact_information; }
};

#endif