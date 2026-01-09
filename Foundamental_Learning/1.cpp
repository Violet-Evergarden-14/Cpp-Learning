#include <iostream>
using namespace std;

void pailie(int n, int list[])
{
    if (n == 1) {
        cout << list[0] << endl;
        return;
    }
    int deleted_list[n - 1];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cout << list[i];
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                deleted_list[count] = list[j];
                count++;
            }
        }
        pailie(n - 1, deleted_list);
    }
    return;
}

int main()
{
    int list[3];
    for (int i = 0; i < 3; i++)
    {
        list[i] = i + 1;
    }
    
    pailie(3, list);
}