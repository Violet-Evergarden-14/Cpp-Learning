#include <iostream>
#include <cstring>
using namespace std;

void translation();
int cifang(int a, int b);
int search(char a, char* standard_number, int jinzhi);

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "Case #" << i + 1 << ": ";
		translation();
	}
}

void translation()
{
	char alien_number[100], source_language[100], target_language[100], target_result[100];
	cin >> alien_number >> source_language >> target_language;

	int real_number_of_earth = 0;

	int jinzhi = strlen(source_language);
	int l = strlen(alien_number);

	for (int i = 0; i < l; i++)
	{
		real_number_of_earth += search(*(alien_number + i), source_language, jinzhi) * cifang(jinzhi, l - 1 - i);
	}
	
	int count = 0;
	int yushu;
	int target_jinzhi = strlen(target_language);
	while (1)
	{
		yushu = real_number_of_earth % target_jinzhi;
		real_number_of_earth /= target_jinzhi;
		*(target_result + count) = *(target_language + yushu);
		count++;
		if (real_number_of_earth <= 0)
		{
			break;
		}
	}
	
	char result[100];
	for (int i = 0; i < count; i++)
	{
		*(result + i) = *(target_result + count - 1 - i);
	}
	
	*(result + count) = '\0';
	cout << result << endl;
}

int cifang(int a, int b)
{
	int result = 1;
	for (int i = 0; i < b; i++)
	{
		result *= a;
	}
	return result;
}

int search(char a, char* standard_number, int jinzhi)
{
	int m = 0;
	while (1)
	{
		if (a == *(standard_number + m))
		{
			return m;
		}
		m++;
	}
}