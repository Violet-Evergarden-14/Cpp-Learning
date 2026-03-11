#include <iostream>
using namespace std;

class Guys
{
public:
	int situation; // 0 dead; 1 alive
};



int execute(Guys guys[], int start, int m, int round) {
	int count = m;
	while (true) {
		start++;
		if (start >= round) start -= round;
		if (guys[start].situation == 0) continue;
		count--;
		if (count == 0) {
			guys[start].situation = 0;
			return start;
		}
	}
}

bool judge_if_die_out(Guys guys[], int k) {
	for (int i = k; i < 2 * k; i++) {
		if (guys[i].situation == 1) return false;
	}
	return true;
}

bool judge_if_all_alive(Guys guys[], int k) {
	for (int i = 0; i < k; i++) {
		if (guys[i].situation == 0) return false;
	}
	return true;
}

int main()
{
	int k;
	int m;
	int start;
	while (cin >> k) {
		if (k == 0) break;
		Guys guys[2 * k];
		for (int i = 0; i < 2 * k; i++) {guys[i].situation = 1;}
		m = 2;
		while (true) {
			start = execute(guys, -1, m, 2 * k);
			A:
			if (judge_if_all_alive(guys, k) == false) {
				m++;
				for (int i = 0; i < 2 * k; i++) {guys[i].situation = 1;}
				continue;
			} else {
				if (judge_if_die_out(guys, k) == true) {
					cout << m << endl;
					break;
				} else {
					start = execute(guys, start, m, 2 * k);
					goto A;
				}
			}
		}
	}
}