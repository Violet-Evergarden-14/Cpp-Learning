#include <iostream>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

vector<string> days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

class Suspector {
public:
	string name = "";
	set<int> day = {};
	set<string> guilty = {};
	set<string> not_guilty = {};
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int m, n, p;
	cin >> m >> n >> p;
	vector<Suspector> suspectors;
	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		suspectors[i].name = a;
	}
	
}
