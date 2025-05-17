#include <string>
#include <iostream>
#include "Vehicle.h"
#include "Empty_string_exception.h"
#include "Negative_value_exception.h"
#include "functions.h"
int Vehicle::m_count = 0;
Vehicle::Vehicle (
        const std::string &type, 
        const std::string &brand,
        const std::string &model,
        const std::string &fuel_type,
        int year,
        double max_speed,
        double weight,
        double price,
        double mileage,
        bool is_rented)
                : m_type{type}, m_brand{brand},
                m_model{model}, m_fuel_type{fuel_type}, 
                m_year{year}, m_max_speed{max_speed}, 
                m_weight{weight}, m_mileage{mileage}, 
                m_price{price}, m_rent_status{is_rented} 
{
        //if(m_type.empty() || m_brand.empty() || m_model.empty() || m_fuel_type.empty())
                //throw Empty_string_exception();
        if(m_year < 0 || m_max_speed < 0 || m_weight < 0 || m_price < 0 || m_mileage < 0)
                throw Negative_value_exception();
        
        m_count++; 
}
std::string Vehicle::get_info() const {
        return m_brand + " " + m_model + " " + std::to_string(m_year);
}

void Vehicle::show() const {
        std::cout 
        << "Type: " << m_type << '\n'
        << "Brand: " << m_brand << '\n'
        << "Model: " << m_model << '\n'
        << "Fuel type: " << m_fuel_type << '\n'
        << "Year: " << m_year << '\n'
        << "Max Speed: " << m_max_speed << '\n'
        << "Weight: " << m_weight << '\n'
        << "Mileage: " << m_mileage << '\n'
        << "PRICE PER DAY: " << m_price << '\n'
        << "Rent status: " << m_rent_status << '\n'
        << '\n';
}
void Vehicle::numbered_show() const {
        std::cout
        << "1. Type: " << m_type << '\n'
        << "2. Brand: " << m_brand << '\n'
        << "3. Model: " << m_model << '\n'
        << "4. Fuel type: " << m_fuel_type << '\n'
        << "5. Year: " << m_year << '\n'
        << "6. Max Speed: " << m_max_speed << '\n'
        << "7. Weight: " << m_weight << '\n'
        << "8. Mileage: " << m_mileage << "\n\n"
        << "9. PRICE PER DAY: " << m_price << '\n'
        << "10.Rent status: " << m_rent_status << '\n'
        << '\n';
}

void Vehicle::update_vehicle() {
        numbered_show();
        std::cout << "Enter info number: ";
        int k{};
        std::cin >> k;
        bool temp_bool;
        int temp_int;
        double temp_double;
        std::string temp_string;
        system("clear");
        switch (k) {
        case 1:
                std::cout << "Previous type: \"" << m_type << "\"\n";
                std::cout << "Enter new type: ";
                std::cin >> temp_string;
                m_type = temp_string;
                break;
        case 2:
                std::cout << "Previous brand: \"" << m_brand << "\"\n";
                std::cout << "Enter new brand: ";
                std::cin >> temp_string;
                m_brand = temp_string;
                break;
        case 3:
                std::cout << "Previous model: \"" << m_model << "\"\n";
                std::cout << "Enter new model: ";
                std::cin >> temp_string;
                m_model = temp_string;
                break;
        case 4:
                std::cout << "Previous fuel type: \"" << m_fuel_type << "\"\n";
                std::cout << "Enter new fuel type: ";
                std::cin >> temp_string;
                m_fuel_type = temp_string;
                break;
        case 5:
                std::cout << "Previous year: \"" << m_year << "\"\n";
                //std::cout << "Enter new year: ";
                // std::cin >> temp_int;
                m_year = valid_int_input("Enter new year: ");
                break;
        case 6:
                std::cout << "Previous max speed: \"" << m_max_speed << "\"\n";
                // std::cout << "Enter new max speed: ";
                // std::cin >> temp_double;
                m_max_speed = valid_double_input("Enter new max speed: ");
                break;
        case 7:
                std::cout << "Previous weight: \"" << m_weight << "\"\n";
                // std::cout << "Enter new weight: ";
                // std::cin >> temp_double;
                m_weight = valid_double_input("Enter new weight: ");
                break;
        case 8:
                std::cout << "Previous mileage: \"" << m_mileage << "\"\n";
                // std::cout << "Enter new mileage: ";
                // std::cin >> temp_double;
                m_mileage = valid_double_input("Enter new mileage: ");
                break;
        case 9:
                std::cout << "Previous price: \"" << m_price << "\"\n";
                // std::cout << "Enter new price: ";
                // std::cin >> temp_double;
                m_price = valid_double_input("Enter new price: ");
                break;
        case 10:
                std::cout << "Previous rent status: \"" << m_rent_status << "\"\n";
                std::cout << "Enter new rent status (0,1): ";
                std::cin >> temp_bool;
                m_rent_status = temp_bool;
                break;
        default:
                std::cout << "There is no such choice\n";
        }
        return;
}
void Vehicle::set_rent_status(const bool value) {
        m_rent_status = value;
}
bool Vehicle::get_rent_status() const {
        return m_rent_status;
}

void Vehicle::wright_data_to_file(std::ostream &file) {
        file 
        << m_type << " " 
        << m_brand << " "
        << m_model << " "
        << m_fuel_type << " "
        << m_year << " "
        << m_max_speed << " "
        << m_weight << " "
        << m_price << " "
        << m_mileage << " "
        << m_rent_status << '\n';
}
// Vehicle::Vehicle(const Vehicle &other)
//     : m_type{other.m_type}, m_price{other.m_price},
//         m_mileage{other.m_mileage} 
//     { 
//         m_count++; 
//     }
// Vehicle::Vehicle(Vehicle &&other) noexcept: m_type{other.m_type} {
//     other.m_type = nullptr;
// }
Vehicle::~Vehicle() { m_count--; }
// Vehicle &Vehicle::operator=(const Vehicle &rhs) {
//     if(this == &rhs)
//         return *this;
//     delete this->m_type;
//     m_type = new std::string{*rhs.m_type};
//     return *this;
// }
int Vehicle::get_count() { return m_count; }
// void Vehicle::show() const {
//     std::cout << "Type: " << *m_type 
//     << "\nPrice: " << m_price 
//     << "\nMileage: " << m_mileage << '\n';
// }
