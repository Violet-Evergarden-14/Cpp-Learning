#include <stdio.h>

int main() 
{
    int line, count = 1;
    scanf("%d", &line);

    int block[102] = {0};
    double rate[102] = {0.0};
    
    for (int i = 0; i < line; i++)
    {
        scanf("%d %lf", &block[i + 1], &rate[i + 1]);
    }
    
    int interest_0;
    scanf("%d", &interest_0);
    double interest = interest_0, result = 0.0;

    
    if (interest <= 0)
    {
        printf("NO");
    } else
    if (interest == 0)
    {
        printf("%.2lf", 0.0);
    } else
    if (interest <= block[1])
    {
        printf("%.2lf", interest * rate[1]);
    } else
    if (interest <= block[line - 1]) {
        while (interest > (block[count] - block[count - 1]))
        {
            interest -= block[count] - block[count - 1];
            result += (block[count] - block[count - 1]) * rate[count];
            count += 1;
        }

        result += interest * rate[count];
        printf("%.2lf", result);
    } else {
        for (int i = 1; i <= line; i++)
        {
            interest -= block[i] - block[i - 1];
            result += (block[i] - block[i - 1]) * rate[i];
        }
        result += interest * rate[line];
        printf("%.2lf", result);
    }
    
    return 0;
}