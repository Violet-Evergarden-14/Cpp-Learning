#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "date.h"
#include "accumulator.h"
#include <string>

class Account {
private:
	std::string id;
	double balance;
	static double total;
protected:
	Account(const Date& _date, const std::string _id);
	void record(const Date& date, double amount, const std::string& desc);
	void error(const std::string& msg) const;
public:
	const std::string& get_id() const {return id;}
	double get_balance() const {return balance;}
	static double get_total() {return total;}
	void show() const;
};

class SavingsAccount: public Account {
private:
	Accumulator acc;
	double rate;
public:
	SavingsAccount(const Date& _date, const std::string& _id, double _rate);
	double get_rate() const {return rate;}
	void deposit(const Date& date, double amount, const std::string& desc);
	void withdraw(const Date& date, double amount, const std::string& desc);
	void settle(const Date& date);
};

class CreditAccount: public Account {
private:
	Accumulator acc;
	double credit;
	double rate;
	double fee;
	double get_debt() const {
		double balance = get_balance();
		return balance < 0 ? balance : 0;
	}
public:
	CreditAccount(const Date& _date, const std::string& _id, double _credit, double _rate, double _fee);
	double get_credit() const {return credit;}
	double get_rate() const {return rate;}
	double get_fee() const {return fee;}
	double get_available_credit() const {return (get_balance() < 0) ? (credit + get_balance()) : credit;}
	void deposit(const Date& date, double amount, const std::string& desc);
	void withdraw(const Date& date, double amount, const std::string& desc);
	void settle(const Date& date);
	void show() const;
};

#endif