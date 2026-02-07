#include "account.h"
#include <cmath>
#include <iostream>
using namespace std;

double savings_account::total = 0;

savings_account::savings_account(const Date &_date, const std::string _id, double _rate)
	: id(_id), balance(0), rate(_rate), last_date(_date), accumulation(0) {
		last_date.show();
		cout << "\t#" << id << "created" << endl;
	}

void savings_account::record(const Date &date, double amount, const std::string &desc) {
	accumulation = accumulate(date);
	last_date = date;
	amount = floor(amount * 100 + 0.5) / 100;
	balance += amount;
	total += amount;
	date.show();
	cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

void savings_account::error(const std::string &msg) const {
	cout << "Error(#" << id << ")" << msg << endl;
}

void savings_account::deposit(const Date &date, double amount, const std::string &desc) {
	record(date, amount, desc);
}

void savings_account::withdraw(const Date &date, double amount, const std::string &desc) {
	if (amount > get_balance()) {
		error("not enough money");
	} else {
		record(date, -amount, desc);
	}
}

void savings_account::settle(const Date &date) {
	double interest = accumulate(date) * rate / date.distance(Date(date.get_year() - 1, 1, 1));
	if (interest != 0) {
		record(date, interest, "interest");
	}
	accumulation = 0;
}

void savings_account::show() const{
	cout << id << "\tBalance:" << balance;
}