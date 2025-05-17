#ifndef RENTAL_SYSTEM_H
#define RENTAL_SYSTEM_H
#include <map>
#include <vector>
#include <memory>
#include "Vehicle.h"
#include "User.h"
class User;
class Rental_system {
private:
    std::vector<std::shared_ptr<Vehicle>> m_vehicles;
    std::vector<std::shared_ptr<User>> m_users;
    std::map<std::string, std::vector<std::string>> m_history;

    std::string m_vehicles_file_name;
    std::string m_users_file_name;
    std::string m_history_file_name;
    std::string m_rented_vehicles_file_name;
public:
    Rental_system(
        const std::string &vehicles_file_name = "Vehicles.txt",
        const std::string &history_file_name = "History.txt",
        const std::string &users_file_name = "Users.txt",
        const std::string &rented_vehicles_file_name = "Rented_vehicles.txt"
    );
    ~Rental_system();
    
    void main_menu();
    int get_vehicles_size() const {
        return m_vehicles.size();
    }
    //DISPLAY-----------------------------------------
    void show_users() const;
    void show_history() const;
    void show() const;
    void show(int index) const;

    std::shared_ptr<Vehicle> find_vehicle(const std::string &brand, 
    const std::string &model, const int year) const;

    //USERS
    void register_customer(const std::string &username, const std::string &password, 
        const std::string &name, const std::string &contact_information);
    std::shared_ptr<User> login_user(const std::string& username, const std::string& password);
    void add_user(std::shared_ptr<User> user);
    
    //USER ACTIONS
    void rent_vehicle(const std::string &username, const int index);
    void return_vehicle(const std::string &username, const int index);

    //VEHICLES
    std::shared_ptr<Vehicle> create_vehicle(const std::string &type,
        const std::string &brand,
        const std::string &model,
        const std::string &fuel_type,
        int year,
        double max_speed,
        double weight,
        double mileage,
        double price,
        bool rent_status);

    void add_vehicle(
        const std::string &type,
        const std::string &brand,
        const std::string &model,
        const std::string &fuel_type,
        int year,
        double max_speed,
        double weight,
        double mileage,
        double price,
        bool rent_status);
    void delete_vehicle(int index);
    void update_vehicle(int index);

    //FILES-----------------------
    void save_vehicles() const;
    void load_vehicles();
    void save_users() const;
    void load_users();
    void save_history() const;
    void load_history();
    void save_rented_vehicles() const;
    void load_rented_vehicles();
};
#endif