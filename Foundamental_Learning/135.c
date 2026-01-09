#include <stdio.h>
#include <string.h>

void change(char a[][18], int k);
int judge(char a[][18], int k);

int main()
{
    int n;
    scanf("%d", &n);

    char id[n][18];
    char useless;

    for (int i = 0; i < n; i++) {
        scanf("%c", &useless);
        for (int j = 0; j < 18; j++) {
            scanf("%c", &id[i][j]);
        }
    }
    
    for (int j = 0; j < n - 1; j++) {
        for (int i = 0; i < n - j - 1; i++) {
            change(id, i);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 18; j++) {
            printf("%c", id[i][j]);
        }
        printf("\n");
    }

    
    return 0;
}

int judge(char a[][18], int k)
{
    for (int i = 6; i < 14; i++) {
        if (a[k][i] != a[k + 1][i]) {
            return a[k][i] < a[k + 1][i];
        }
    }

    for (int i = 0; i < 18; i++) {
        if (a[k][i] != a[k + 1][i]) {
            return a[k][i] < a[k + 1][i];
        }
    }
}

void change(char a[][18], int k)
{
    char c;
    if (judge(a, k)) {
        for (int i = 0; i < 18; i++) {
            c = a[k][i];
            a[k][i] = a[k + 1][i];
            a[k + 1][i] = c;
        }
    }
}