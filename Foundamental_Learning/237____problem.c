#include <stdio.h>

int abs(int a);

int main()
{
    int n;
    scanf("%d", &n);

    int number[n], sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &number[i]);
        sum += number[i];
    }
    int ave = sum / n;
    for (int i = 0; i < n; i++) {
        number[i] -= ave;
    }

    int max = abs(number[0]);
    for (int i = 0; i < n - 1; i++) {
        if (abs(number[i + 1]) > abs(number[i])) {
            max = abs(number[i + 1]);
        }
    }

    int move, move_copy;
    int minus[n];

    minus[0] = -5 * max;
    move = abs(minus[0]);
    for (int i = 1; i < n; i++) {
        minus[i] = number[i] + minus[i - 1];
        move += abs(number[i]);
    }
    move_copy = move;

    int a = minus[0];
    for (int index = -5 * max + 1; index < 5 * max; index++) {
        minus[0] = index;
        move = abs(minus[0]);
        for (int i = 1; i < n; i++) {
            minus[i] = number[i] + minus[i - 1];
            move += abs(minus[i]);
        }
        if (move < move_copy) {
            move_copy = move;
            a = index;
        }
    }
    
    sum = abs(a);
    minus[0] = a;
    printf("%d\n", minus[0]);

    for (int i = 1; i < n; i++)
    {
        minus[i] = number[i] + minus[i - 1];
        printf("%d\n", minus[i]);
        sum += abs(minus[i]);
    }
    

    printf("%d", sum);

    return 0;
}

int abs(int a)
{
    if (a >= 0) {
        return a;
    } else {
        return -a;
    }
}