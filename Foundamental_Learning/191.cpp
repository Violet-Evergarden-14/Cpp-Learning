#include<iostream>
using namespace std;

class Students
{
public:
    int id;
    int score[10] = {0};
    float sum = 0;
};


int main()
{
    int n, m;
    cin >> n >> m;

    Students list[n];

    int course[m];
    for (int i = 0; i < m; i++) {
        cin >> course[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> list[i].id;
        for (int j = 0; j < m; j++)
        {
            cin >> list[i].score[j];
            list[i].sum += list[i].score[j] * course[j] * 0.01;
        }
    }
    

    return 0;
    
}