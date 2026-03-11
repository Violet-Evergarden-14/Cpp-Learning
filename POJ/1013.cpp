#include <iostream>
#include <string>

using namespace std;

bool judge_in_list(int m, int* list, int count) {
	for (int i = 0; i < count; i++) {
		if (list[i] == m) return true;
	}
	return false;
}

bool judge_in_list(int m, string list, int count) {
	for (int i = 0; i < count; i++) {
		if (list[i] - 'A' == m) return true;
	}
	return false;
}

void find_the_different() {
	int even_list[24];
	int count = 0;
	string situation[3];
	int number[3] = {0};
	string compare[3][2];
	for (int i = 0; i < 3; i++) {
		cin >> compare[i][0] >> compare[i][1] >> situation[i];
		number[i] = compare[i][0].length();
		if (situation[i] == "even") {
			for (int j = 0; j < number[i]; j++) {
				even_list[count] = compare[i][0][j] - 'A';
				count++;
			}
			for (int j = 0; j < number[i]; j++) {
				even_list[count] = compare[i][1][j] - 'A';
				count++;
			}
		}
	}
	for (int i = 0; i < 12; i++) {
		if (judge_in_list(i, even_list, count) == true) continue;
		for (int j = -1; j <= 1; j += 2) {
			bool judge = true;
			for (int k = 0; k < 3; k++) {
				if (situation[k] == "even") continue;
				int left = 0;
				if (judge_in_list(i, compare[k][0], number[k]) == true) left += j;
				if (judge_in_list(i, compare[k][1], number[k]) == true) left -= j;
				if (left > 0 && situation[k] == "up") continue;
				if (left < 0 && situation[k] == "down") continue;
				judge = false;
				break;
			}
			if (judge == true) {
				cout << char(i + 'A') << " is the counterfeit coin and it is ";
				if (j < 0) cout << "light";
				else cout << "heavy";
				cout << "." << endl;
				return;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		find_the_different();
	}
}