#include <iostream>
#include "Admin.h"
#include "functions.h"
Admin::Admin(const std::string &username, const std::string &password, 
    const std::string &name, const std::string &contact_information)
        :User(username, password, name, contact_information) {}
void Admin::add_vehicle_to_rented(std::shared_ptr<Vehicle> vehicle) {
    throw std::runtime_error("Admin cannot rent vehicles!");
}

void Admin::write_data_to_file(std::ostream &file) {
    //file << "Admin " << m_username << " " << m_password << m_name << m_contact_information << '\n';
    file << "Admin ";
    write_user_data_to_file(file);
    file << '\n';
}

void Admin::show_menu(Rental_system &rental_system, const std::string &username) {
    enum MENU {
        EXIT,
        SHOW_VEHICLES,
        SHOW_USERS,
        DISPLAY_HISTORY,
        ADD_VEH,
        DELETE_VEH,
        CHANGE_VEH_INFO,

    };
    int k{};
    do {
        std::cout << "MENU:\n"
        << EXIT << ". Exit.\n"
        << SHOW_VEHICLES << ". Display all cars.\n"
        << SHOW_USERS << ". Display all users.\n"
        << DISPLAY_HISTORY << ". Display users history.\n"
        << ADD_VEH << ". Add vehicle.\n"
        << DELETE_VEH << ". Delete vehicle.\n"
        << CHANGE_VEH_INFO << ". Change vehicle`s info.\n"

        << "Choice: ";
        std::cin >> k;
        system("clear");
        switch (k) {
        case EXIT:
            std::cout << "Goodbye!\n";
            break;
        case SHOW_VEHICLES:
            rental_system.show();
            break;
        case SHOW_USERS:
            std::cout << "All Users.\n";
            rental_system.show_users();
            break;
        case DISPLAY_HISTORY:
            std::cout << "Users History.\n";
            rental_system.show_history();
            break;
        case ADD_VEH: {
            std::cout << "Vehicle addition.\n" 
            << "Type: ";
            std::string type{};
            std::cin >> type;
            std::cout << "Brand: ";
            std::string brand{};
            std::cin >> brand;
            std::cout << "Model: ";
            std::string model{};
            std::cin >> model;
            std::cout << "Fuel type: ";
            std::string fuel_type{};
            std::cin >> fuel_type;

            int year = valid_int_input("Manufacture year: ");
            double max_speed = valid_double_input("Max speed: ");
            double weight = valid_double_input("Weight: ");
            double mileage = valid_double_input("Mileage: ");
            double price = valid_double_input("Price: ");
            rental_system.add_vehicle(
                type, brand, model, fuel_type, year, 
                max_speed, weight, mileage, price, 0);
            try {
                rental_system.save_vehicles();
            } catch (std::runtime_error &ex) {
                std::cerr << "Failed to add vehicle. " << ex.what() << '\n';
            } catch (std::exception &ex) {
                std::cerr << "Failed to add vehicle. An unexpected error occurred: " << ex.what() << '\n';
            }
            break;
        }
        case DELETE_VEH: {
            rental_system.show();
            std::cout << "Vehicle deletion. Choose a vehicle`s number: ";
            int index{};
            std::cin >> index;
            try {
                system("clear");
                rental_system.delete_vehicle(index);
                rental_system.save_vehicles();
                system("clear");
                std::cout << "Deletion successful\n";
            } catch (std::out_of_range &ex) {
                std::cerr << "Failed to delete vehicle. " << ex.what() << '\n';
            } catch (std::logic_error &ex) {
                std::cerr << "Failed to delete vehicle. " << ex.what() << '\n';
            } catch (std::runtime_error &ex) {
                std::cerr << "Failed to delete vehicle. " << ex.what() << '\n';
            } catch (std::exception &ex) {
                std::cerr << "Failed to delete vehicle. An unexpected error occurred: " << ex.what() << '\n';
            }
            break;
        }
        case CHANGE_VEH_INFO: {
            rental_system.show();
            std::cout << "Information update. Choose a vehicle`s number: ";
            int index{};
            std::cin >> index;
            try {
                system("clear");
                rental_system.update_vehicle(index);
                rental_system.save_vehicles();
            } catch (std::out_of_range &ex) {
                std::cerr << "Failed to update vehicle. " << ex.what() << '\n';
            } catch (std::runtime_error &ex) {
                std::cerr << "Failed to update vehicle. " << ex.what() << '\n';
            } catch (std::exception &ex) {
                std::cerr << "Failed to update vehicle. An unexpected error occurred: " << ex.what() << '\n';
            }
            break;
        }
        default:
            std::cout << "There is no such choice\n";
        }
    } while(k != EXIT);
}