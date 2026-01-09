#include <iostream>
using namespace std;

int c(int n, int m);
int j(int n);
void search(int sum, int list[], int n, int k, int a[]);
int check(int list[], int k);

int main()
{
    int n, sum;
    cin >> n >> sum;

    int list[n] = {-1};
    int a[1] = {0};
    search(sum, list, n, 0, a);
}

int c(int n, int m)
{
    return j(n) / j(m) / j(n - m);
}

int j(int n)
{
    if (n == 0)
    {
        return 1;
    }
    
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

void search(int sum, int list[], int n, int k, int a[])
{
    if (a[0])
    {
        return;
    }
    
    if (k == n - 1)
    {
        for (int i = 0; i < n; i++)
        {
            list[k] = i;
            if (check(list, n))
            {
                int sum_up = 0;
                for (int i = 0; i < n; i++)
                {
                    sum_up += (list[i] + 1) * c(n - 1, i);
                }

                if (sum == sum_up)
                {
                    for (int i = 0; i < n; i++)
                    {
                        cout << list[i] + 1 << " ";
                    }
                    a[0] = 1;
                }
            }
        }
    } else {
        for (int i = 0; i < n; i++)
        {
            list[k] = i;
            if (check(list, k + 1))
            {
                search(sum, list, n, k + 1, a);
            }
        }
    }
    return;
}

int check(int list[], int k)
{
    for (int i = 0; i < k - 1; i++)
    {
        if (list[i] == list[k - 1])
        {
            return 0;
        }
    }
    return 1;
}