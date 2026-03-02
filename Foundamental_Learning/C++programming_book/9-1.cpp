#include <iostream>
using namespace std;

template<class T>
void output_array(const T* array, int count) {
	for (int i = 0; i < count; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int main()
{
	int a[8];
	double b[8];
	for (int i = 0; i < 8; i++) {
		a[i] = i;
		b[i] = i / 2.0;
	}
	output_array(a, 8);
	output_array(b, 8);
	
}