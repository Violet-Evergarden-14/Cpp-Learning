#include <stdio.h>

class temperature
{
public:
    int number;
    char type;
};

int main()
{
    temperature high_tem;
    temperature low_tem;

    int n;
    scanf("%d", &n);
    temperature list[n];
    int hot_days = 0, cold_days = 0;

    scanf("%d%c", &high_tem.number, &high_tem.type);
    scanf("%d%c", &low_tem.number, &low_tem.type);

    for (int i = 0; i < n; i++) {
        scanf("%d%c", &list[i].number, &list[i].type);
    }
    
    double tem[n];
    for (int i = 0; i < n; i++) {
        if (list[i].type == 'C') {
            tem[i] = 1.8 * list[i].number + 32.0;
        } else {
            tem[i] = list[i].number;
        }
    }

    double high;
    if (high_tem.type == 'C') {
        high = 1.8 * high_tem.number + 32.0;
    } else {
        high = high_tem.number;
    }

    double low;
    if (low_tem.type == 'C') {
        low = 1.8 * low_tem.number + 32.0;
    } else {
        low = low_tem.number;
    }

    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += tem[i];
        if (tem[i] > high) {
            hot_days++;
        }
        if (tem[i] < low) {
            cold_days++;
        }
    }
    
    double ave = sum / n;
    printf("%.3lfF\n", ave);
    printf("%d %d", hot_days, cold_days);

    return 0;
}