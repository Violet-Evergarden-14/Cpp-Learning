#include <iostream>
using namespace std;

int diffusion(int map[102][102], int a, int b);
int find_island(int map[102][102], int island_index[5000], int n, int m);

int main()
{
	int n, m;
	cin >> n >> m;

	char in;
	int map[102][102] = {0};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> in;
			if (in == '.')
			{
				map[i + 1][j + 1] = 0;
			} else {
				map[i + 1][j + 1] = 1;
			}
		}
	}
	
	int island_index[5000] = {0};
	int island_number = find_island(map, island_index, n, m);

	if (island_number)
	{
		cout << island_number << " ";
		int max = island_index[0];
		for (int i = 0; i < island_number; i++)
		{
			if (island_index[i] > max)
			{
				max = island_index[i];
			}
		}
		
		cout << max;
	} else {
		cout << "0 0";
	}
	
}

int diffusion(int map[102][102], int a, int b)
{
	int count = 0;
	int around[3][3];
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (map[a + i][b + j])
			{
				around[i + 1][j + 1] = 1;
				count++;
				map[a + i][b + j] = 0;
			} else {
				around[i + 1][j + 1] = 0;
			}
		}
	}

	if (count == 0) return 0;
	
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (around[i + 1][j + 1])
			{
				count += diffusion(map, a + i, b + j);
			}
		}
	}

	return count;
}

int find_island(int map[102][102], int island_index[5000], int n, int m)
{
	int index = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j])
			{
				map[i][j] = 0;
				island_index[index] = 1 + diffusion(map, i, j);
				index++;
			}
		}
	}
	
	return index;
}