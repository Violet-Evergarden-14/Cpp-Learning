#include <stdio.h>

int main()
{
    int n, sum_up = 0, change;
    scanf("%d", &n);

    int score[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &score[i]);
        sum_up += score[i];
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (score[j] > score[j + 1])
            {
                change = score[j];
                score[j] = score[j + 1];
                score[j + 1] = change;
            }
        }
    }

    int ave = sum_up / n;
    int y = sum_up % n;
    if (n % 2)
    {
        if (y > n / 2.0)
        {
            ave++;
        }
    } else {
        if (y >= n / 2)
        {
            ave++;
        }
    }
    
    
    printf("%d %d %d", score[n - 1], score[0], ave);

    return 0;
}