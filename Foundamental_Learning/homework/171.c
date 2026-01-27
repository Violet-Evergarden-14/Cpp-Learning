#include <stdio.h>

int main()
{
    long long a, b;
    char c;

    scanf("%lld %lld %c", &a, &b, &c);

    /*You can use switch-case statement. There!!!!!!*/
    
    if (c == '+')
    {
        printf("%lld", a + b);
    }

    if (c == '-')
    {
        printf("%lld", a - b);
    }
    
    if (c == '*')
    {
        printf("%lld", a * b);
    }
    
    if (c == '%')
    {
        if (b == 0)
        {
            printf("NO");
        } else {
            printf("%lld", a % b);
        }
        
        
    }

    if ( c == '/')
    {
        if (b == 0) {
            printf("NO");
        } else {
            printf("%lld", a / b);
        }
        
    }
    
    

    return 0;
}