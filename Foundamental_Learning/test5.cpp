#include<iostream>
using namespace std;

int find_max(int matrix[12][12], int path[10][2], int a, int b, int end_row, int end_col, int count);

int main()
{
	int n;
	cin >> n;
	int matrix[12][12] = {0};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i + 1][j + 1];
		}
	}

	int start_row, start_col, end_row, end_col;
	cin >> start_row >> start_col >> end_row >> end_col;

	int path[10][2] = {0};
	int a = find_max(matrix, path, start_row + 1, start_col + 1, end_row + 1, end_col + 1, 0);
	cout << a << endl;
	for (int i = 0; i < start_row - end_row; i++)
	{
		cout << '(' << path[i][0] - 1 << ',' << path[i][1] - 1 << ')';
	}
	
	
}

int find_max(int matrix[12][12], int path[10][2], int a, int b, int end_row, int end_col, int count)
{
	if (a == end_row + 1 )
	{
		if (b == end_col || b == end_col + 1 || b == end_col - 1)
		{
			path[count][0] = end_row;
			path[count][1] = end_col;
			return matrix[end_row][end_col];
		} else {
			return -100000;
		}
	} else {
		int max = -100000;
		int index = -100000;
		int index_i;
		for (int i = 0; i < 3; i++)
		{
			if (matrix[a - 1][b - 1 + i] == 0)
			{
				index = -100000;
			} else {
				path[count][0] = a - 1;
				path[count][1] = b - 1 + i;
				index = matrix[a - 1][b - 1 + i] + find_max(matrix, path, a - 1, b - 1 + i, end_row, end_col, count + 1);
				
			}
			
			if (index > max)
			{
				max = index;
				index_i = i;
			}
		}
		
		if (max < 0)
		{
			return -100000;
		} else {
			path[count][0] = a - 1;
			path[count][1] = b - 1 + index_i;
			find_max(matrix, path, a - 1, b - 1 + index_i, end_row, end_col, count + 1);
			return max;
		}
	}
	
}