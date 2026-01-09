#include <iostream>
using namespace std;
int find_path(int matrix[11][11], int path[81][2], int count, int i, int j, int n, int m);

int main()
{
    int n, m;
    cin >> n >> m;
    int matrix[11][11] = {0};

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int path[81][2] = {1};

    if(find_path(matrix, path, 0, 1, 1, n, m))
    {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
}

int find_path(int matrix[11][11], int path[81][2], int count, int i, int j, int n, int m)
{
    if (i == n && j == m) {return 1;}
    else if (count > 1)
    {
    if (matrix[i][j] == 0 || (i == path[count - 2][0] && j == path[count - 2][1])) 
        {
            return 0;
        } else {
            path[count][0] = i;
            path[count][1] = j;
            
            if (find_path(matrix, path, count + 1, i + 1, j, n, m) || 
                find_path(matrix, path, count + 1, i - 1, j, n, m) ||
                find_path(matrix, path, count + 1, i, j + 1, n, m) ||
                find_path(matrix, path, count + 1, i, j - 1, n, m))
            {
                return 1;
            } else {
                return 0;
            }
        }
    } else {
        if (matrix[i][j] == 0) 
        {
            return 0;
        } else {
            path[count][0] = i;
            path[count][1] = j;
                
            if (find_path(matrix, path, count + 1, i + 1, j, n, m) || 
                find_path(matrix, path, count + 1, i - 1, j, n, m) ||
                find_path(matrix, path, count + 1, i, j + 1, n, m) ||
                find_path(matrix, path, count + 1, i, j - 1, n, m))
            {
                return 1;
            } else {
                return 0;
            }
        }
    }
}

