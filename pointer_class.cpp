#include <iostream>
using namespace std;

class Student
{
public:
	int id;
	int score;
};

void show(Student* pstu);
void show_all(Student* list, int n);

int main()
{
	Student middle_exam[5] =
    {
        {1,98},
        {2,35},
        {3,69},
        {4,76},
        {5,88}
    };

	show_all(middle_exam, 5);
}

void show(Student* pstu)
{
	cout << pstu->id << " " << pstu->score << endl;
}

void show_all(Student* list, int n)
{
	for (int i = 0; i < n; i++)
	{
		show(list + i);
	}
}