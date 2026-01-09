#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    int table[m + 2][n + 2];

    for (int i = 0; i < m + 2; i++)
    {
        for (int j = 0; j <= n + 2; j++)
        {
            table[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> table[i][j];
        }
    }

    int sum[m][n];
    int max = table[1][1] + table[0][1] + table[2][1] + table[1][0] + table[1][2];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum[i][j] = table[i + 1][j + 1] + table[i][j + 1] + table[i + 2][j + 1] + table[i + 1][j] + table[i + 1][j + 2];
            if (sum[i][j] > max)
            {
                max = sum[i][j];
            }
        }
    }

    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (sum[i][j] == max)
            {
                count++;
            }
        }
    }

    cout << max << " " << count << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (sum[i][j] == max)
            {
                cout << i << " " << j << endl;
            }
        }
    }
}