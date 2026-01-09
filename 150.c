#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int pupil_number[1000] = {0};
    int pupil_score[1000] = {0};
    int number, score;
    int rank[1000];

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &pupil_number[i], &pupil_score[i]);
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (pupil_score[j] < pupil_score[j + 1]) {
                score = pupil_score[j];
                pupil_score[j] = pupil_score[j + 1];
                pupil_score[j + 1] = score;
                number = pupil_number[j];
                pupil_number[j] = pupil_number[j + 1];
                pupil_number[j + 1] = number;
            }
        }
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (pupil_score[j] == pupil_score[j + 1] && pupil_number[j] > pupil_number[j + 1]) {
                score = pupil_score[j];
                pupil_score[j] = pupil_score[j + 1];
                pupil_score[j + 1] = score;
                number = pupil_number[j];
                pupil_number[j] = pupil_number[j + 1];
                pupil_number[j + 1] = number;
            }
        }
    }

    rank[0] = 1;
    for (int i = 1; i < n; i++) {
        if (pupil_score[i] == pupil_score[i - 1]) {
            rank[i] = rank[i - 1];
        } else {
            rank[i] = i + 1;
        } 
    }

    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", rank[i], pupil_number[i], pupil_score[i]);
    }

    return 0;
}