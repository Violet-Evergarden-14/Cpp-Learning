#include <stdio.h>
#include <math.h>

long long jiecheng(int x);
double cifang(double x, int number);

int main()
{
    const double pi = acos(-1.0);
    double x, e, sin = 0.0, cos = 1.0;
    scanf("%lf %lf", &x, &e);
    int count = 2, s = 2;

    if (x > pi)
    {
            while (x > pi)
        {
            x -= pi;
            count++;
        }
        s = count;
    }
    
    if (x < -pi){
        while (x < -pi)
    {
        x += pi;
        count++;
    }s = count;
    }

    
    count = 1;
    do
    {
        sin += cifang(x, 2 * count - 1) * cifang(-1, count + 1) / jiecheng(2 * count - 1);
        count++;
    } while (cifang(x, 2 * count - 1) / jiecheng(2 * count - 1) >= e);
    printf("%lf\n", sin * cifang(-1, s));

    count = 1;
    do
    {
        cos += cifang(x, 2 * count) * cifang(-1, count) / jiecheng(2 * count);
        count++;
    } while (cifang(x, 2 * count) / jiecheng(2 * count) >= e);
    printf("%lf", cos * cifang(-1, s));
    

    return 0;
}

long long jiecheng(int x)
{
    long long result = 1;
    for (int i = 0; i < x; i++)
    {
        result *= (i + 1);
    }
    return result;
}

double cifang(double x, int number)
{
    double result = 1.0;
    for (int i = 0; i < number; i++)
    {
        result *= x;
    }
    return result;
}