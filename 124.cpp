#include <iostream>
using namespace std;

int find(int matrix[52][52], int i, int j, int path[2500][2], int count);
int max(int a, int b, int c, int d);
bool judge(int i, int j, int path[2500][2], int count);

int main()
{
    int n, m;
    cin >> n >> m;

    int matrix[52][52] = {5000};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i + 1][j + 1];
        }
    }

    int path[2500][2];
    int a;
    int M = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a = find(matrix, i, j, path, 0);
            if (a > M)
            {
                M = a;
            }
        }
    }
    
    cout << M;
}

int find(int matrix[52][52], int i, int j, int path[2500][2], int count)
{
    if (count == 0)
    {
        path[count][0] = i;
        path[count][1] = j;
        return 1 + max(find(matrix, i + 1, j, path, count + 1),
                       find(matrix, i - 1, j, path, count + 1),
                       find(matrix, i, j + 1, path, count + 1),
                       find(matrix, i, j - 1, path, count + 1));
    } else {
        if (matrix[path[count - 1][0]][path[count - 1][1]] > matrix[i][j] || judge(i ,j, path, count))
        {
            return 0;
        } else {
            path[count][0] = i;
            path[count][1] = j;
            return 1 + max(find(matrix, i + 1, j, path, count + 1),
                           find(matrix, i - 1, j, path, count + 1),
                           find(matrix, i, j + 1, path, count + 1),
                           find(matrix, i, j - 1, path, count + 1));
        }
    }
}

int max(int a, int b, int c, int d)
{
    int list[4] = {a, b, c, d};

    int temp;
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (list[i] < list[i + 1])
            {
                temp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = temp;
            }
        }
    }
    
    return list[0];
}

bool judge(int i, int j, int path[2500][2], int count)
{
    for (int time = 0; time < count; time++)
    {
        if (i == path[time][0] && j == path[time][1])
        {
            return 1;
        }
    }
    return 0;
}