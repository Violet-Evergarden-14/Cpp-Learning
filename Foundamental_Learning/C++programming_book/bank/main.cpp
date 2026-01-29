#include "account.h"
#include <iostream>
using namespace std;

int main()
{
	savings_account account0(1, 21325302, 0.015);
	savings_account account1(5, 58320212, 0.015);

	account0.deposit(5, 5000);
	account1.deposit(25, 10000);
	account0.deposit(45, 5500);
	account1.withdraw(60, 4000);

	account0.settle(90);
	account1.settle(90);

	account0.show();
	account1.show();

	cout << "Total: " << savings_account::get_total() << endl;
}