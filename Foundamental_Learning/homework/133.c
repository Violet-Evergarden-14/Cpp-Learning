#include <stdio.h>

int judge(int list_result[10000], int list_y[10000], int number, int *parament);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    int c = a / b;
    int d = a % b;
    printf("%d.", c);

    int initial;

    if (d == 0)
    {
        printf("0");
    } else {
        int list_result[10000];
        list_result[0] = 1;
        int list_y[10000];
        list_y[0] = d;
        int count = 1;
        do
        {
            list_result[count] = list_y[count - 1] * 10 / b;
            list_y[count] = list_y[count - 1] * 10 % b;
            if (list_y[count] == 0)
            {
                for (int i = 0; i < count; i++)
                {
                    printf("%d", list_result[i + 1]);
                }
                break;
            } else {
                if (judge(list_result, list_y, count, &initial))
                {
                    for (int i = 1; i < initial; i++)
                    {
                        printf("%d", list_result[i]);
                    }
                    printf("(");
                    for (int i = initial; i < count; i++)
                    {
                        printf("%d", list_result[i]);
                    }
                    printf(")");
                    break;
                }
            }
            
            count++;
        } while (1);
    }
    


    return 0;
}

int judge(int list_result[10000], int list_y[10000], int number, int *parament)
{
    int result = 0;
    for (int i = 1; i < number; i++)
    {
        if (list_result[i] == list_result[number] && list_y[i] == list_y[number])
        {
            result = 1;
            *parament = i;
        }
    }
    
    return result;
}