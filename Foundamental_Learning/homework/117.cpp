#include <iostream>
using namespace std;
int choose(int col[], int k, int n, int peach[100][100]);
int max(int a, int b);

int main()
{
    int n;
    cin >> n;

    int peach[100][100] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> peach[i][j];
        }
    }

    int col[n] = {-1};
    col[0] = 0;
    cout << choose(col, 1, n, peach) + peach[0][0];
}

int choose(int col[], int k, int n, int peach[100][100])
{
    if (k == n - 1)
    {
        return max(peach[n - 1][col[n - 2]], peach[n - 1][col[n - 2] + 1]);
    } else {
        int m1 = col[k - 1];
        col[k] = m1;
        int a = peach[k][m1] + choose(col, k + 1, n, peach);

        int m2 = col[k - 1] + 1;
        col[k] = m2;
        int b = peach[k][m2] + choose(col, k + 1, n, peach);

        return max(a, b);
    }
}

int max(int a, int b)
{
    if (a > b) return a;
    return b;
}
/*
#include <iostream>
using namespace std;
int max(int a, int b);

int main()
{
    int n;
    cin >> n;

    int peach[100][100] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> peach[i][j];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            peach[i][j] += max(peach[i + 1][j], peach[i + 1][j + 1]);
        }
    }

    cout << peach[0][0];
}

int max(int a, int b)
{
    if (a > b) return a;
    return b;
}*/