#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int weishu = n / 3 + 2;

    int huge[weishu] = {0};
    huge[0] = 3;

    int round = n / 24;
    int yu = n % 24;

    for (int j = 0; j < round; j++)
    {
        for (int i = 0; i < weishu; i++)
        {
            huge[i] *= 16777216;
        }

        for (int i = 0; i < weishu; i++)
        {
            huge[i + 1] += huge[i] / 10;
            huge[i] %= 10;
        }
    }

    for (int j = 0; j < yu; j++)
    {
        for (int i = 0; i < weishu; i++)
        {
            huge[i] *= 2;
        }

        for (int i = 0; i < weishu; i++)
        {
            huge[i + 1] += huge[i] / 10;
            huge[i] %= 10;
        }
    }

    int minus = 2 * n + 3;
    int count = 0;
    while (minus > 0)
    {
        huge[count] -= minus % 10;
        count++;
        minus /= 10;
    }
    for (int i = 0; i < 15; i++)
    {
        if (huge[i] < 0)
        {
            huge[i] += 10;
            huge[i + 1] -= 1;
        }
    }
    
    
    count = 0;
    for (int i = weishu - 1; i >= 0; i--)
    {
        if (huge[i])
        {
            break;
        } else {
            count++;
        }
    }
    
    int result[weishu - count];
    for (int i = 0; i < weishu - count; i++) {
        result[i] = huge[-i + weishu - count - 1];
    }
    
    
    
    for (int i = 0; i < weishu - count; i++)
    {
        cout << result[i];
    }
    

}