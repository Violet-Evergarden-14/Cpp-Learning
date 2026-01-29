#include "account.h"
#include <iostream>
#include <cmath>
using namespace std;

double savings_account::total = 0;

void savings_account::record(int date, double amount)
{
	accumulation += accumulate(date);
	amount = floor(amount * 100 + 0.5) / 100;
	balance += amount;
	last_date = date;
	total += amount;
	cout << last_date << "\t#" << id << "\t" << amount << "\t" << balance << endl;
}

savings_account::savings_account(int _date, int _id, double _rate)
	: last_date(_date), id(_id), rate(_rate)
{
	cout << last_date << "\t#" << id << " is created" << endl;
}

const void savings_account::show()
{
	cout << "#" << id << "\tBalnace: " << balance << endl;
}

void savings_account::deposit(int date, double amount)
{
	record(date, amount);
}

void savings_account::withdraw(int date, double amount)
{
	if (amount > get_balnace())
	{
		cout << "Error: not enough money" << endl;
	} else {
		record(date, -amount);
	}
	
}

void savings_account::settle(int date)
{
	double interst = (accumulation + accumulate(date)) * rate / 365;
	if (interst != 0)
	{
		record(date, interst);
	}
	accumulation = 0;
}