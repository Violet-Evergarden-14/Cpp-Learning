#include <stdio.h>
#include <cmath>

int main()
{
    int n[21];
    int count = 0;
    int m, result;
    int c, index = 0;
    for (int i = 0; i < 21; i++)
    {
        scanf("%d", &n[i]);
        count++;
        if (n[i] == 0) break;
    }
    

    for (int i = 0; i < count - 1; i++) {
        m = sqrt(n[i]) + 1;
        while (1) {
            index = 0;
            c = n[i];
            for (int j = 0; j < m; j++) {
                if (c % m != 1) break;
                c -= c / m + 1;
                index++;
            }
            
            if (c % m == 0 && index == m) {
                printf("%d\n", m);
                break;
            }

            m--;

            if (m == 1) {
                printf("no solution\n");
                break;
            }
        }
    }
    


    return 0;
}