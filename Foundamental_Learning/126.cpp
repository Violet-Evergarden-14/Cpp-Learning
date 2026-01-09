#include <iostream>
using namespace std;

int travel(int number[8][8], int path[64][2], int count, int i, int j, int n, int m);
int max(int a, int b, int c);
bool judge(int path[64][2], int count, int i, int j, int n, int m);

int main()
{
    int n, m;
    cin >> n >> m;
    int p[1];

    int number[8][8];
    int path[64][2];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> number[i][j];
        }
    }
    
    cout << travel(number, path, 0, 0, 0, n, m);
}

int travel(int number[8][8], int path[64][2], int count, int i, int j, int n, int m)
{
    if (n == 1 && m == 1)
    {
        return number[0][0];
    }
    
    if (count == 0)
    {
        path[0][0] = i;
        path[0][1] = j;
        return number[i][j] + max(travel(number, path, count + 1, i + 1, j, n, m),
                                  travel(number, path, count + 1, i, j + 1, n, m),
                                  travel(number, path, count + 1, i, j - 1, n, m));
    }

    if (judge(path, count, i, j, n, m))
    {
        return -10000000;
    } else if (i == n - 1 && j == m - 1)
    {
        return number[i][j];
    } else {
        path[count][0] = i;
        path[count][1] = j;
        return number[i][j] + max(travel(number, path, count + 1, i + 1, j, n, m),
                                  travel(number, path, count + 1, i, j + 1, n, m),
                                  travel(number, path, count + 1, i, j - 1, n, m));
    }
    
}

int max(int a, int b, int c)
{
    if (a >= b && a >= c)
    {
        return a;
    } else if (b >= c)
    {
        return b;
    }
    return c;
}

bool judge(int path[64][2], int count, int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
    {
        return 1;
    }

    for (int time = 0; time < count; time++)
    {
        if (i == path[time][0] && j == path[time][1])
        {
            return 1;
        }
    }
    
    return 0;
}