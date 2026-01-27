#include <stdio.h>
#include <string.h>

int length(char target[2001]);
void evaluate(char x_0[2001], int x[2000], int length_x);

int main()
{
    char a_0[2001];  int a[2000];
    char b_0[2001];  int b[2000];
    char c;
    int result[2000];

    scanf(" %c", &c);
    scanf("%s", a_0);
    scanf("%s", b_0);
    
    int length_a = length(a_0);
    int length_b = length(b_0);
    int l;
    if (length_a > length_b)
    {
        l = length_a;
    } else {
        l = length_b;
    }

    evaluate(a_0, a, length_a);//赋值给字符串
    evaluate(b_0, b, length_b);

    if (c == '-')//转化为加法
    {
        for (int i = 0; i < length_b; i++)
        {
            b[i] = -b[i];
        }
    }
    
    if (length_a > length_b)//先进行相加
    {
        for (int i = 0; i < length_b; i++)
        {
            result[i] = a[i] + b[i];
        }
        for (int i = length_b; i < length_a; i++)
        {
            result[i] = a[i];
        }
    } else
    if (length_a == length_b)
    {
        for (int i = 0; i < length_b; i++)
        {
            result[i] = a[i] + b[i];
        }
    } else {
        for (int i = 0; i < length_a; i++)
        {
            result[i] = a[i] + b[i];
        }
        for (int i = length_a; i < length_b; i++)
        {
            result[i] = b[i];
        }
    }

    for (int i = 0; i < l - 1; i++)//对进位操作
    {
        if (result[i] < -10)
        {
            result[i + 1] -= 2;
            result[i] += 20;
        } else if (result[i] < 0)
        {
            result[i + 1] -= 1;
            result[i] += 10;
        } else if (result[i] >= 10)
        {
            result[i + 1] += 1;
            result[i] -= 10;
        }
    }

    while (result[l - 1] == 0)//确定字符串有好长
    {
        l--;
        if (l == 0)
        {
            break;
        }
        
    }
    
    if (l != 0) {
        if (result[l - 1] < 0)//对负数讨论，转换正负号，再对进位操作
        {
            printf("-");
            for (int i = 0; i < l; i++)
            {
                result[i] = -result[i];
            }
            for (int i = 0; i < l - 1; i++)
            {
                if (result[i] < -10)
                {
                    result[i + 1] -= 2;
                    result[i] += 20;
                } else if (result[i] < 0)
                {
                    result[i + 1] -= 1;
                    result[i] += 10;
                } else if (result[i] >= 10)
                {
                    result[i + 1] += 1;
                    result[i] -= 10;
                }
            }
        }
        
        if (result[l - 1] >= 10)//打出这个数
        {
            printf("1%d", result[l - 1] - 10);
            for (int i = l - 2; i > -1; i--)
            {
                printf("%d", result[i]);
            }
        } else {
            for (int i = l - 1; i > -1; i--)
            {
                printf("%d", result[i]);
            }
            
        }
    } else {
        printf("0");
    }

    return 0;
}

int length(char target[2001])
{
    int l = strlen(target);
    if (target[0] == '-')
    {
        l--;
    }
    return l;
}

void evaluate(char x_0[2001], int x[2000], int length_x)//对字符串赋值
{
    if (x_0[0] == '-')
    {
        for (int i = 0; i < length_x; i++)
        {
            x[length_x - i - 1] = -(x_0[i + 1] - '0');
        }
    } else {
        for (int i = 0; i < length_x; i++)
        {
            x[length_x - i - 1] = x_0[i] - '0';
        }
    }
}