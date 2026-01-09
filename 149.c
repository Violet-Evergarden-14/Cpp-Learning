#include <stdio.h>

int main()
{
    int n, p, m;
    scanf("%d%d%d", &n, &p, &m);
    int matrix1[n][p];
    int matrix2[p][m];
    int matrix_final[n][m];
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int t = 0; t < p; t++)
        {
            scanf("%d", &matrix1[i][t]);
        }
        printf("\n");
    }

    for (int i = 0; i < p; i++)
    {
        for (int t = 0; t < m; t++)
        {
            scanf("%d", &matrix2[i][t]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < p; k++)
            {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            matrix_final[i][j] = sum;
            sum = 0;
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matrix_final[i][j]);
        }
        printf("\n");
    }
    


    return 0;
}