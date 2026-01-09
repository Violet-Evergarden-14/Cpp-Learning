#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int matrix[m][n];

    int k;
    cin >> k;
    int index[k];
    for (int i = 0; i < k; i++)
    {
        cin >> index[i];
        index[i]--;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int temp;
    for (int j = 0; j < m - 1; j++)
    {
        for (int i = 0; i < m - 1; i++)
        {
            if (matrix[i][index[0]] > matrix[i + 1][index[0]])
            {
                for (int a = 0; a < n; a++)
                {
                    temp = matrix[i][a];
                    matrix[i][a] = matrix[i + 1][a];
                    matrix[i + 1][a] = temp;
                }
            }
        }
    }
    
    int YES = 1;
    for (int i = 1; i < k; i++)
    {
        for (int outer = 0; outer < m - 1; outer++) {
            for (int inner = 0; inner < m - 1; inner++) {
                YES = 1;

                for (int jiancha = 0; jiancha < i; jiancha++) {
                    if (matrix[inner][index[jiancha]] != matrix[inner + 1][index[jiancha]]) YES = 0;
                }
                
                if (YES) {
                    if (matrix[inner][index[i]] > matrix[inner + 1][index[i]]) {
                        for (int t = 0; t < n; t++) {
                            temp = matrix[inner][t];
                            matrix[inner][t] = matrix[inner + 1][t];
                            matrix[inner + 1][t] = temp;
                        }
                    }
                }
            }
        }
    }

    for (int outer = 0; outer < m - 1; outer++) {
        for (int inner = 0; inner < m - 1; inner++) {
            YES = 1;
            for (int jiancha = 0; jiancha < k; jiancha++) {
                if (matrix[inner][index[jiancha]] != matrix[inner + 1][index[jiancha]]) YES = 0;
            }
            
            if (YES) {
                if (matrix[inner][0] > matrix[inner + 1][0]) {
                    for (int t = 0; t < n; t++) {
                        temp = matrix[inner][t];
                        matrix[inner][t] = matrix[inner + 1][t];
                        matrix[inner + 1][t] = temp;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}