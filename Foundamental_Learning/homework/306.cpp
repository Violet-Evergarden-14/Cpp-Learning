#include <iostream>
using namespace std;

class num
{
public:
    int number;
    int time;
};

int main()
{
    int n;
    cin >> n;
    int count = 1;

    int a;
    int index = 1;
    
    num list[n];
    cin >> list[0].number;
    list[0].time = 1;
    for (int i = 1; i < n; i++)
    {
        cin >> a;
        index = 1;
        for (int j = 0; j < count; j++)
        {
            if (a == list[j].number)
            {
                list[j].time++;
                index = 0;
                break;
            }
        }
        if (index)
        {
            list[count].number = a;
            list[count].time = 1;
            count++;
        }
    }

    int _;
    for (int j = 0; j < count - 1; j++)
    {
        for (int i = 0; i < count - 1; i++)
        {
            if ((list[i].time < list[i + 1].time) ||
                (list[i].time == list[i + 1].time && list[i].number < list[i + 1].number))
            {
                _ = list[i].number;
                list[i].number = list[i + 1].number;
                list[i + 1].number = _;

                _ = list[i].time;
                list[i].time = list[i + 1].time;
                list[i + 1].time = _;
            }
        }
    }

    int m = 0;
    if (list[0].time == 1)
    {
        cout << "NO" << endl;
    } else {
        cout << list[0].number << " " << list[0].time << endl;
    }
    
    
}