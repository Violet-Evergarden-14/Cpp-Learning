#include <stdio.h>

int function(int a, int b, int c, int d, int e, int x);

int main()
{
    int n, k, score1 = 0, score2 = 0, a, b, c, d, e, x;
    scanf("%d %d", &n, &k);
    int value, answer1, answer2, count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &x, &answer1, &answer2);
        value = function(a, b, c, d, e, x);

        if (answer2 == value)
        {
            count2++;
            if (count2 > k) {
                score2 += 1 + count2 - k;
            } else {
                score2 += 1;
            }   
        } else {
            count2 *= 0;
        }
        
        if (answer1 == value)
        {
            count1++;
            if (count1 > k) {
                score1 += 1 + count1 - k;
            } else {
                score1 += 1;
            }   
        } else {
            count1 *= 0;
        }
    }
    
    printf("%d %d", score1, score2);

    return 0;
}

int function(int a, int b, int c, int d, int e, int x)
{
    int result = a * x * x * x * x + b * x * x * x + c * x * x + d * x + e;
    return result;
}