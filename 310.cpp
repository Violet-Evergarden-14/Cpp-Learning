#include <stdio.h>

int n_len(int x);

int main()
{
    int a, b, use;
    scanf("%d%d", &a, &b);
    int length;
    int judge = 1;
    int number_t[b - a];
    int count = 0;
    int sum_up = 0;

    for (int i = a; i <= b; i++)
    {
        length = n_len(i);
        use = i * i - i;
        for (int j = 0; j < length; j++)
        {
            if (use % 10 != 0)
            {
                judge = 0;
                break;
            }
            use /= 10;
        }
        
        if (judge)
        {
            number_t[count] = i;
            count++;
        }
        judge = 1;
    }
    
    for (int i = 0; i < count; i++)
    {
        sum_up += number_t[i];
    }
    
    printf("%d", sum_up);

    return 0;
}

int n_len(int x)
{
    int n = 1;
    while (x > 9)
    {
        x /= 10;
        n++;
    }
    return n;
}