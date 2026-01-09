#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	int a;

	Person()
	{
		cout << "zhijie" << endl;
		a = 1;
	}

	Person(const Person &ps)  //不修改ps
	{
		cout << "kaobei" << endl;
		this->a = ps.a;
	}
};

/*
void fun(Person ps)  //这里会有一次拷贝构造，生成一个副本；不想这样，就直接拷贝（用&）
{
	cout << ps.a << endl;
}
*/

Person fun(Person& ps)
{
	cout << ps.a << endl;
	return ps;//返回时会有拷贝构造（用&消除）
}


int main()
{
	Person p;
	Person p2 = p;
	fun(p);

}