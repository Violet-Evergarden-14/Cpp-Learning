#include <stdio.h>

double function(double a, double b, double c, double d, double x);
double deri(double a, double b, double c, double x);

int main()
{
    double a, b, c, d, change;
    int count = 0;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    double result[3] = {0.0};
    double number[10] = {0.0};

    for (int i = -100; i < 100 ; i++) {
        if (function(a, b, c, d, i) == 0) {
            result[count] = (float) i;
            count++;
            }
        
        if (function(a, b, c, d, i) * function(a, b, c, d, i + 1) < 0) {
            number[0] = i + 0.5;
            for (int t = 0; t < 9; t++) {
                number[t + 1] = number[t] - function(a, b, c, d, number[t]) / deri(a, b, c, number[t]);
            }
            result[count] = number[9];
            count++;
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (result[j] > result[j + 1]) {
                change = result[j];
                result[j] = result[j + 1];
                result[j + 1] = change;
            }
        }
    }
    

    for (int i = 0; i < 3; i++) {
        printf("%.2lf ", result[i]);
    }
    

    return 0;
}

double function(double a, double b, double c, double d, double x)
{
    double result = a * x * x * x + b * x * x + c * x + d;
    return result;
}

double deri(double a, double b, double c, double x)
{
    double result = 3 * a * x * x + 2 * b * x + c;
    return result;
}