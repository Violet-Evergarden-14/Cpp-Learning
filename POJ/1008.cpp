#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> haab_month_name_list = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", 
									   "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
vector<string> Tzolkin_month_name_list = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", 
										  "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int search_for_index(vector<string> original_list, string target) {
	int count = 0;
	while(original_list[count] != target) {
		count++;
	}
	return count;
}

void exchange_date() {
	int day_haab, year_haab, date;
	string month_haab;
	cin >> day_haab >> month_haab >> month_haab >> year_haab;

	int index = search_for_index(haab_month_name_list, month_haab);
	if (index == 18) {date = 360 + day_haab + 1 + year_haab * 365;}
	else {date = index * 20 + day_haab + 1 + year_haab * 365;}

	int day_Tzolkin, year_Tzolkin;
	string month_Tzolkin;

	year_Tzolkin = date / 260;
	date %= 260;
	if (date == 0) {date = 260; year_Tzolkin--;}
	day_Tzolkin = date % 13;
	if (day_Tzolkin == 0) {day_Tzolkin = 13;}
	month_Tzolkin = Tzolkin_month_name_list[(date - 1) % 20];

	cout << day_Tzolkin << " " << month_Tzolkin << " " << year_Tzolkin << endl;
}

int main()
{
	int n;
	cin >> n;
	cout << n << endl;
	for (int i = 0; i < n; i++) {exchange_date();}
}