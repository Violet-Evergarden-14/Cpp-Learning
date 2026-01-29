#include <iostream>
using namespace std;

class B;
class A
{
private:
	B& b;
public:
	A(B& _b):b(_b){};
	void method();
};



class B
{
private:
	int m = 0;
public:
	void just_do_it() {cout << 1;};
};
void A::method()
	{
		b.just_do_it();
	}
int main()
{
	B b;
	A a(b);
	a.method();
}