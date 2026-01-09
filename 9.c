#include <stdio.h>

int main()
{
    int int_a, int_b;
    float float_a, float_b;
    char char_a, char_b;

    scanf("%d,%d", &int_a, &int_b);
    scanf("%f %f", &float_a, &float_b);
    scanf(" %c, %c", &char_a, &char_b);

    printf("%d,%d\n", int_a, int_b);
    printf("%.1f %.1f\n", float_a, float_b);
    printf(" %c, %c\n", char_a, char_b);

    return 0;
}