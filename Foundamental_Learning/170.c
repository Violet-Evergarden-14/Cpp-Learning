#include <stdio.h>

int main()
{
    int lindan = 0, lizongwei = 0, result, gap;

    do
    {
        scanf("%d", &result);
        if (result)
        {
            lizongwei += 1;
        } else {
            lindan += 1;
        }
    } while (lindan < 21 && lizongwei < 21);
    
    gap = lindan - lizongwei;
    while (gap >= -1 && gap <= 1)
    {
        scanf("%d", &result);
        if (result)
        {
            gap -= 1;
        } else {
            gap += 1;
        }
    }
    

    if (gap > 1) {
        printf("0");
    } else
    if (gap < -1) {
        printf("1");
    }


    return 0;
}