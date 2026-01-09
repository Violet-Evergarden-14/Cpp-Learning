#include <iostream>

using namespace std;

int time(int a);

int main()
{
    int m, n;
    cin >> m >> n;
    int sum = 0;

    for (int i = m; i <= n; i++)
    {
        sum += i * time(i);
    }
    
    cout << sum << endl;
}

int time(int a)
{
    if (a % 4 == 2 || a % 4 == 1)
    {
        return 1;
    }
    return -1;
    
}