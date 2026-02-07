#ifndef __DATE_H__
#define __DATE_H__

class Date
{
private:
	int year;
	int month;
	int day;
	int total_days;
public:
	Date(int _year, int _month, int _day);
	int get_year() const {return year;}
	int get_month() const {return month;}
	int get_day() const {return day;}
	int get_max_day() const;     // get the maximum date of the month
	bool is_leap_year() const {
		return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	}
	void show() const;
	int distance(const Date &_date) const {
		return total_days - _date.total_days;
	}
};

#endif