#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double price;
    int number;
    cin >> price >> number;
    double total;
    if (number == 1)
    {
        total = price;
    } else if (number == 2)
    {
        total = price * 2 * 0.8;
    } else if (number >= 3 && number <= 5)
    {
        total = price * number * 0.7;
    } else {
        total = price * 3.5 + price * 1.1 * (number - 5);
    }
    
    cout << fixed << setprecision(2) << total << endl;
    
}