#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 

	int n, m;
	cin >> n >> m;
	vector<int> puples(n);
	for (int i = 0; i < n; i++) {
		cin >> puples[i];
	}
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		cout << puples[k - 1] << endl;
	}
	
}