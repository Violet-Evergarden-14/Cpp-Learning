#include <iostream>
using namespace std;

void mission1(int number[], int m);
void mission2(int number[], int m);

int main()
{
    int n, m, g;
    cin >> n >> m >> g;

    int a;
    int number[m] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 100) {
            number[m - 1]++;
        } else {
            number[a * m / 100]++;
        }
    }

    if (g == 1)
    {
        mission1(number, m);
    } else if (g == 2) {
        mission2(number, m);
    } else {
        mission1(number, m);
        cout << endl;
        mission2(number, m);
    }
    
}

void mission1(int list[], int m)
{
    int max = 0;
    int index = 0;
    int number[m];
    for (int i = 0; i < m; i++)
    {
        number[i] = list[i];
    }

    for (int k = 0; k < m; k++)
    {
        max = number[0];

        
        

        for (int i = 1; i < m; i++) {
            if (number[i] > max) {
                max = number[i];
                index = i;
            }
        }

        if (max == 0)
        {
            break;
        }
        
        if (index == 0)
        {
            cout << "[ 0, " << 100 / m << "): " << max << endl;
        } else if (index == m - 1) {
            cout << "[" << 100 - 100 / m << ",100]: " << max << endl;
        } else {
            cout << "[" << 100 * index / m << ", " << 100 * (index + 1) / m << "): " << max << endl;
        }
        number[index] = 0;
            
        max = 0;
        index = 0;

    }
    
}

void mission2(int list[], int m)
{
    int max = 0;
    max = list[0];
    int number[m];

    for (int i = 0; i < m; i++)
    {
        number[i] = list[i];
    }
    

    for (int i = 1; i < m; i++) {
        if (number[i] > max) {
            max = number[i];
        }
    }

    if (max > 50)
    {
        for (int i = 0; i < m; i++)
        {
            number[i] = number[i] * 50 / max;
        }
    }

    for (int index = 0; index < m; index++)
    {
        if (index == 0)
        {
            cout << "[ 0, " << 100 / m << "):";
            for (int i = 0; i < number[index]; i++) {
                cout << "*";
            }
        } else if (index == m - 1) {
            cout << "[" << 100 - 100 / m << ",100]:";
            for (int i = 0; i < number[index]; i++) {
                cout << "*";
            }
        } else {
            cout << "[" << 100 * index / m << ", " << 100 * (index + 1) / m << "):";
            for (int i = 0; i < number[index]; i++) {
                cout << "*";
            }
        }
        cout << endl;
    }
}