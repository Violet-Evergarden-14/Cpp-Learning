#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "date.h"
#include <string>

class savings_account
{
private:
	std::string id;
	double balance;
	double rate;
	Date last_date;
	double accumulation;
	static double total;
	void record(const Date &date, double amount, const std::string &desc);   //desc is a description
	void error(const std::string &msg) const;
	double accumulate(const Date &date) const {
		return accumulation + balance * date.distance(last_date);
	}
public:
	savings_account(const Date &_date, const std::string _id, double _rate);
	const std::string &get_id() const {return id;}
	double get_balance() const {return balance;}
	double get_rate() const {return rate;}
	static double get_total() {return total;}
	void deposit(const Date &date, double amount, const std::string &desc);
	void withdraw(const Date &date, double amount, const std::string &desc);
	void settle(const Date &date);
	void show() const;
};



#endif