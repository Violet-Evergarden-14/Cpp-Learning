#include <stdio.h>
#include <math.h>

int judge(int number);

int main()
{
	int number;
	scanf("%d", &number);

    int list[number];

    for (int i = 0; i < number; i++)
    {
        scanf("%d", &list[i]);
    }
    
    for (int i = 0; i < number; i++)
    {
        if (judge(list[i])) {
            printf("NO ");
        } else {
            printf("YES ");
        }
    }
    
	return 0;
}

int judge(int number)
{
	int sqrt_result, index = 0;
	sqrt_result = sqrt(number);

    if (number == 1)
    {
        index = 1;
    } else {
        for (int i = 2; i <= sqrt_result; i++) {
            if (number % i == 0) {
                index = 1;
                break;
            }
        }
    }
	
	return index;
}



