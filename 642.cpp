#include <stdio.h>

int main()
{
    int price_1, price_2;
    int num_1, num_2;

    scanf("%d%d%d%d", &price_1, &price_2, &num_1, &num_2);
    int sum = num_1 * price_1 + num_2 * price_2;

    double total_price_1, total_price_2;

    switch (num_1 + num_2) {
    case 2:
        total_price_1 = sum * 0.9;
        break;
    case 3:
    case 4:
        total_price_1 = sum * 0.8;
        break;
    case 5:
        total_price_1 = sum * 0.7;
        break;
    }

    total_price_2 = sum - sum / 500 * 100;

    if (total_price_1 <= total_price_2) {
        printf("1 %.1lf", total_price_1);
    } else {
        printf("2 %.1lf", total_price_2);
    }
    


    return 0;
}