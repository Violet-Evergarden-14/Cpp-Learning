#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    int avg = sum / n;
    
    vector<int> s(n);
    s[0] = a[0] - avg;
    for (int i = 1; i < n; ++i) {
        s[i] = s[i-1] + (a[i] - avg);
    }
    
    sort(s.begin(), s.end());
    int mid = s[n/2];  // 取中位数
    
    int total = 0;
    for (int num : s) {
        total += abs(num - mid);
    }
    cout << total << endl;
    return 0;
}