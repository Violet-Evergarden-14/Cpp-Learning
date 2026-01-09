#include <stdio.h>
#include <string.h>

int main()
{
    char s1[200], s2[200];
    gets(s1);
    gets(s2);

    int l1 = strlen(s1);
    int l2 = strlen(s2);

    int max;
    if (l1 > l2) max = l1;
    else max = l2;

    int minus;
    int index = 1;

    for (int i = 0; i < max; i++)
    {
        minus = s1[i] - s2[i];
        if (minus) {
            printf("%d", minus);
            index = 0;
            break;
        }
    }

    if (index)
    {
        printf("0");
    }

}