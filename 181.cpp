#include <iostream>
using namespace std;

void run(int *x1, int *x2, int A, int B);

int main()
{
    int a, b, n;
    cin >> a >> b >> n;

    int x1 = 1;
    int x2 = 1;

    for (int i = 0; i < n - 2; i++) run(&x1, &x2, a, b);

    
    cout << x1;
}

void run(int *x1, int *x2, int A, int B)
{
    int p1 = *x1;
    int p2 = *x2;
    int m = (A * p1 + B * p2) % 7;
    *x2 = *x1;
    *x1 = m;
}