#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <stdexcept>
#include "Rental_system.h"
#include "Customer.h"
#include "Admin.h"
#include <algorithm>

Rental_system::Rental_system(
    const std::string &vehicles_file_name, 
    const std::string &history_file_name,
    const std::string &users_file_name,
    const std::string &rented_vehicles_file_name)
        : m_vehicles_file_name{vehicles_file_name}, 
        m_history_file_name{history_file_name},
        m_users_file_name{users_file_name},
        m_rented_vehicles_file_name{rented_vehicles_file_name}
{
    try {
        Rental_system::load_history();
        Rental_system::load_vehicles();
        Rental_system::load_users();
        Rental_system::load_rented_vehicles();
    } catch (std::runtime_error &ex) {
        std::cerr << "Failed to read data. " << ex.what() << '\n';
    }
}

Rental_system::~Rental_system() { 
    if (!m_vehicles.empty()) {
        try {
        Rental_system::save_vehicles(); 
        } catch (std::runtime_error &ex) {
        std::cerr << "Failed to save vehicles in Rental_system destructor. " << ex.what() << '\n';
        }
    }
    if (!m_users.empty()) {
        try {
            Rental_system::save_users();
        } catch (const std::runtime_error &ex) {
            std::cerr << "Failed to save users in Rental_system destructor. " << ex.what() << '\n';
        }
    }
}

