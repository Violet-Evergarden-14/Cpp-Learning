#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Candidate
{
public:
	int id;
	string vote;
	int len;

	friend bool operator>(const Candidate& a, const Candidate& b) {
		if (a.len > b.len) return true;
		if (a.len < b.len) return false;
		int i = 0;
		while (a.vote[i] == b.vote[i]) {
			i++;
		}
		return a.vote[i] > b.vote[i];
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 

	int n;
	cin >> n;
	vector<Candidate> candidates(n);
	for (int i = 0; i < n; i++)
	{
		candidates[i].id = i + 1;
		cin >> candidates[i].vote;
		candidates[i].len = candidates[i].vote.length();
	}
	sort(candidates.begin(), candidates.end(), greater<Candidate>());
	cout << candidates[0].id << endl;
	cout << candidates[0].vote << endl;
}