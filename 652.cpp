#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n > 0)
    {
        cout << n * (n + 1) / 2 << endl;
    } else {
        cout << 1 + n * (1 - n) / 2 << endl;
    }
    
}