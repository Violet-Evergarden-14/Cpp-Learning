#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a, b;

    int list[n];
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }

    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (list[i] > list[i + 1])
            {
                a = list[i];
                list[i] = list[i + 1];
                list[i + 1] = a;
            }
        }
    }
    
    a = 0;
    b = n - 1;
    int c = (a + b) / 2;
    int count = 1;
    int index = 1;
    while (b >= a)
    {
        if (list[c] == m)
        {
            cout << c << endl;
            index = 0;
            break;
        } else if (list[c] < m) {
            a = c + 1;
            if (c == b) break;
        } else {
            b = c - 1;
            if (c == a) break;
        }


        
        
        c = (a + b) / 2;
        count++;
        
    }

    if (index)
    {
        cout << -1 << endl;
    }
    
    
    cout << count;
    
}