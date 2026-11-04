#include "Stack.h"

// output from high to low
void convert(Stack<char>& s, long long n, int base) {
	static char digit[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	if (n > 0) {
		s.push(digit[n % base]);
		convert(s, n / base, base);
	} 
}

// another method
void convert1(Stack<char>& s, long long n, int base) {
	static char digit[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	while (n > 0) {
		s.push(digit[(int)(n % base)]);
		n /= base;
	}
}

