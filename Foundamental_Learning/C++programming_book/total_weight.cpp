#include <iostream>
using namespace std;

class Car;

class Boat
{
private:
	int weight;
public:
	Boat(int _weight) : weight(_weight) {};
	friend void get_total_weight(const Boat &b, const Car &c);
};

class Car
{
private:
	int weight;
public:
	Car(int _weight) : weight(_weight) {};	
	friend void get_total_weight(const Boat &b, const Car &c);
};

void get_total_weight(const Boat &b, const Car &c) {
	cout << b.weight + c.weight << endl;
}

int main()
{
	Boat b(10);
	Car c(12);
	Car c1(50);
	get_total_weight(b, c1);
}