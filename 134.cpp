#include <iostream>

class guess
{
public:
    int guess_number, r_number, r_position;
    int guess_number_list[4];
};

using namespace std;


int right_number(int i, int j, int k, int l, int list[4]);
int right_position(int i, int j, int k, int l, int list[4]);



int main()
{
    int n;
    cin >> n;
    guess list[n];

    for (int i = 0; i < n; i++) {
        cin >> list[i].guess_number;
        for (int j = 0; j < 4; j++) {
            list[i].guess_number_list[j] = list[i].guess_number % 10;
            list[i].guess_number /= 10;
        }
        
        cin >> list[i].r_number >> list[i].r_position;
    }
    
    int count = 0;
    int index = 0;
    int s;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                for (int l = 1; l < 10; l++) {
                    index = 0;
                    for (int m = 0; m < n; m++) {
                        if (right_number(i, j, k, l, list[m].guess_number_list) == list[m].r_number &&
                        right_position(i, j, k, l, list[m].guess_number_list) == list[m].r_position) {
                            index++;
                        }
                    }
                    if (index == n)
                    {
                        s = i + j * 10 + k * 100 + l * 1000;
                        count++;
                    }
                    
                }
            }
        }
    }
    
    if (count == 1)
    {
        cout << s << endl;
    } else {
        cout << "Not sure" << endl;
    }
    

    return 0;
}

int right_number(int i, int j, int k, int l, int list[4])
{
    int count = 0;
    int list_local[4];
    for (int i = 0; i < 4; i++)
    {
        list_local[i] = list[i];
    }
    
    for (int m = 0; m < 4; m++)
    {
        if (i == list_local[m])
        {
            count++;
            list_local[m] = 10;
            break;
        }
    }
    for (int m = 0; m < 4; m++)
    {
        if (j == list_local[m])
        {
            count++;
            list_local[m] = 10;
            break;
        }
    }
    for (int m = 0; m < 4; m++)
    {
        if (k == list_local[m])
        {
            count++;
            list_local[m] = 10;
            break;
        }
    }
    for (int m = 0; m < 4; m++)
    {
        if (l == list_local[m])
        {
            count++;
            list_local[m] = 10;
            break;
        }
    }
    return count;
}

int right_position(int i, int j, int k, int l, int list[4])
{
    int count = 0;
    if (list[0] == i) count++;
    if (list[1] == j) count++;
    if (list[2] == k) count++;
    if (list[3] == l) count++;
    return count;
}