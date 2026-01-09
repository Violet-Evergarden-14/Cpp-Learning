#include <stdio.h>

int main()
{
    int number[8];
    int sum_up = 0;

    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &number[i]);
    }
    
    sum_up = number[0] * 1000 + number[1] * 1000 + number[2] * 6000 + number[3] * 3000 + number[4] * 1000 + number[5] * 50000 + number[6] * 30000 + number[7] * 70000;
    
    printf("%d", sum_up / 100);
    return 0;
}