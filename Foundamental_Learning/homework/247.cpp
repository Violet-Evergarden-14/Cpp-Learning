#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int number(char a[10], char b[10], int list[10], int start, int l, int count, int shunxu);
int time(int a);

int main()
{
	char a[10], b[10];
	int l, count = 0, s;
	int list[10] = {0};

	while (1) {
		count = 0;
		gets(a);
		l = strlen(a);
		if (a[0] == '#')
		{
			break;
		}

		gets(b);
		
		for (int i = 0; i < l; i++)
		{
			if (a[i] == '?')
			{
				list[i] = 1;
				count++;
			} else {
				list[i] = 0;
			}
		}

		s = number(a, b, list, 0, l, count, 1);
		cout << s << endl;
	}
}

int number(char a[10], char b[10], int list[10], int start, int l, int count, int shunxu)
{
	if (start >= l)
	{
		return 0;
	}

	//下面的分类不能完全讨论出start>=l的情况，因此要讨论
	
	if (list[start])
	{
		if (start < l - 1) {
			return (9 - (b[start] - '0')) * time(count - shunxu) + number(a, b, list, start + 1, l, count, shunxu + 1);
		} else {
			return 9 - (b[start] - '0');
		}
	} else {
		if (a[start] > b[start])
		{
			return time(count - shunxu + 1);
		} else if (a[start] < b[start])
		{
			return 0;
		} else {
			return number(a, b, list, start + 1, l, count, shunxu);
		}
	}
}

int time(int a)
{
	int result = 1;
	for (int i = 0; i < a; i++)
	{
		result *= 10;
	}
	return result;
}