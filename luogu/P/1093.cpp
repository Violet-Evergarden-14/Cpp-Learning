#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
public:
	int id;
	int chinese, math, english;
	int total_score;

	friend bool operator>(const Student& a, const Student& b) {
		if (a.total_score > b.total_score) return true;
		if (a.total_score < b.total_score) return false;
		if (a.chinese > b.chinese) return true;
		if (a.chinese < b.chinese) return false;
		if (a.id < b.id) return true;
		else return false;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 

	int n;
	cin >> n;
	vector<Student> students(n);
	for (int i = 0; i < n; i++) {
		cin >> students[i].chinese >> students[i].math >> students[i].english;
		students[i].id = i + 1;
		students[i].total_score = students[i].chinese + students[i].math + students[i].english;
	}
	sort(students.begin(), students.end(), greater<Student>());
	for (int i = 0; i < 5; i++)
	{
		cout << students[i].id << " " << students[i].total_score << endl;
	}
}