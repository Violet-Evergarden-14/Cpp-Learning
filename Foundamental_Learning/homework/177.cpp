#include <iostream>
using namespace std;

int judge(int number, int k);

int main()
{
    int n, k;
    cin >> n >> k;

    int number[n];
    int index[n] = {0};
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> number[i];
        if (judge(number[i], k)) {
            count++;
            index[i] = 1;
        } else {
            index[i] = 0;
        }
    }

    cout << count << endl;
    int satisfied[count];
    int a = 0;
    int change;
    for (int i = 0; i < n; i++)
    {
        if (index[i])
        {
            satisfied[a] = number[i];
            a++;
        }
        
        if (a == count)
        {
            break;
        }
    }


    for (int j = 0; j < count - 1; j++)
    {
        for (int i = 0; i < count - 1; i++)
        {
            if (satisfied[i] > satisfied[i + 1])
            {
                change = satisfied[i];
                satisfied[i] = satisfied[i + 1];
                satisfied[i + 1] = change;
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        cout << satisfied[i] << endl;
    }
    
    
    
}

int judge(int number, int k)
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += number % 10;
        number /= 10;
    }
    
    if (sum % k) return 0;

    return 1;
}

