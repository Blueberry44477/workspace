#include <iostream>
#include <cmath>
#include "Header.h"
using namespace std;

//Вказівник *this

//class Mathem {
//private:
//	int m_value = 0;
//public:
//	Mathem(int value) :m_value{ value } {}
//	Mathem& add(int value) { m_value += value; return *this; }
//	Mathem& sub(int value) { m_value -= value; return*this; }
//	Mathem& divide(int value) { m_value /= value; return *this; }
//	int show() { return m_value; }
//};

//Статичні змінні

//class Anything {
//private:
//	int m_value = 0;
//	static int s_value;
//public:
//	static int get_value() { return s_value; }
//};
//int Anything::s_value = 5;

//Дружні функції
//class Humidity;
//class Temperature {
//private:
//	int m_temp = 0;
//public:
//	Temperature(int temp) :m_temp{ temp } {}
//	friend void show_weather(Temperature &temperature, Humidity &humidity);
//};
//class Humidity {
//private:
//	int m_humidity = 0;
//public:
//	Humidity(int humidity) :m_humidity{ humidity } {}
//	friend void show_weather(Temperature& temperature, Humidity& humidity);
//};
//void show_weather(Temperature& temperature, Humidity& humidity) {
//	cout << temperature.m_temp << humidity.m_humidity;
//}

//Дружні класи
//class Values;  // попереднє оголошення класу Values
//class Display {
//private:
//	bool m_display_int_first;
//public:
//	Display(bool display_int_first) :m_display_int_first{ display_int_first } {}
//	void show(Values& object); // вищенаведене попереднє оголошення необхідне для цього рядка
//};
//class Values { // повне визначення класу Values
//private:
//	int m_int_value = 0;
//	double m_double_value = 0;
//public:
//	Values(int int_value, double double_value)
//		:m_int_value{ int_value }, m_double_value{ double_value } {}
//	friend void Display::show(Values& object);
//};
//// Тепер ми можемо визначити метод Display::displayItem(), якому потрібно побачити повне визначення класу Values
//void Display::show(Values& object) {
//	if (m_display_int_first == true)
//		cout << object.m_int_value << ' ' << object.m_double_value;
//	else
//		cout << object.m_double_value << ' ' << object.m_int_value;
//}


//Анонімні об'єкти класу
//class Something {
//private:
//	int m_value = 0;
//public:
//	Something(int value) :m_value{ value } {}
//	int get_value()const { return m_value; }
//};
//void print(const Something& object) {
//	cout << object.get_value();
//}
//Something something_add(const Something& v1, const Something& v2) {
//	return Something(v1.get_value() + v2.get_value());
//}


//Вкладені типи даних у класах 
//class Fruit {
//public:
//	enum Fruit_list {
//		AVOCADO,
//		BLACKBERRY,
//		LEMON
//	};
//private:
//	Fruit_list m_type;
//public:
//	Fruit(Fruit_list type) :m_type{ type } {}
//	Fruit_list get_type() { return m_type; }
//};

//Завдання 1
//class Point {
//private:
//	double m_x = 0;
//	double m_y = 0;
//public:
//	Point(double x, double y) :m_x{ x }, m_y{ y }{}
//	Point() :Point(0, 0) {}
//	void print() {
//		cout << "Point (" << m_x << ", " << m_y << ")\n";
//	}
//	double distance_to(const Point& object) const  {
//		return sqrt((object.m_x - m_x) * (object.m_x - m_x) + (object.m_y - m_y) * (object.m_y - m_y));
//	}
//	friend double distance(const Point& point1, const Point& point2);
//};
//double distance(const Point& point1, const Point& point2) {
//	return sqrt((point2.m_x - point1.m_x) * (point2.m_x - point1.m_x) + (point2.m_y - point1.m_y) * (point2.m_y - point1.m_y));
//}


//завдання 3
class Monster {
public:
	enum Monster_type {
		DRAGON,
		GOBLIN,
		OGRE,
		ORC,
		SKELETON,
		TROLL,
		VAMPIRE,
		ZOMBIE,
		MAX_MONSTER_TYPES
	};
private:
	Monster_type m_type;
	string m_name;
	int m_health = 0;
public:
	Monster(Monster_type type, string name, int health) 
		:m_type { type }, m_name{ name }, m_health{ health }{}
	string get_string_type()const {
		switch (m_type) {
		case DRAGON: return "dragon";
		case GOBLIN: return "goblin";
		case OGRE: return "ogre";
		case ORC: return "orc";
		case SKELETON: return "skeleton";
		case TROLL: return "troll";
		case VAMPIRE: return "vampire";
		case ZOMBIE: return "zombie";
		case MAX_MONSTER_TYPES: return "error!";
		default: return "Error!";
		}
	}
	void print() {
		cout << m_name << " is the " << get_string_type() << " that has " << m_health << " health points.";
	}
};
class Monster_generator {
public:
	static Monster generate_monster() {
		Monster::Monster_type type = static_cast<Monster::Monster_type>(get_random_number(0, Monster::MAX_MONSTER_TYPES - 1));
		int health = get_random_number(1, 100);

		static std::string s_names[6]{ "John", "Brad", "Alex", "Thor", "Hulk", "Asnee" };
		return Monster(type, s_names[get_random_number(0, 5)], health);
	}
	static int get_random_number(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}
};

int main() {
	srand(static_cast<unsigned int>(time(0))); // використовуємо системний годинник в якості стартового значення
	rand();
	Monster m = Monster_generator::generate_monster();
	m.print();


	//Mathem operation(5);
	//operation.add(5).sub(3).divide(2);
	//std::cout << operation.show();

	///*Date date1(0, 0, 0);
	//Date date2;
	//Date date3;
	//cout << date1.get_id() << '\n';
	//cout << date2.get_id() << '\n';
	//cout << date3.get_id() << '\n';

	//cout << Anything::get_value();*/

	/*Temperature temp(30);
	Humidity hum(11);
	show_weather(temp, hum);
	return 0;*/

	/*Values value(5, 10.5);
	Display display_int_first(true);
	display_int_first.show(value);*/

	//print(Something(5));
	//cout << something_add(Something(3), Something(6)).get_value();

	/*Fruit fruit(Fruit::AVOCADO);
	if (fruit.get_type() == Fruit::AVOCADO)
		cout << "I am avocado";
	else
		cout << "I am not avocado";*/

	//Завдання 1
	/*Point first;
	Point second(2.0, 5.0);
	first.print();
	second.print();
	cout << first.distance_to(second) << '\n';
	cout << "Distance: " << distance(first, second);*/

	return 0;
}