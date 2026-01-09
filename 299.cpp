#include <stdio.h>
#include <cmath>

int main()
{
    int n;
    scanf("%d", &n);
    int count = 0;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n == 1)
        {
            break;
        }
        
        if (n % i == 0)
        {
            do
            {
                n /= i;
                count++;
            } while (n % i == 0);
            printf("%d:%d\n", i, count);
            count = 0;
        }
    }

    if (n > 1)
    {
        printf("%d:1", n);
    }
    


    return 0;
}