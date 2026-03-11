#include <iostream>
#include <list>
using namespace std;

class die {
public:
	int number;
	int count;
};

int execute(list<int>& guys, int start, int m, int& round) {
	start += m;
	start %= round;
	list<int>::iterator it = guys.begin();
	advance(it, start);
	guys.erase(it);
	round--;
	return start - 1;
}

bool judge_if_all_alive(list<int>& guys, int k) {
	list<int>::iterator it = guys.begin();
	if (*it != 0) return false;
	for (int i = 1; i < k; i++) {
		advance(it, 1);
		if (*it != i) return false;
	}
	return true;
}

int arrange_number(int a, int b) {
	int result = 1;
	for (int i = 0; i < b; i++) {
		result *= a - i;
	}
	return result;
}

bool if_in_problem_list(list<die>& problem_list, int n, int arrange_a) {
	list<die>::iterator it;
	it = problem_list.begin();
	while (it != problem_list.end()) {
		if (n % arrange_number(arrange_a, it->count) == it->number) return true;
		it++;
	}
	return false;
}

int main()
{
	int k;
	int m;
	int start;
	int round;
	list<int> guys;
	list<die> problem_list;
	while (cin >> k) {
		if (k == 0) break;
		for (int i = 0; i < 2 * k; i++) {
			guys.push_back(i);
		}
		round = 2 * k;
		m = 1;
		while (true) {
			if (if_in_problem_list(problem_list, m, 2 * k) == true) {m++; continue;}
			start = execute(guys, -1, m, round);
			A:
			if (judge_if_all_alive(guys, k) == false) {
				if (2 * k - round < 3) problem_list.push_back({m, 2 * k - round});
				m++;
				guys.clear();
				for (int i = 0; i < 2 * k; i++) {
					guys.push_back(i);
				}
				round = 2 * k;
				continue;
			} else {
				if (round == k) {
					cout << m << endl;
					guys.clear();
					break;
				} else {
					start = execute(guys, start, m, round);
					goto A;
				}
			}
		}
	}
}