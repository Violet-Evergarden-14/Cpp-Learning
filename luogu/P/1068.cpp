#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Interview {
public:
	int id;
	int score;

	friend bool operator>(const Interview& a, const Interview& b) {
		if (a.score > b.score) return true;
		if (a.score < b.score) return false;
		if (a.id < b.id) return true;
		return false;
	}

	void show() {
		cout << id << " " << score << endl;
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	m = m * 1.5;
	vector<Interview> interviewees(n);
	for (int i = 0; i < n; i++) cin >> interviewees[i].id >> interviewees[i].score;
	sort(interviewees.begin(), interviewees.end(), greater<Interview>());
	int standard = interviewees[m - 1].score;
	while (interviewees[m].score >= standard) {
		m++;
	}
	cout << interviewees[m - 1].score << " " << m << endl;
	for (int i = 0; i < m; i++) {
		interviewees[i].show();
	}
}