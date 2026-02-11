#include "account.h"
#include <cmath>
#include <iostream>
using namespace std;

double Account::total = 0;

Account::Account(const Date& _date, const std::string _id): id(_id), balance(0) {
	_date.show();
	cout << "\t#" << id << " created" << endl;
}

void Account::record(const Date& date, double amount, const std::string& desc) {
	amount = floor(amount * 100 + 0.5) / 100;
	balance += amount;
	total += amount;
	date.show();
	cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

void Account::error(const std::string& msg) const {cout << "Error(#" << id << "):" << msg << endl;}

void Account::show() const {cout << id << "\tBalance:" << balance;}

SavingsAccount::SavingsAccount(const Date& _date, const std::string& _id, double _rate): Account(_date, _id), rate(_rate), acc(_date, 0) {}

void SavingsAccount::deposit(const Date& date, double amount, const std::string& desc) {
	record(date, amount, desc);
	acc.change(date, get_balance(), "savings_account");
}

void SavingsAccount::withdraw(const Date& date, double amount, const std::string& desc) {
	if (amount > get_balance()) {
		error("Not enough money");
	} else {
		record(date, -amount, desc);
		acc.change(date, get_balance(), "savings_account");
	}
}

void SavingsAccount::settle(const Date& date) {
	double interest = acc.get_sum(date, "savings_account") * rate / date.distance(Date(date.get_year() - 1, 1, 1));
	if (interest != 0) {record(date, interest, "interest");}
	acc.reset(date, get_balance());
}

CreditAccount::CreditAccount(const Date& _date, const std::string& _id, double _credit, double _rate, double _fee): Account(_date, _id), credit(_credit), rate(_rate), fee(_fee), acc(_date, 0) {}

void CreditAccount::deposit(const Date& date, double amount, const std::string& desc) {
	record(date, amount, desc);
	acc.change(date, get_balance(), "credit_account");
}

void CreditAccount::withdraw(const Date& date, double amount, const std::string& desc) {
	if (amount - get_balance() > credit) {
		error("Not enough credit");
	} else {
		record(date, -amount, desc);
		acc.change(date, get_debt(), "credit_account");
	}
}

void CreditAccount::settle(const Date& date) {
	double interest = acc.get_sum(date, "credit_account") * rate;
	if (interest != 0) {record(date, interest, "interest");}
	if (date.get_month() == 1) {record(date, -fee, "annual fee");}
	acc.reset(date, get_debt());
}

void CreditAccount::show() const {
	Account::show();
	cout << "\tAvailable credit:" << get_available_credit();
}