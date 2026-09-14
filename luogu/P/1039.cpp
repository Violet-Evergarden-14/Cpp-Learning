#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <set>
#include <limits>
using namespace std;

vector<string> days = {"Sunday.", "Monday.", "Tuesday.", "Wednesday.", "Thursday.", "Friday.", "Saturday."};
set<string> week_days = {"Sunday.", "Monday.", "Tuesday.", "Wednesday.", "Thursday.", "Friday.", "Saturday."};

class Suspector {
public:
	string name = "";
	set<string> day = {};
	set<string> is_guilty = {};
	set<string> not_guilty = {};
	bool fuck = false;
};

void get_information(string line);
int is_telling_lies(string guilty, string today, string liar_name);

int m, n, p;
vector<Suspector> suspectors;
unordered_map<string, int> the_index;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n >> p;
	int cnt = 0;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	set<string> the_guilty;
	suspectors = vector<Suspector>(m);

	// get information
	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		suspectors[i].name = a;
		the_index[a] = i;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	for (int i = 0; i < p; i++) {      
		string line;
		getline(cin, line);
		while (line.back() == '\r' || line.back() == '\n' || line.back() == '\0') line.pop_back();
		get_information(line);
	}
	for (int i = 0; i < m; i++) {
		if (suspectors[i].fuck == false) cnt++;
	}

	// list the result -- date, guilty -- and count the number people tell a lie -- judge if available -- add to set
	for (int i = 0; i < m; i++) {
		string guilty = suspectors[i].name;
		for (int j = 0; j < 7; j++) {
			string today = days[j];
			int count = 0;
			bool invalid = true;
			for (int t = 0; t < m; t++) {
				string liar_name = suspectors[t].name;
				if (suspectors[the_index[liar_name]].fuck == false) continue;
				int res = is_telling_lies(guilty, today, liar_name);
				if (res == -1) {
					invalid = false;
					break;
				} else if (res == 1) count++;
			}
			if (invalid == false) continue;
			if ((count == n) || (count < n && (count + cnt >= n))) {the_guilty.insert(guilty); break;}
		}
	}

	// get the set -- 0/1/others -- result
	if (the_guilty.size() == 0) cout << "Impossible";
	else if (the_guilty.size() > 1) cout << "Cannot Determine";
	else cout << *the_guilty.begin();
}

void get_information(string line) {
	int l = line.size();
	vector<string> words;
	string a = "";
	int i = 0;
	while (i < l && line[i] != ':') a.push_back(line[i++]);
	int idx = the_index[a];
	i += 2;
	while (i < l) {
		a = "";
		while (i < l && line[i] != ' ') a.push_back(line[i++]);
		words.push_back(a);
		i++;
	}
	words.push_back(a);
	l = words.size();
	i = 0;
	while (i < l) {
		if (words[i] == "guilty.") {
			if (i - 2 >= 0 && words[i - 1] == "am" && words[i - 2] == "I") {
				suspectors[idx].is_guilty.insert(suspectors[idx].name);
				suspectors[idx].fuck = true;
			}
			if (i - 2 >= 0 && words[i - 1] == "is" && the_index.count(words[i - 2]) == 1) {
				suspectors[idx].is_guilty.insert(words[i - 2]);
				suspectors[idx].fuck = true;
			}
			if (i - 3 >= 0 && words[i - 1] == "not" && words[i - 2] == "am" && words[i - 3] == "I") {
				suspectors[idx].not_guilty.insert(suspectors[idx].name);
				suspectors[idx].fuck = true;
			}
			if (i - 3 >= 0 && words[i - 1] == "not" && words[i - 2] == "is" && the_index.count(words[i - 3]) == 1) {
				suspectors[idx].not_guilty.insert(words[i - 3]);
				suspectors[idx].fuck = true;
			}
		}
		i++;
	}
	i = 0;
	while (i < l) {
		if (words[i] == "Today") {
			if (i + 2 < l && words[i + 1] == "is" && week_days.count(words [i + 2]) != 0) {
				suspectors[idx].day.insert(words[i + 2]);
				suspectors[idx].fuck = true;
			} 
		}
		i++;
	}
}

int is_telling_lies(string guilty, string today, string liar_name) {
	int idx = the_index[liar_name];
	if (!(suspectors[idx].day.size() > 1) && !(suspectors[idx].day.size() == 1 && suspectors[idx].day.count(today) == 0) &&
		!(suspectors[idx].is_guilty.size() > 1) && !(suspectors[idx].is_guilty.size() == 1 && suspectors[idx].is_guilty.count(guilty) != 1) &&
		!(suspectors[idx].not_guilty.count(guilty) > 0)) return 0;
	if ((suspectors[idx].day.count(today) > 0) || (suspectors[idx].is_guilty.count(guilty) > 0) || 
		(suspectors[idx].not_guilty.size() > 1) || (suspectors[idx].not_guilty.size() == 1 && suspectors[idx].not_guilty.count(guilty) == 0)) return -1;
	return 1;
}