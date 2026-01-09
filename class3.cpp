#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Person
{
public:
	char* name;

	Person()
	{
		name = new char[20];
		strcpy(name, "ahhh");
	}

	Person(const Person& ps)  //申请新内存
	{
		this->name = new char[20];
		strcpy(name, ps.name);
	}
};



int main()
{
	Person p1;
	Person p2 = p1;

	cout << p1.name << endl;
	cout << p2.name << endl;

	delete[] p1.name;
	p1.name = nullptr;

	delete[] p2.name;
	p2.name = nullptr;
}