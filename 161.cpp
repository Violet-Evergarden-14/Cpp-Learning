#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    int change[4];
    for (int i = 0; i < 4; i++) {
        change[i] = (a % 10 + 5) % 10;
        a /= 10;
    }

    int count = 0;
    for (int i = 0; i < 4; i++) {
        if (change[i] || count) {
            count++;
            printf("%d", change[i]);
        }
    }

    return 0;
}