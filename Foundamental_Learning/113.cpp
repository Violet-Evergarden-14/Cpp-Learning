#include <iostream>
using namespace std;
int queen(int col[], int k, int n);
int judge(int col[], int k, int n);

int main()
{
    int n;
    cin >> n;

    int col[n] = {-1};
    cout << queen(col, 0, n);
}

int queen(int col[], int k, int n)
{
    int count = 0;
    if (k == n - 1)
    {
        for (int i = 0; i < n; i++)
        {
            col[k] = i;
            if (judge(col, n, n))
            {
                count++;
            }
        }
    } else {
        for (int i = 0; i < n; i++)
        {
            col[k] = i;
            if (judge(col, k + 1, n))
            {
                count += queen(col, k + 1, n);
            }
        }
    }
    return count;
}

int judge(int col[], int k, int n)
{
    for (int i = 0; i < k - 1; i++)
    {
        if (col[i] == col[k - 1] || col[i] + i == col[k - 1] + k - 1 || col[i] - i == col[k - 1] - k + 1)
        {
            return 0;
        }
    }
    return 1;
}