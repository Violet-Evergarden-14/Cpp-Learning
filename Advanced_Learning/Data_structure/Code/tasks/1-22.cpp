#include <iostream>
using namespace std;

class Fib
{
private:
	int f = 0, g = 1;
public: 
	Fib(int n){
		f = 0;
		g = 1;
		while (f < n)
		{
			g = f + g;
			f = g - f;
		}
	};
	int get() {return f;}
	int next() {return f + g;}
	int prev() {return g - f;}
}; 

int main()
{
	Fib fib(6);
	cout << fib.get();
}