#include <stdio.h>
#include <math.h>

int judge(int number);

int main()
{
	int target, count = 1;
	scanf("%d", &target);

	for (int i = 3; i <= target / 2; i += 2)
	{
		if (judge(i) == 0 && judge(target - i) == 0)
		{
			printf("%d=%d+%d", target, i, target - i);
			count = 0;
			break;
		}
	}
	
	if (count)
	{
		printf("NO RESULT!!!");
	}
	
	return 0;
}

int judge(int number) 
{
	int sqrt_result, index = 0;
	sqrt_result = sqrt(number);

	for (int i = 2; i <= sqrt_result; i++)
	{
		if (number % i == 0)
		{
			index = 1;
			break;
		}
	}
	
	return index;
}



