#include <iostream>
using namespace std;

int MAX(int time[5000][2], int n);
int find_min(int time[5000][2], int n, int start, int table[5000][2], int count);
int find_max(int time[5000][2], int n, int start, int end);
int find_online(int time[5000][2], int n, int table[5000][2]);
int time_online_max(int table[5000][2], int count);
int  time_offline_max(int table[5000][2], int count);

int main()
{
	int n;
	cin >> n;
	
	int time[5000][2];
	for (int i = 0; i < n; i++)
	{
		cin >> time[i][0] >> time[i][1];
	}

	int table[5000][2];
	
	int count = find_online(time, n, table);

	cout << time_online_max(table, count) << " " << time_offline_max(table, count);

}

int find_online(int time[5000][2], int n, int table[5000][2])
{
	int end, start = -1, temp, count = 0;
	int max = MAX(time, n);
	do {
		end = find_min(time, n, start, table, count);
		start = table[count][0];
		do {
			temp = find_max(time, n, start, end);

			if (temp != -1)
			{
				start = end;
				end = temp;
			} else {
				table[count][1] = end;
				start = end;
				count++;
				break;
			}
		} while (1);
		
	} while (end < max);

	return count;
}

int find_max(int time[5000][2], int n, int start, int end)
{
	int max = -1;

	for (int i = 0; i < n; i++)
	{
		if (time[i][0] >= start && time[i][0] <= end)
		{
			if (time[i][1] > max)
			{
				max = time[i][1];
			}
		}
	}
	
	return max;
}

int find_min(int time[5000][2], int n, int start, int table[5000][2], int count)
{
	int min;
	int max;
	int index = 0;

	for (int i = 0; i < n; i++)
	{
		if (time[i][0] > start)
		{
			index = 1;
			min = time[i][0];
			max = time[i][1];
			break;
		}
	}

	if (index)
	{
		for (int i = 0; i < n; i++)
		{
			if (time[i][0] > start && time[i][0] < min)
			{
				min = time[i][0];
				max = time[i][1];
			}

			if (time[i][0] == min && time[i][1] > max)
			{
				max = time[i][1];
			}
		}
		
		table[count][0] = min;

		return max;
	}
	
	return -1;
}

int MAX(int time[5000][2], int n)
{
	int max = time[5000][1];
	for (int i = 0; i < n; i++)
	{
		if (time[i][1] > max)
		{
			max = time[i][1];
		}
	}
	
	return max;
}

int time_offline_max(int table[5000][2], int count)
{
	if (count == 1)
	{
		return 0;
	}
	
	int max = table[1][0] - table[0][1];
	for (int i = 0; i < count - 1; i++)
	{
		if (table[i + 1][0] - table[i][1] > max)
		{
			max = table[i + 1][0] - table[i][1];
		}
	}

	return max;
}	

int time_online_max(int table[5000][2], int count)
{
	int max = table[0][1] - table[0][0];
	for (int i = 0; i < count; i++)
	{
		if (table[i][1] - table[i][0] > max)
		{
			max = table[i][1] - table[i][0];
		}
	}
	
	return max;
}