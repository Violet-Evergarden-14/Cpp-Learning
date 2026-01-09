#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double cross(float a);

int main()
{
    int n, m, d;
    cin >> m >> d >> n;

    int w[d][m], v[n][d];
    int x[m] = {0};
    double h[d] = {0}, o[n] = {0};

    for (int i = 0; i < m; i++)
    {
        cin >> x[i];
    }

    for (int i = 0; i < d * m; i++)
    {
        cin >> w[i / m][i % m];
    }

    for (int i = 0; i < n * d; i++)
    {
        cin >> v[i / d][i % d];
    }
    
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < m; j++)
        {
            h[i] += w[i][j] * x[j];
        }
        h[i] = cross(h[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            o[i] += v[i][j] * h[j];
        }
        o[i] = cross(o[i]);
    }

    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++)
    {
        cout << o[i] << " ";
    }
    
}

double cross(float a)
{
    return 1 / (1 + exp(-a));
}