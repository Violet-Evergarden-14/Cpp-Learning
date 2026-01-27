#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        for (int j = 1; j <= (n - 2 * i) / 6; j++)
        {
            for (int k = 1; k <= n - 2 * i - 6 * j; k++)
            {
                if (i != j && j != k && k != i && i % 2 == 0 && k % 10 == 8 && (2 * i + 6 * j + k) * 10 > 9 * n)
                {
                    if (k < i && i < j)
                    {
                        if (j < 10)
                        {
                            if (i > 9 && i < 100)
                            {
                                count++;
                                cout << i << " " << j << " " << k << endl;
                            }
                            
                        } else {
                            count++;
                            cout << i << " " << j << " " << k << endl;
                        }
                        
                        
                    }
                    
                    if (k > i && i > j)
                    {
                        if (j < 10)
                        {
                            if (i > 9 && i < 100)
                            {
                                count++;
                                cout << i << " " << j << " " << k << endl;
                            }
                            
                        } else {
                            count++;
                            cout << i << " " << j << " " << k << endl;
                        }
                    }
                    
                }
                
            }
            
        }
        
    }
    
    if (count == 0)
    {
        cout << "no answer" << endl;
    }
    
}