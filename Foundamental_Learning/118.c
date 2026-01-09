#include <stdio.h>

int main()
{
    int f[10000];
    f[0] = 0;
    f[1] = 1;
    int a, b;

   /* int n;
    scanf("%d", &n);*/

    for (int n = 0; n < 1000; n++)
    {
        
    
    if (n == 0)
    {
        printf("0");
    } else if (n == 1)
    {
        printf("1");
    } else {
        for (int i = 2; i <= n; i++)
        {
            a = f[i - 2] + f[i - 1];
            b = a % 10000;
            f[i] = b;
        }
        printf("%d\n", f[n]);
    } }
    


    return 0;
}