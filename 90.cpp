#include <iostream>
using namespace std;
class Student
{
public:
    int sno = 0;
    int score = 0;
    int rank = 0;
};

int judge(int a, int list[], int n);

int main()
{
    int n;
    cin >> n;
    int problem_list[n];
    for (int i = 0; i < n; i++) {
        cin >> problem_list[i];
    }

    int m, k;
    cin >> m >> k;
    Student student[m];

    int a;
    int repeat;

    for (int i = 0; i < m; i++) {
        cin >> student[i].sno >> repeat;
        for (int j = 0; j < repeat; j++) {
            cin >> a;
            student[i].score += judge(a, problem_list, n);
        }
    }
    
    for (int j = 0; j < m - 1; j++)
    {
        for (int i = 0; i < m - 1; i++)
        {
            if ((student[i].score < student[i + 1].score) || 
                (student[i].score == student[i + 1].score && student[i].sno > student[i + 1].sno))
            {
                a = student[i].score;
                student[i].score = student[i + 1].score;
                student[i + 1].score = a;
                a = student[i].sno;
                student[i].sno = student[i + 1].sno;
                student[i + 1].sno = a;
            }   
        }
    }
    
    student[0].rank = 1;
    for (int i = 1; i < m; i++)
    {
        if (student[i].score == student[i - 1].score)
        {
            student[i].rank = student[i - 1].rank;
        } else {
            student[i].rank = student[i - 1].rank + 1;
        }
        
    }
    

    a = 0;

    while (student[a].rank <= k)
    {
        cout << student[a].sno << " ";
        a++;
    }
    
    

}

int judge(int a, int list[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a == list[i])
        {
            return 1;
        }
    }
    return 0;
}