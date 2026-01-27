#include <iostream>
using namespace std;

class MyDate
{
private:
	int year;
	int month;
	int day;
public:
	void init_date()
	{
		cin >> year >> month >> day;
	}

	void show_date()
	{
		cout << "MyDate is " << year << "." << month << "." << day << "." << endl;
	}

	bool is_leap_year()
	{
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		{
			return true;
		}
		return false;
	}

	int get_year()
	{
		return year;
	}

	void set_year()
	{
		int a;
		cin >> a;
		year = a;
	}
};

int main()
{
	MyDate today;
	today.init_date();
	today.show_date();

	if (today.is_leap_year())
	{
		cout << "This year is a leap year." << endl;
	} else {
		cout << "This year is not a leap year." << endl;
	}
	today.set_year();
	
	int m = today.get_year();
	cout << m << endl;
}