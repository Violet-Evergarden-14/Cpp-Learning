#ifndef __ACCOUNT_H__
#define __ACCONUT_H__

class savings_account
{
private:
	int id;
	double balance;
	double rate;
	int last_date;
	double accumulation;
	static double total;
	void record(int date, double amount);
	const double accumulate(int date) {return accumulation + (date - last_date) * balance;}
public:
	savings_account(int _date, int _id, double _rate);
	const int get_id() {return id;}
	const double get_balnace() {return balance;}
	const double get_rate() {return rate;}
	const void show();
	void deposit(int date, double amount);
	void withdraw(int date, double amount);
	void settle(int date);
	static double get_total() {return total;}
};

#endif