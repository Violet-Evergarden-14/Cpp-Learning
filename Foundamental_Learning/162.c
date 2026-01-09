#include <stdio.h>
#include <string.h>

int main()
{
    char bianma[20];
    scanf("%s", bianma);
    int length = strlen(bianma);

    int number[20];
    int non = 0;
    for (int i = 0; i < length; i++)
    {
        if (bianma[i] != '-')
        {
            number[i - non] = bianma[i] - '0';
        } else {
            non++;
        }
    }

    int last = 0;
    for (int i = 0; i < length - non - 1; i++)
    {
        last += (i + 1) * number[i];
    }

    last = last % 11;
    if (number[length - non - 1] == last || (last == 10 && bianma[length - 1] == 'X'))
    {
        printf("Right");
    } else {
        for (int i = 0; i < length - 1; i++)
        {
            printf("%c", bianma[i]);
        }

        if (last == 10)
        {
            printf("X");
        } else {
            printf("%d", last);
        }
    }

    return 0;
}