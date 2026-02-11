#include <iostream>
using namespace std;

class Base1
{
public:
	Base1(int j) {cout << "Constructing base1..." << j << endl;}
};

class Base2 {
public:
	Base2(int j) {cout << "Constructing base2..." << j << endl;}
};

class Base3 {
public:
	Base3() {cout << "Constructing base3..." << endl;}
};

class Derived: public Base2, public Base1, public Base3 {
private:
	Base1 member1;
	Base2 member2;
	Base3 member3;
public:
	Derived(int a, int b, int c, int d): Base1(a), member2(d), member1(c), Base2(b) {}
};

int main()
{
	Derived obj(1, 2, 3, 4);
}