#include "date.h"
#include  <iostream>
#include <cstdlib>
using namespace std;

namespace {
	const int DAYS_BEFORE_MONTH[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
}

Date::Date(int _year, int _month, int _day) : year(_year), month(_month), day(_day) {
	if (day <= 0 || day > get_max_day()) {
		cout << "Invalid date: ";
		show();
		cout << endl;
		exit(1);
	}
	int years = year - 1;
	total_days = years * 365 + years / 4 - years / 100 + years / 400
				 + DAYS_BEFORE_MONTH[month - 1] + day;
	if (is_leap_year() && month > 2) {
		total_days++;
	}
}

int Date::get_max_day() const {
	if (is_leap_year() && month == 2) {
		return 29;
	}
	return DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1];
}

void Date::show() const {
	cout << get_year() << "-" << get_month() << "-" << get_day();
}