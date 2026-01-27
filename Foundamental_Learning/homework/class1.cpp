#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	int id;
	int age;
	double money;

	Person()  //初始化函数，与类名一致，没有返回值以及返回值类型（用某些方法可以知道调用的时机）
	{
		cout << "调用无参构造函数" << endl;
		id = 0;
		age = 0;
		money = 0.0;
	}  //没写这个系统默认会给一个啥都不干的函数

	Person(int _id, int _age, int _money)   //传参函数（用来重载，没有就用原始的），只有这个在创建时必须给参数
	{
		cout << "调用有参构造函数" << endl;
		id = _id;
		age = _age;
		money = _money;
	}
};

int main()
{
	//1
	Person ps;
	cout << ps.id << endl;
	cout << ps.age << endl;
	cout << ps.money << endl;

	//2
	Person ps1(1, 2, 3);
	cout << ps1.id << endl;
	cout << ps1.age << endl;
	cout << ps1.money << endl;
}