#include <iostream>
#include <vector>
using namespace std;

void round(int i, int j, int& count_a, int& count_b) {
	switch (i) {
	case 0:
		switch (j) {
		case 0:
			break;
		case 1:
			count_b++;
			break;
		case 2:
			count_a++;
			break;
		case 3:
			count_a++;
			break;
		case 4:
			count_b++;
			break;
		default:
			break;
		}
		break;
	case 1:
		switch (j) {
		case 0:
			count_a++;
			break;
		case 1:
			break;
		case 2:
			count_b++;
			break;
		case 3:
			count_a++;
			break;
		case 4:
			count_b++;
			break;
		default:
			break;
		}
		break;
	case 2:
		switch (j) {
		case 0:
			count_b++;
			break;
		case 1:
			count_a++;
			break;
		case 2:
			break;
		case 3:
			count_b++;
			break;
		case 4:
			count_a++;
			break;
		default:
			break;
		}
		break;
	case 3:
		switch (j) {
		case 0:
			count_b++;
			break;
		case 1:
			count_b++;
			break;
		case 2:
			count_a++;
			break;
		case 3:
			break;
		case 4:
			count_a++;
			break;
		default:
			break;
		}
		break;
	case 4:
		switch (j) {
		case 0:
			count_a++;
			break;
		case 1:
			count_a++;
			break;
		case 2:
			count_b++;
			break;
		case 3:
			count_b++;
			break;
		case 4:
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

int main()
{
	int count_a = 0;
	int count_b = 0;
	int n, na, nb;
	cin >> n >> na >> nb;
	vector<int> a(na);
	vector<int> b(nb);
	for (int i = 0; i < na; i++) cin >> a[i];
	for (int i = 0; i < nb; i++) cin >> b[i];
	for (int i = 0; i < n; i++) {
		round(a[i % na], b[i % nb], count_a, count_b);
	}
	cout << count_a << " " << count_b;
}