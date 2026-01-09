#include <iostream>
using namespace std;
#include <cmath>

class Targets
{
public:
    int id;
    int bazi[8];
    double similar;
};


double similarity(int a[8], int b[8]);

int main()
{
    int n, k;
    cin >> n >> k;
    int a[8];
    for (int i = 0; i < 8; i++)
    {
        cin >> a[i];
    }
    
    Targets list[n];

    for (int i = 0; i < n; i++)
    {
        cin >> list[i].id;
        for (int j = 0; j < 8; j++)
        {
            cin >> list[i].bazi[j];
        }
        list[i].similar = similarity(a, list[i].bazi);
    }

    int _;
    double __;
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if ((list[i].similar < list[i + 1].similar) ||
                (list[i].similar == list[i + 1].similar && list[i].id < list[i + 1].id))
            {
                _ = list[i].id;
                list[i].id = list[i + 1].id;
                list[i + 1].id = _;

                __ = list[i].similar;
                list[i].similar = list[i + 1].similar;
                list[i + 1].similar = __;
                
            }
        }
    }
    
    for (int i = 0; i < k; i++)
    {
        cout << list[i].id << " ";
    }
    
    

}

double similarity(int a[8], int b[8])
{
    double x = 0, y = 0, z = 0;
    for (int i = 0; i < 8; i++)
    {
        x += a[i] * b[i];
        y += a[i] * a[i];
        z += b[i] * b[i];
    }
    double result = x / (sqrt(y) * sqrt(z));
    return result;
}