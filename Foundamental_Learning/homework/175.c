#include <stdio.h>

int main()
{
    char target = 'A';
    char result;
    int row, line;
    scanf("%d %d", &row, &line);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < line; j++)
        {
            if (i > j)
            {
                result = target + i - j;
            } else {
                result = target - i + j;
            }
            printf("%c", result);
        }
        printf("\n");
    }
    


    return 0;
}