#include <iostream>
#include "Customer.h"

Customer::Customer(const std::string &username, const std::string &password, 
        const std::string &name, const std::string &contact_information)
            :User(username, password, name, contact_information) {}

void Customer::show_rented_vehicles() const {
    std::cout << "Number of rented vehicles: " << m_rented_vehicles.size() << '\n';
    int i{};
    for (const auto &veh : m_rented_vehicles) {
        std::cout << "###" << i << "###\n";
        veh->show();
        i++;
    }
}
int Customer::get_rented_vehicles_size() const {
    return m_rented_vehicles.size();
}
void Customer::add_vehicle_to_rented(std::shared_ptr<Vehicle> vehicle) {
    m_rented_vehicles.push_back(vehicle);
}
std::shared_ptr<Vehicle> Customer::get_rented_vehicle(const int index) {
    if (index < 0 || index >= m_rented_vehicles.size())
        throw std::out_of_range("Index is out of range for rented vehicles.");
    return m_rented_vehicles[index];
}
void Customer::remove_vehicle_from_rented(const int index) {
    if (index < 0 || index >= m_rented_vehicles.size())
        throw std::out_of_range("Vehicle`s index is out of range");
    m_rented_vehicles[index]->set_rent_status(false);
    m_rented_vehicles.erase(m_rented_vehicles.begin() + index);
}
void Customer::write_data_to_file(std::ostream &file) {
    file << "Customer ";
    write_user_data_to_file(file);
    file << '\n';
}
void Customer::show_menu(Rental_system &rental_system, const std::string &username) {
    enum MENU {
        EXIT,
        SHOW,
        SHOW_OWN_RENTED_VEHICLES,
        RENT,
        RETURN,
    };
    int k{};
    do {
        std::cout << "MENU.\n"
        << EXIT << ". Exit.\n"
        << SHOW << ". Display vehicles.\n"
        << SHOW_OWN_RENTED_VEHICLES << ". Show own rented vehicles.\n"
        << RENT << ". Rent vehicle.\n"
        << RETURN << ". Return rented vehicle.\n"
        
        << "Choice: ";
        std::cin >> k;
        system("clear");
        switch(k) {
        case EXIT:
            std::cout << "Goodbye.\n";
            break;
        case SHOW:
            rental_system.show();
            break;
        case SHOW_OWN_RENTED_VEHICLES:
            std::cout << "YOUR rented vehicles.\n\n";
            show_rented_vehicles();
            break;
        case RENT: {
            rental_system.show();
            std::cout << "Enter vehicle`s number to rent it: ";
            int index{};
            std::cin >> index;
            try {
                rental_system.rent_vehicle(username, index);
                rental_system.save_history();
                rental_system.save_rented_vehicles();
                std::cout << "Vehicle #" << index << " has been rented successfuly\n";
            } catch (std::out_of_range &ex) {
                std::cerr << "Failed to rent vehicle. " << ex.what() << '\n';
            } catch (std::logic_error &ex) {
                std::cerr << "Failed to rent vehicle. " << ex.what() << '\n';
            } catch (std::runtime_error &ex) {
                std::cerr << "Failed to rent vehicle. " << ex.what() << '\n';
            }
            break;
        }
        case RETURN: {
            show_rented_vehicles();
            std::cout << "Enter vehicle`s number to return it: ";
            int index{};
            std::cin >> index;
            try {
                rental_system.return_vehicle(username, index);
                rental_system.save_history();
                rental_system.save_rented_vehicles();
                std::cout << "Returned successfuly.\n";
            } catch (std::out_of_range &ex) {
                std::cerr << "Failed to return vehicle. " << ex.what() << '\n';
            } catch (std::runtime_error &ex) {
                std::cerr << "Failed to return vehicle. " << ex.what() << '\n';
            } catch (std::logic_error &ex) {
                std::cerr << "Failed to return vehicle. " << ex.what() << '\n';
            } 
            break;
        }

        }
    } while (k != EXIT);
}