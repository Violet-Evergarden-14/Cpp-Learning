#include <iostream>
using namespace std;

class Customers
{
private:

public:
	int shopping_number;
	int shopping_list[100];
};


int main()
{
	int n;
	cin >> n;

	Customers list[n];

	for (int i = 0; i < n; i++)
	{
		cin >> list[i].shopping_number;
		for (int j = 0; j < list[i].shopping_number; j++)
		{
			cin >> list[i].shopping_list[j];
		}
	}

	int temp;
	for (int i = 0; i < list[0].shopping_number - 1; i++)
	{
		for (int j = 0; j < list[0].shopping_number - 1; j++)
		{
			if (list[0].shopping_list[j] > list[0].shopping_list[j + 1])
			{
				temp = list[0].shopping_list[j];
				list[0].shopping_list[j] = list[0].shopping_list[j + 1];
				list[0].shopping_list[j + 1] = temp;
			}
		}
	}
	
	
	int judge = 0;
	int inner_judge;
	int inner_inner_judge;
	for (int i = 0; i < list[0].shopping_number; i++)
	{
		inner_judge = 1;
		for (int j = 1; j < n; j++)
		{
			inner_inner_judge = 0;
			for (int k = 0; k < list[j].shopping_number; k++)
			{
				if (list[j].shopping_list[k] == list[0].shopping_list[i])
				{
					inner_inner_judge = 1;
					break;
				}
			}

			if (inner_inner_judge == 0)
			{
				inner_judge = 0;
				break;
			}
		}

		if (inner_judge)
		{
			judge = 1;
			cout << list[0].shopping_list[i] << " ";
		}
	}

	if (judge == 0)
	{
		cout << "NO";
	}
}