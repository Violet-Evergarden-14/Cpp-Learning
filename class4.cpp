#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Person
{
private:
	/* data */
public:
	int id;
	char* name;

	Person();
	Person(const Person& ps);
	~Person();
};

Person::Person(/* args */)   //构造函数，这个操作相当于添加函数，注意要在类里面声明
{
	id = 1;
	name = new char[20];
	strcpy(name, "jiao");
}

Person::Person(const Person& ps)
{
	id = ps.id + 1;
	name = new char[20];
	strcpy(name, ps.name);
}

Person::~Person()   //析构函数，注意从后往前析构函数
{
	delete[] name;
	name = nullptr;
	cout << id << "xigou" << endl;
}

int main()
{
	Person p1;
	Person p2 = p1;

}