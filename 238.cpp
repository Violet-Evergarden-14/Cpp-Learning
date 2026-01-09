#include <iostream>
#include <vector>
using namespace std;

void merge(vector<vector<int>>& list, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int count = 0;
	vector<vector<int>> temp(right - left + 1, vector<int>(2));
	while (i <= mid && j <= right)
	{
		if (list[i][0] < list[j][0] || (list[i][0] == list[j][0] && list[i][1] < list[j][1]))
		{temp[count][0] = list[i][0]; temp[count][1] = list[i][1]; i++;}
		else {temp[count][0] = list[j][0]; temp[count][1] = list[j][1]; j++;}
		count++;
	}

	while (i <= mid) {temp[count][0] = list[i][0]; temp[count][1] = list[i][1]; i++; count++;}
	while (j <= right) {temp[count][0] = list[j][0]; temp[count][1] = list[j][1]; j++; count++;}
	
	for (int t = 0; t < count; t++) {list[left + t][0] = temp[t][0]; list[left + t][1] = temp[t][1];}
}

void merge_sort(vector<vector<int>>& list, int left, int right)
{
	if (left >= right) return;
	int mid = (left + right) / 2;

	merge_sort(list, left, mid);
	merge_sort(list, mid + 1, right);
	merge(list, left, mid, right);
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> qujian(n, vector<int>(2));
	for (int i = 0; i < n; i++)
	{
		cin >> qujian[i][0] >> qujian[i][1];
	}

	merge_sort(qujian, 0, n - 1);
	int min_max = qujian[0][0];
	int max_min = qujian[0][1];
	
	int count = 0;
	int search_index = 0;
	while (1)
	{
		min_max = qujian[search_index][0];
		if (qujian[search_index][1] < max_min) max_min = qujian[search_index][1];
		
		if (min_max > max_min) {
			count++;
			max_min = qujian[search_index][1];
		} else {
			search_index++;
		}

		if (search_index == n) {
			count++;
			break;
		}
	}
	
	cout << count;
}
