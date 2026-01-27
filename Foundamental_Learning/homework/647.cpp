#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double height[n][n];
    double max = 0, min = 3, sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> height[i][j];
            if (height[i][j] < min) min = height[i][j];
            if (height[i][j] > max) max = height[i][j];
            sum += height[i][j];
        }
    }
    
    cout << fixed << setprecision(3) << max << " " << min << " " << setprecision(2) << sum / (n * n) << endl;

}