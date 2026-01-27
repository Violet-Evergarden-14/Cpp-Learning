#include <stdio.h>

int main()
{
    int a, b, m;
    scanf("%d %d", &a, &b);
    m = a;

    while (m % b != 0)
    {
        m += a;
    }
    
    printf("%d", m);

    return 0;
}