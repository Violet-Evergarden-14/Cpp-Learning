#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
	char input[100];
	gets(input);
	int l = strlen(input);

	int judge_number[l];
	for (int i = 0; i < l; i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
		{
			judge_number[i] = 1;
		} else {
			judge_number[i] = 0;
		}
	}

	int count_dot = 0;
	for (int i = 0; i < l - 1; i++)
	{
		if (input[i] == '.' && judge_number[i + 1])
		{
			count_dot++;
		}
	}

	int start = 0, end = 0;
	int i = 0, j = 0;
	int count_int = 0;
	while (1)
	{
		if (i >= l)
		{
			break;
		}
		
		if (judge_number[i])
		{
			count_int++;
			start = i;
			end = i;
			j = i;
			while (1)
			{
				if (judge_number[j + 1])
				{
					end++;
					j++;
				} else {
					break;
				}
			}

			if (input[end + 1] == '.')
			{
				count_int -= 2;
			}

			i = end + 1;
		}
		
		i++;
	}
	
	cout << count_int << " " << count_dot << endl;
}