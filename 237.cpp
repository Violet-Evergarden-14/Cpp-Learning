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

    int sum_up[n];
    sum_up[0] = 0;

    for (int i = 1; i < n; i++) {
        sum = 0;
        for (int j = 0; j < i; j++) {
            sum += number[j];
        }
        sum_up[i] = sum;
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (sum_up[j] > sum_up[j + 1]) {
                sum = sum_up[j];
                sum_up[j] = sum_up[j + 1];
                sum_up[j + 1] = sum;
            }
        }
    }

    int mid = sum_up[n / 2];
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += abs(mid - sum_up[i]);
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