#include <iostream>
using namespace std;

int main()
{
    int n1;
    cin >> n1;

    int a;
    int t1 = n1, t2 = n1, t3 = n1;
    char m, n;

    while (1)
    {
        cin >> a;
        if (a == 0)
        {
            break;
        }
        if (a == 1)
        {
            cin >> n >> m;
            if (n == 'A')
            {
                t1--;
                if (m == 'C')
                {
                    t2--;
                }
                if (m == 'D')
                {
                    t2--;
                    t3--;
                }
            }
            if (n == 'B')
            {
                t2--;
                if (m == 'D')
                {
                    t3--;
                }
            }
            if (n == 'C')
            {
                t3--;
            }
        }
        if (a == 2)
        {
            cin >> n >> m;
            if (n == 'A')
            {
                t1++;
                if (m == 'C')
                {
                    t2++;
                }
                if (m == 'D')
                {
                    t2++;
                    t3++;
                }
            }
            if (n == 'B')
            {
                t2++;
                if (m == 'D')
                {
                    t3++;
                }
            }
            if (n == 'C')
            {
                t3++;
            }
        }
    }

    int min = t1;
    if (t2 < min)
    {
        min = t2;
    }
    if (t3 < min)
    {
        min = t3;
    }
    
    cout << min;
    
}