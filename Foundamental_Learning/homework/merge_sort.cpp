#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& list, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int count = 0;
	vector<int> temp(right - left + 1);
	while (i <= mid && j <= right)
	{
		if (list[i] < list[j]) {temp[count] = list[i]; i++;}
		else {temp[count] = list[j]; j++;}
		count++;
	}

	while (i <= mid) {temp[count++] = list[i++];}
	while (j <= right) {temp[count++] = list[j++];}
	
	for (int i = 0; i < count; i++) {list[left + i] = temp[i];}
}

void merge_sort(vector<int>& list, int left, int right)
{
	if (left >= right) return;
	int mid = (left + right) / 2;

	merge_sort(list, left, mid);
	merge_sort(list, mid + 1, right);
	merge(list, left, mid, right);
}

int main()
{
	vector<int> list = {548, 48,1951, 4,8,444,88938,4 ,14,1708};
	merge_sort(list, 0, 9);
}