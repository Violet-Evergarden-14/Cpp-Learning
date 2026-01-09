#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int score[n], id[n];
    for (int i = 0; i < n; i++) {
        cin >> id[i] >> score[i];
    }

    int t;
    for (int j = 0; j < n -1; j++) {
        for (int i = 0; i < n - 1; i++) {
            if (score[i] < score[i + 1] ||
                (score[i] == score[i + 1] && id[i] > id[i + 1])) {
                    t = score[i + 1];
                    score[i + 1] = score[i];
                    score[i] = t;
                    t = id[i + 1];
                    id[i + 1] = id[i];
                    id[i] = t;
                }
        }
    }   
    t = m * 1.5;
    int index = score[t - 1];
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (score[i] >= index) {
            count++;
        } else {break;}
    }

    cout << index << " " << count << endl;

    for (int i = 0; i < n; i++) {
        if (score[i] >= index) {
            cout << id[i] << " " << score[i] << endl;
        } else {break;}
    }
}