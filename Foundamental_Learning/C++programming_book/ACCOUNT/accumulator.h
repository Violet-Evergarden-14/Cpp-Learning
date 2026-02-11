#ifndef _ACCUMULATOR_H
#define _ACCUMULATOR_H

#include "date.h"
#include <string>

class Accumulator
{
private:
	Date last_date;
	double value;
	double value_for_credit_account;
	double sum;
public:
	Accumulator(const Date& _date, double _value): last_date(_date), value(_value), value_for_credit_account(0), sum(0) {};
	double get_sum(const Date& date, const std::string& type) const {
		if (type == "credit_account" && value >= 0) {return sum;}
		else {return sum + value * date.distance(last_date);}
	}
	void change(const Date& date, double _value, const std::string& type) {
		sum = get_sum(date, type);
		last_date = date;
		value = _value;
	}
	void reset(const Date& date, double _value) {
		last_date = date;
		value = _value;
		sum = 0;
	}
};

#endif