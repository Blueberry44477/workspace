#include "Header.h"
#include <iostream>
int Date::s_id_generator = 0;
Date::Date(int day, int month, int year) :m_day{ day }, m_month{ month }, m_year{ year } {
	m_id = s_id_generator++;
}
Date::Date() : Date(0, 0, 0) {}
void Date::set_date(int day, int month, int year) {
	m_day = day;
	m_month = month;
	m_year = year;
}
void Date::show() {
	std::cout << m_day << "." << m_month << "." << m_year;
}
int Date::get_value() const {
	return m_day;
}
int Date::get_id() const {
	return m_id;
}