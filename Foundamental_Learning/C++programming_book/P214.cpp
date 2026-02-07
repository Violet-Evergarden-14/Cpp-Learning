#include <iostream>
using namespace std;

void print_stuff(double) {
	cout << "Print-staff function called." << endl;
}

void print_message(double data) {
	cout << "Print-message function called." << endl;
	cout << "data = " << data << endl;
}

void print_double(double data) {
	cout << "Print-double function called." << endl;
	cout << "number = " << data << endl;
}

const double PI = 3.14159;

int main()
{
	void (*function_ptr) (double);
	print_stuff(PI);
	function_ptr = print_stuff;
	function_ptr(PI);
	function_ptr = print_message;
	function_ptr(PI);
	function_ptr = print_double;
	function_ptr(PI);
}