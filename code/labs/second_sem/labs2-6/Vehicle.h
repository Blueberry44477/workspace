#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
class Vehicle {
private:
    static int m_count;
    std::string m_type;
    std::string m_brand;
    std::string m_model;
    std::string m_fuel_type;
    int m_year;
    double m_max_speed;
    double m_weight;
    double m_mileage;
    double m_price;
    bool m_rent_status;
public:
    Vehicle(const std::string &type, 
        const std::string &brand,
        const std::string &model,
        const std::string &fuel_type,
        int year,
        double max_speed,
        double weight,
        double mileage,
        double price,
        bool is_rented = false);
    ~Vehicle();
    static int get_count();
    void show() const;
    void numbered_show() const;
    void wright_data_to_file(std::ostream &file);
    void update_vehicle();
    std::string get_info() const;
    void set_rent_status(const bool value);
    bool get_rent_status() const;
    const std::string get_brand() const {
        return m_brand;
    }
    const std::string get_model() const {
        return m_model;
    }
    const int get_year() const {
        return m_year;
    }

    // Vehicle(const Vehicle &other);
    // Vehicle(Vehicle &&other) noexcept;
    // Vehicle &operator=(const Vehicle &rhs);
    // void show() const;
};

#endif