void Rental_system::main_menu() {
    enum MENU {
        LOGIN,
        REGISTER,
        EXIT,
    };
    int k{};
    do {
        std::cout << "Main Menu.\n"
        << LOGIN << ". Login.\n"
        << REGISTER << ". Register\n"
        << EXIT << ". Exit\n"
        << "Choice: ";
        std::cin >> k;

        switch (k) {
            case LOGIN: {
                system("clear");
                std::string username{}, password{};
                std::cout << "LOGIN.\n";
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;

                try {
                    auto user = login_user(username, password);
                    system("clear");
                    std::cout << "Login successful\n";
                    user->show_menu(*this, username);
                } catch (std::invalid_argument &ex) {
                    std::cerr << "Login failed. " << ex.what() << '\n';
                } catch (std::runtime_error &ex) {
                    std::cerr << "Login failed. " << ex.what() << '\n';
                }
                break;
            }
            case REGISTER: {
                std::string username{}, password{}, name{}, contact_info{};
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                std::cout << "Enter name: ";
                std::cin >> name;
                std::cout << "Enter contact information: ";
                std::cin >> contact_info;
                try {
                    register_customer(username, password, name, contact_info);
                    save_users();
                    system("clear");
                    std::cout << "Registration successful!\n";
                } catch (const std::invalid_argument &ex) {
                    std::cout << "Registration failed. " << ex.what() << "\n";
                } catch (std::runtime_error &ex) {
                    std::cerr << "Registration failed. " << ex.what() << '\n';
                }
                break;
            }
            case EXIT:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (k != EXIT);
}

//DISPLAY-----------------------------
void Rental_system::show() const {
    std::cout << "Number of vehicles: " << Vehicle::get_count() << "\n\n";
    int i{};
    for (const auto &vehicle: m_vehicles) {
        std::cout << "# " << i << '\n';
        vehicle->show();
        i++;
    }
}
void Rental_system::show(int index) const {
    if(index > 0 || index < m_vehicles.size()) {
        std::cout << "### " << index << " ###\n";
        m_vehicles[index]->numbered_show();
    } else {
        std::cout << "No car with number \"" << index << "\"\n";
    }
}
void Rental_system::show_users() const {
    int i{};
    for (const auto &user : m_users) {
        std::cout << i << ". ";
        user->display_user_info();
        std::cout << '\n';
        //std::cout << i << ". " << user->get_username() << " " << user->get_password() << '\n';
        i++;
    }
}
void Rental_system::show_history() const {
    for (const auto& [username, actions] : m_history) {
        std::cout << "User: " << username << "\n";
        std::cout << "Actions:\n";
        int i{};
        for (const auto &action : actions) {
            std::cout << "#" << i << " " << action << '\n';
            i++;
        }
        std::cout << '\n';
    }
}
//USERS
void Rental_system::register_customer(const std::string &username, const std::string &password, 
        const std::string &name, const std::string &contact_information) {
    if (username.empty() || password.empty() || name.empty() || contact_information.empty()) {
        throw std::invalid_argument("One or more of the entered values are empty.");
    }
    auto new_customer = std::make_shared<Customer>(username, password, name, contact_information);
    add_user(new_customer);
}

std::shared_ptr<User> Rental_system::login_user(const std::string& username, const std::string& password) {
    if (username.empty() || password.empty()) {
        throw std::invalid_argument("Username and password cannot be empty.");
    }
    auto it = std::find_if(m_users.begin(), m_users.end(),
        [&username](const std::shared_ptr<User>& user) {
            return user->get_username() == username;
        });
    if (it == m_users.end()) {
        throw std::runtime_error("User not found!");
    }
    if ((*it)->get_password() != password) {
        throw std::runtime_error("Incorrect password!");
    }
    return *it;
}
void Rental_system::add_user(std::shared_ptr<User> user) {
    auto it = std::find_if(m_users.begin(), m_users.end(),
        [&user](const std::shared_ptr<User>& u) {
            return u->get_username() == user->get_username();
        });
    if (it != m_users.end()) {
        throw std::runtime_error("User with username " + user->get_username() + " already exists!");
    }
    m_users.push_back(user);
}
//VEHICLES
void Rental_system::add_vehicle(
        const std::string &type, const std::string &brand,
        const std::string &model, const std::string &fuel_type,
        int year, double max_speed, double weight, double mileage, double price, bool rent_status) 
{
        auto vehicle = std::make_shared<Vehicle>(
            type, brand, model, fuel_type, year, 
            max_speed, weight, mileage, price, rent_status);
        m_vehicles.push_back(vehicle);
}
std::shared_ptr<Vehicle> Rental_system::find_vehicle(const std::string &brand, 
    const std::string &model, const int year) const 
{
    auto it = std::find_if(m_vehicles.begin(), m_vehicles.end(),
            [&](const std::shared_ptr<Vehicle>& vehicle) {
                bool matches = true;
                if (!brand.empty() && vehicle->get_brand() != brand) {
                    matches = false;
                }
                if (!model.empty() && vehicle->get_model() != model) {
                    matches = false;
                }
                if (year != -1 && vehicle->get_year() != year) {
                    matches = false;
                }
                return matches;
            });
        return (it != m_vehicles.end()) ? *it : nullptr;
}
void Rental_system::delete_vehicle(int index) {
    if (index < 0 || index >= m_vehicles.size())
        throw std::out_of_range("Vehicle`s index is out of range");
    if (!m_vehicles[index]->get_rent_status()) {
        m_vehicles.erase(m_vehicles.begin() + index);
    } else {
        throw std::logic_error("Attempted to erase rented vehicle");
    }
}
void Rental_system::update_vehicle(const int index) {
    if (index < 0 || index >= m_vehicles.size())
        throw std::out_of_range("Vehicle`s index is out of range.");
    m_vehicles[index]->update_vehicle();
}
void Rental_system::rent_vehicle(const std::string &username, const int index) {
    if (index < 0 || index >= m_vehicles.size())
        throw std::out_of_range("Vehicle`s index is out of range");
    if (m_vehicles[index]->get_rent_status() == true)
        throw std::logic_error("Attempted to rent a rented vehicle");

    auto user_it = std::find_if(m_users.begin(), m_users.end(),
        [&username](const std::shared_ptr<User>& user) {
            return user->get_username() == username;
        });
    if (user_it == m_users.end()) {
        throw std::runtime_error("User not found!");
    }

    m_vehicles[index]->set_rent_status(true);
    (*user_it)->add_vehicle_to_rented(m_vehicles[index]);
    m_history[username].push_back("Rented vehicle: " + m_vehicles[index]->get_info());
}
void Rental_system::return_vehicle(const std::string &username, const int index) {
    auto user_it = std::find_if(m_users.begin(), m_users.end(),
        [&username](const std::shared_ptr<User>& user) {
            return user->get_username() == username;
        });
    if(user_it == m_users.end()) {
        throw std::runtime_error("User not found!");
    }
    auto customer = std::dynamic_pointer_cast<Customer>(*user_it);
    if(!customer) {
        throw std::logic_error("Admins cannot return vehicles!");
    }
    if(index < 0 || index >= customer->get_rented_vehicles_size())
        throw std::out_of_range("Vehicle`s index is out of range");
    auto vehicle = customer->get_rented_vehicle(index);
    customer->remove_vehicle_from_rented(index);
    m_history[username].push_back("Returned vehicle: " + vehicle->get_info());
}

//FILES---------------------------------------------------
void Rental_system::load_vehicles() {
    std::ifstream file(m_vehicles_file_name);
    if(!file.is_open())
        throw std::runtime_error("Failed to open file: " + m_vehicles_file_name);
    file.seekg(0, std::ios::end);
    if(file.tellg() == 0) 
        throw std::runtime_error("File is empty: " + m_vehicles_file_name);
    file.seekg(0, std::ios::beg);
    std::string type{}, brand{}, model{}, fuel_type{};
    int year{};
    double max_speed, weight{},price{}, mileage{};
    bool rent_status{};
    while(file >> type >> brand >> model >> fuel_type >> year >> max_speed
            >> weight >> price >> mileage >> rent_status) {
    auto vehicle = std::make_shared<Vehicle>(
        type, brand, model, fuel_type, year, 
        max_speed, weight, price, mileage, rent_status);
    m_vehicles.push_back(vehicle);
    }
    file.close();
}
void Rental_system::save_vehicles() const {
    std::ofstream file(m_vehicles_file_name);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open vehicles file for writing");
    }
    for (const auto &veh : m_vehicles) {
        veh->wright_data_to_file(file);
    }
    file.close();
}
void Rental_system::load_users() {
    std::ifstream file(m_users_file_name);
    if(!file.is_open())
        throw std::runtime_error("Failed to open file: " + m_users_file_name);
    file.seekg(0, std::ios::end);
    if(file.tellg() == 0)
        throw std::runtime_error("File is empty: " + m_users_file_name);
    file.seekg(0, std::ios::beg);
    std::string user_type{}, username{}, password{}, name{}, contact_information{};
    while(file >> user_type >> username >> password >> name >> contact_information) {
        if (user_type == "Admin") {
            auto admin = std::make_shared<Admin>(username, password, name, contact_information);
            m_users.push_back(admin);
        } else if (user_type == "Customer") {
            auto customer = std::make_shared<Customer>(username, password, name, contact_information);
            m_users.push_back(customer);
        }
    }
    file.close();
}
void Rental_system::save_users() const {
    std::ofstream file(m_users_file_name);
    if (!file.is_open())
        throw std::runtime_error("Failed to open users file for writing");
    for (const auto &user : m_users) 
        user->write_data_to_file(file);
    file.close();
}
void Rental_system::save_history() const {
    std::ofstream file(m_history_file_name);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open history file for writing.");
    }
    for (const auto& [username, actions] : m_history) {
        for (const auto& action : actions) {
            file << username << " " << action << "\n";
        }
    }
    file.close();
}
void Rental_system::load_history() {
    std::ifstream file(m_history_file_name);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + m_history_file_name);
    }
    std::string line;
    while (std::getline(file, line)) {
        int space_position = line.find(' ');
        std::string username = line.substr(0, space_position);
        std::string action = line.substr(space_position + 1);
        m_history[username].push_back(action);
    }
    file.close();
}
void Rental_system::save_rented_vehicles() const {
    std::ofstream file(m_rented_vehicles_file_name);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open rented vehicles file for writing.");
    }
    for (const auto &user : m_users) {
        auto customer = std::dynamic_pointer_cast<Customer>(user);
        if (customer) {
            for (const auto &vehicle : customer->get_rented_vehicles()) {
                file << customer->get_username() << " " << vehicle->get_info() << "\n";
            }
        }
    }
    file.close();
}
void Rental_system::load_rented_vehicles() {
    std::ifstream file(m_rented_vehicles_file_name);
    if (!file.is_open())
        throw std::runtime_error("Failed to open rented vehicles file for reading.");
    file.seekg(0, std::ios::end);
    if(file.tellg() == 0)
        throw std::runtime_error("File is empty: " + m_rented_vehicles_file_name);
    file.seekg(0, std::ios::beg);
    std::string username{}, brand{}, model{};
    int year{};

    while(file >> username >> brand >> model >> year) {
        auto user_it = std::find_if(m_users.begin(), m_users.end(),
            [&username](const std::shared_ptr<User>& user) {
                return user->get_username() == username;
        });
        if (user_it != m_users.end()) {
            auto customer = std::dynamic_pointer_cast<Customer>(*user_it);
            if (customer) {
                auto vehicle = find_vehicle(brand, model, year);
                if(vehicle)
                    customer->add_vehicle_to_rented(vehicle);
            }
        }
        file.close();
    }
}