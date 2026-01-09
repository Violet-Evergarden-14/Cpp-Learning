#include <iostream>
using namespace std;

int judge(int a, int start[], int end[], int length);

int main()
{
    int l, m, count = 0;
    cin >> l >> m;
    int start[m], end[m];
    for (int i = 0; i < m; i++)
    {
        cin >> start[i] >> end[i];
    }

    for (int i = 0; i <= l; i++)
    {
        if (judge(i, start, end, m))
        {
            count++;
        }
        
    }
    
    cout << count << endl;
    
}

int judge(int a, int start[], int end[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (a >= start[i] && a <= end[i])
        {
            return 0;
        }
    }
    return 1;
}