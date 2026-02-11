#include "account.h"
#include <iostream>
using namespace std;

int main()
{
	Date date(2008, 1, 1);
	SavingsAccount sa1(date, "s3755217", 0.015);
	SavingsAccount sa2(date, "02342342", 0.015);
	CreditAccount ca(date, "C5392394", 10000, 0.0005, 50);

	sa1.deposit(Date(2008, 11, 5), 5000, "salary");
	ca.withdraw(Date(2008, 11, 15), 2000, "buy a cell");
	sa2.deposit(Date(2008, 11, 25), 10000, "sell stock 0323");

	ca.deposit(Date(2008, 12, 1), 2016, "repay the credit");
	sa1.deposit(Date(2008, 12, 5), 5500, "salary");

	Date settle_date(2009, 1, 1);
	sa1.settle(settle_date);
	sa2.settle(settle_date);
	ca.settle(settle_date);

	cout << endl;

	sa1.show(); cout << endl;
	sa2.show(); cout << endl;
	ca.show(); cout << endl;
	cout << "Total: " << Account::get_total() << endl;
}