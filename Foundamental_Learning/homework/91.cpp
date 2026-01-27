#include <iostream>
using namespace std;

class Songs
{
public:
	int id;
	int distance_square;
};

int o_distance_square(int a[16], int b[16]);
void change(Songs* a, Songs* b);

int main()
{
	int n0;
	cin >> n0;
	int vector_origin[16] = {0};
	int vector_temp[16];
	int input_number;
	for (int i = 0; i < n0; i++)
	{
		cin >> input_number;
		vector_origin[input_number / 16]++;
	}
	
	int n, k;
	cin >> n >> k;
	Songs list[n];
	int number_of_the_frequency;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			vector_temp[j] = 0;
		}
		
		list[i].id = i;
		cin >> number_of_the_frequency;

		for (int j = 0; j < number_of_the_frequency; j++)
		{
			cin >> input_number;
			vector_temp[input_number / 16]++;
		}
		
		list[i].distance_square = o_distance_square(vector_origin, vector_temp);
	}
	
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (list[j].distance_square > list[j + 1].distance_square ||
				(list[j].distance_square == list[j + 1].distance_square && list[j].id > list[j + 1].id))
			{
				change(&list[j], &list[j + 1]);
			}
		}
	}
	
	for (int i = 0; i < k; i++)
	{
		cout << list[i].id << " ";
	}
	
}

int o_distance_square(int a[16], int b[16])
{
	int sum = 0;
	int temp;
	for (int i = 0; i < 16; i++)
	{
		temp = a[i] - b[i];
		sum += temp * temp;
	}
	return sum;
}

void change(Songs* a, Songs* b)
{
	int temp;
	temp = a->id;
	a->id = b->id;
	b->id = temp;
	temp = a->distance_square;
	a->distance_square = b->distance_square;
	b->distance_square = temp;
}