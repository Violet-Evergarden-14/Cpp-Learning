#include <stdio.h>

int main()
{
    int k;
    scanf("%d", &k);
    int count = 0;
    double sum_up = 0;

    while (sum_up <= k)
    {
        count++;
        sum_up += 1.0 / count;
    }

    printf("%d", count);
    




    return 0;
}