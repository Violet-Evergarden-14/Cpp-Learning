#include <iostream>
#include <string>
using namespace std;

class exam_information
{
private:
	string name;
	enum {
		GRADE, PASS, PERCENTAGE
	} mode;

	union
	{
		char grade;
		bool pass;
		int percent;
	};
	
public:
	exam_information(string _name, char _grade) : name(std::move(_name)), grade(std::move(_grade)), mode(GRADE) {};
	exam_information(string _name, bool _pass) : name(std::move(_name)), pass(std::move(_pass)), mode(PASS) {};
	exam_information(string _name, int _percent) : name(std::move(_name)), percent(std::move(_percent)), mode(PERCENTAGE) {};
	
	void show_grade();
};

void exam_information::show_grade()
{
	cout << name << " : ";
	switch (mode)
	{
	case GRADE:
		cout << grade;
		break;
	case PASS:
		cout << (pass ? "PASS" : "FAIL");
		break;
	case PERCENTAGE:
		cout << percent;
		break;
	default:
		break;
	}
	cout << endl;
}

int main()
{
	exam_information course1("Math", 76);
	course1.show_grade();
}