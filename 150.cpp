#include <stdio.h>

class Student
{
public:
    int score;
    int id;
};

void change(Student &a, Student &b)
{
    Student contem = a;
    a = b;
    b = contem;
}

int main()
{
    int n;
    scanf("%d", &n);

    Student student[n];

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &student[i].id, &student[i].score);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (student[j].score < student[j + 1].score) {
                change(student[j], student[j + 1]);
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (student[j].score == student[j + 1].score && student[j].id > student[j + 1].id) {
                change(student[j], student[j + 1]);
            }
        }
    }
    
    int rank[n];
    rank[0] = 1;
    printf("%d %d %d\n", 1, student[0].id, student[0].score);

    for (int i = 1; i < n; i++) {
        if (student[i].score == student[i - 1].score) {
            rank[i] = rank[i - 1];
        } else {
            rank[i] = i + 1;
        }
        
        printf("%d %d %d\n", rank[i], student[i].id, student[i].score);
    }

    return 0;
}