#include <stdio.h>

int abs(int a);
int min(int a, int num[], int n);

int main()
{
    int n;
    scanf("%d", &n);

    int money[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &money[i]);
    }

    int f = abs(money[0]);
    for (int i = 1; i < n; i++) {
        f += min(money[i], money, i);
    }
    
    printf("%d", f);

    return 0;
}

int abs(int a)
{
    if (a > 0) {
        return a;
    } else {
        return -a;
    }
}

int min(int a, int num[], int n)
{
    int minus;
    int m = abs(a - num[0]);

    for (int i = 1; i < n; i++)
    {
        minus = abs(a - num[i]);
        if (m > minus) {
            m = minus;
        }
    }

    return m;
}