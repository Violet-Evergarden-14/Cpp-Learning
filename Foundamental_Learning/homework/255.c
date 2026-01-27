#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int matrix[n][m];
    int parament;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &parament);
            matrix[i][j] = parament;
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }
    


    return 0;
}