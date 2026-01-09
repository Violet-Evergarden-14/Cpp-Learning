#include <iostream>
using namespace std;
int sum_up(int i, int j, int list[]);

int main()
{
    int n;
    cin >> n;
    int list[n];
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }

    int sum;
    int max = -10000;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum = sum_up(i, j, list);
            if (sum > max)
            {
                max = sum;
            }
            
        }
        
    }
    
    cout << max << endl;
}

int sum_up(int i, int j, int list[])
{
    int sum = 0;
    for (int m = i; m <= j; m++)
    {
        sum += list[m];
    }
    return sum;
}