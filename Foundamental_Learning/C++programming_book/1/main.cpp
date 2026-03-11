#include <iostream>
using namespace std;
int n;
void fun();

int main()
{
	n = 1;
	cout << n;
	string m;
	m = cin.get();  //get()一次一个
	getline(cin, m, '\n');
	cout << m;
}