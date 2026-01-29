#include <iostream>
using namespace std;

class A
{
private:
	int x;
public:
	void display() {cout << x << endl;}
	int get_x() {return x;}
	friend class B;
};

class B
{
private:
	A a;
public:
	void display() {cout << a.x << endl;}
	void set(int i) {a.x = i;}    //可以访问A的元素
};

