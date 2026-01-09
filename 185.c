#include <stdio.h>
#include <math.h>

int main()
{
    int a, count = 0;
    scanf("%d", &a);
    
    double x = a / 2;
    double y = a;

    while (x - y < -0.00001 || x - y > 0.00001)
    {
        y = x;
        x = 0.5 * (x + a / x);
        count++;
    }
    
    printf("%lf\n%d", x, count);


    return 0;
}