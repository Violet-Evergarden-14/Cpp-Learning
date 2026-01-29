#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class savings_account
{
private:
	int id;
	double balance;
	double rate;
	int last_date;
	double accumulation;
	void record(int date, double amount);
	double accumulate(int date) const {return accumulation + balance * (date - last_date);};
public:
	savings_account(int _date, int _id, double _rate);
	int get_id() {return id;};
	double get_balance() {return balance;};
	double get_rate() {return rate;};
	void show() {cout << "#" << id << "\tBalance:" << balance;};
	void deposit(int date, double amount) {record(date, amount);};
	void withdraw(int date, double amount);
	void settle(int date);
};

savings_account::savings_account(int _date, int _id, double _rate)
	:last_date(_date), id(_id), rate(_rate), balance(0), accumulation(0)
{
	cout << last_date << "\t#" << id << " is created" << endl;
}

void savings_account::record(int date, double amount)
{
	accumulation = accumulate(date);
	last_date = date;
	amount = floor(amount * 100 + 0.5) / 100;
	balance += amount;
	cout << date << "\t#" << id << "\t" << amount << "\t" << balance << endl;
}


void savings_account::withdraw(int date, double amount)
{
	if (get_balance() >= amount)
		record(date, -amount);
	else {
		cout << "Error: not enough money";
	}
}

void savings_account::settle(int date)
{
	double interest = accumulate(date) * rate / 365;
	if (interest != 0)
	{
		record(date, interest);
	}
	accumulation = 0;	
}

int main()
{
	savings_account account0(1, 21325302, 0.015);
	savings_account account1(5, 58320212, 0.015);

	account0.deposit(5, 5000);
	account1.deposit(25, 10000);
	account0.deposit(45, 5500);
	account1.withdraw(60, 4000);

	account0.settle(90);
	account1.settle(90);

	account0.show();
	cout << endl;
	account1.show();
	cout << endl;
}