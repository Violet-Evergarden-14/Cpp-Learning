#include <iostream>
using namespace std;

class Cat
{
private:
	static int num_of_cats;
public:
	Cat() {num_of_cats++;};
	~Cat() {num_of_cats--;};
	static int get_num() {return num_of_cats;}
};

int Cat::num_of_cats = 0;

int main()
{
	cout << Cat::get_num() << endl;
	Cat a;
	Cat b;
	cout << Cat::get_num() << endl;
}
