#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 

	int n;
	cin >> n;
	vector<int> numbers(n);
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}
	
	sort(numbers.begin(), numbers.end());
	for (int i = 0; i < n; i++)
	{
		cout << numbers[i] << " ";
	}
	
}