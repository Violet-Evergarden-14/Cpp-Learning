#include <iostream>
using namespace std;

long long jiecheng(int n);

int main()
{
    int n;
    cin >> n;

    int list[n];
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }

    long long time = 1;

    for (int i = 0; i < n; i++)
    {
        if (list[i] != 1)
        {
            time += (list[i] - 1) * jiecheng(n - 1 - i);
        }
        
        for (int j = i + 1; j < n; j++)
        {
            if (list[j] > list[i])
            {
                list[j]--;
            }
        }
    }
    
    cout << time;
}

long long jiecheng(int n)
{
    if (n <= 1)
    {
        return 1;
    } else {
        return n * jiecheng(n - 1);
    }
}