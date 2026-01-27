#include <stdio.h>

int main()
{
    int a, b, judge = 0;
    scanf("%d", &a);

    if (a >= 0) {
        do
        {
            if (a % 10)
            {
                judge++;
            }
            if (judge)
            {
                printf("%d", a % 10);
            }
            a /= 10;
        } while (a > 0);
    } else {
        printf("-");
        b = -a;
        do
        {
            if (b % 10)
            {
                judge++;
            }
            if (judge)
            {
                printf("%d", b % 10);
            }
            b /= 10;
        } while (b > 0);
    }
    

    return 0;
}