#pragma once
#ifndef HEADER_H
#define HEADER_H
class Date {
private:
	int m_day = 0;
	int m_month = 0;
	int m_year = 0;
	static int s_id_generator;
	int m_id = 0;
public:
	Date(int day, int month, int year);
	Date();
	void set_date(int day, int month, int year);
	void show();
	int get_value() const;
	int get_id() const;
};
#endif
