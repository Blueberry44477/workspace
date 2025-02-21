#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Functions.cpp"
int owner_number = 0;
const int size1 = 100;
bool already_initialized = false;
struct Cars_Owners_Information {
	char brand[size1] = {};
	char number[3000] = {};
	char color[size1] = {};
	int car_manufacture_year = 0;
	char owner_name[size1] = {};
	char address[3000] = {};
};
void Init(Cars_Owners_Information* info, int n, int c);
void Show_info_1(Cars_Owners_Information* info, int n);
void Show_info_2(Cars_Owners_Information* info, int n);
void Save(Cars_Owners_Information* info, int n);
void Read_from_file(Cars_Owners_Information* info, int n);
void Change_info(Cars_Owners_Information* info, int n);
void Add_new_info(Cars_Owners_Information* info, int n);
void Show_cars_of_the_selected_color_in_alphabetic_order(Cars_Owners_Information* info, int n, int owner_number);
#endif // !FUNCTIONS_H

