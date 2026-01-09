#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
    char ac[1010], bc[1010];
    gets(ac);
    gets(bc);

    int l = strlen(ac);
    int a[l];
    int b[l];
    int c[l];

    for (int i = 0; i < l; i++)
    {
        a[i] = ac[l - 1 - i] - '0';
        b[i] = bc[l - 1 - i] - '0';
        c[i] = a[i];
    }

    while (1) {
        for (int i = 0; i < l - 1; i++)
        {
            c[i] -= b[i];
            if (c[i] < 0) {
                c[i] += 10;
                c[i + 1] -= 1;
            }
        }

        c[l - 1] -= b[l - 1];
        if (c[l - 1] < 0)
        {
            break;
        }
        

        for (int i = 0; i < l; i++)
        {
            a[i] = c[i];
        }
        
    }    

    int count = 0;
    for (int i = l - 1; i >= 0; i--)
    {
        if (a[i] == 0)
        {
            count++;
        } else {
            break;
        }
    }

    for (int i = l - 1 - count; i >= 0; i--)
    {
        cout << a[i];
    }
    
    if (count == l)
    {
        cout << 0;
    }
    
    
}