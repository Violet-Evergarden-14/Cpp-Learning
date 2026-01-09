#include <iostream>
using namespace std;

class Vote
{
public:
	int id;
	int time;
};

int main()
{
	int n, m;
	cin >> n >> m;

	int a, count = 1, index = 0;
	Vote candidates[m];

	cin >> a;
	candidates[0].id = a;
	candidates[0].time = 1;
	for (int i = 1; i < m; i++) {
		cin >> a;
		index = 0;
		for (int i = 0; i < count; i++) {
			if (a == candidates[i].id) {
				candidates[i].time++;
				index = 1;
				break;
			}
		}
		
		if (index == 0) {
			candidates[count].id = a;
			candidates[count].time = 1;
			count++;
		}
	}
	
	int result = 0;
	for (int i = 0; i < count; i++)
	{
		if (candidates[i].time > m / 2)
		{
			result = candidates[i].id;
			break;
		}
	}
	
	if (result)
	{
		cout << result;
	} else {
		cout << -1;
	}
	
}