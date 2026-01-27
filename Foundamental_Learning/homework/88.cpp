#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int matrix[n][n];
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            for (int j = 0; j < i; j++)
            {
                matrix[i - 1][j] = (i - 1) * (i - 1) + j + 1;
            }

            for (int j = 0; j < i - 1; j++)
            {
                matrix[j][i - 1] = i * i - j;
            }
            
        } else {
            for (int j = 0; j < i; j++)
            {
                matrix[j][i - 1] = (i - 1) * (i - 1) + j + 1;
            }

            for (int j = 0; j < i - 1; j++)
            {
                matrix[i - 1][j] = i * i - j;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    
}