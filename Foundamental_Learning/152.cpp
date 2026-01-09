#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int result[n];

    int p, q, r;
    int a[8] = {0}, b[8] = {0}, c[8] = {0}, d[8] = {0};
    int count, m, max;
    int index = 0;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < 8; i++) {
            a[i] = 0; b[i] = 0; c[i] = 0;
        }
        
        scanf("%d%d%d", &p, &q, &r);
        max = p % 10;

        count = 0;
        do {
            a[count] = p % 10;
            if (a[count] > max)  max = a[count];
            p /= 10;
            count++;
        } while (p > 0);
            
        count = 0;
        do {
            b[count] = q % 10;
            if (b[count] > max)  max = b[count];
            q /= 10;
            count++;
        } while (q > 0);
            
        count = 0;
        do {
            c[count] = r % 10;
            if (c[count] > max)  max = c[count];
            r /= 10;
            count++;
        } while (r > 0);

        m = max + 1;
        while (m < 82)
        {
            index = 0;
            for (int i = 0; i < 8; i++) d[i] = 0;
            
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j <= i; j++) {
                    d[i] += a[j] * b[i - j];
                }

                d[i + 1] += d[i] / m;
                d[i] %= m;
            }
            
            for (int i = 0; i < 8; i++) {
                if (c[i] != d[i]) {
                    index = 1;
                    break;
                }
            }

            if (index == 0) {
                result[k] = m;
                break;
            }

            m++;
            
        }
        
        if (index) result[k] = 0;
        
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", result[i]);
    }
    

    return 0;
}