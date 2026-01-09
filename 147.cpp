#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int number[8] = {120, 40, 85, 50, 100, 140, 70, 100};
    int count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 8; l++) {
                    if (i != j && i != k && i != l && j != k && j != l && k != l) {
                        if (number[i] >= a && number[j] >= b && number[k] >= c && number[l] >= d) {
                            cout << i + 1 << " " << j + 1 << " " << k + 1 << " " << l + 1 << endl;
                            count++;
                        }
                        
                    }
                    
                }
            }
        }
    }

    if (count == 0)
    {
        cout << "-1" << endl;
    }
    

}