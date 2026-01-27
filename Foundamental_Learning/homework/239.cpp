#include <iostream>
#include <cstring>
using namespace std;

int multiple(int number[], int start_number, int length, int cross);
int multiple_number(int number[], int start, int end);
int time(int n);
int find_max(int col[], int start, int end);

int main()
{
    char shuzi[11];
    cin >> shuzi;
    int k;
    cin >> k;

    int length = strlen(shuzi);
    int number[length];
    for (int i = 0; i < length; i++) number[i] = shuzi[i] - '0';
    
	cout << multiple(number, 0, length, k);
}

int multiple(int number[], int start_number, int length, int cross)
{
	if (cross == 0)
	{
		return multiple_number(number, start_number, length - 1);
	}
	
	int col[length];
	for (int end = start_number; end < length - cross; end++)
	{
		col[end] = multiple_number(number, start_number, end) * multiple(number, end + 1, length, cross - 1);
	}
	return find_max(col, start_number, length - cross);
}

int multiple_number(int number[], int start, int end)
{
	int num = 0;
	for (int i = start; i <= end; i++)
	{
		num += number[i] * time(end - i);
	}
	return num;
}

int time(int n)
{
	int result = 1;
	for (int i = 0; i < n; i++)
	{
		result *= 10;
	}
	return result;
}

int find_max(int col[], int start, int end)
{
	int result = 0;
	for (int i = start; i < end; i++)
	{
		if (result < col[i])
		{
			result = col[i];
		}
	}
	return result;
}