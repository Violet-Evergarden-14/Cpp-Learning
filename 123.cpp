#include <iostream>
using namespace std;

void move(int n, char kaishi, char zhongdian, char xianzhi, int* count)
{
    if (n <= 0) return;
    else if (n == 1) {
        cout << "[step " << *count << "]    move plate " << 1 <<"# from " << kaishi << " to " << zhongdian <<endl;
        (*count)++;
        return;
    } else {
        move(n - 1, kaishi, xianzhi, zhongdian, count);
        cout << "[step " << *count << "]    move plate " << n <<"# from " << kaishi << " to " << zhongdian <<endl;
        (*count)++;
        move(n - 1, xianzhi, zhongdian, kaishi, count);
    }
}

int main()
{
    int n;
    cin >> n;

    int count = 1;

    move(n, 'a', 'c', 'b', &count);
    cout << count - 1 << endl;
}