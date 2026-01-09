#include <stdio.h>

class Dots
{
public:
    char uesless;
    int index[3];
};

int judge(Dots &a);
void average(Dots &a, Dots &b, Dots &c, Dots &d, Dots &target);

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    Dots dot[n + 2][m + 2];
    Dots shadow[n + 2][m + 2];
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < m + 2; j++) {
            dot[i][j].index[0] = 0; 
            dot[i][j].index[1] = 0;
            dot[i][j].index[2] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %c %d %c %d %c %d", 
            &dot[i][j].uesless, &dot[i][j].index[0], 
            &dot[i][j].uesless, &dot[i][j].index[1], 
            &dot[i][j].uesless, &dot[i][j].index[2]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            shadow[i][j] = dot[i][j];
        }
    }

    for (int k = 0; k < n + m - 2; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (judge(dot[i][j])) {
                    average(dot[i - 1][j], dot[i + 1][j], dot[i][j - 1], dot[i][j + 1], shadow[i][j]);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dot[i][j] = shadow[i][j];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("R %d G %d B %d ", dot[i][j].index[0], dot[i][j].index[1], dot[i][j].index[2]);
        }
        printf("\n");
    }


    return 0;
}

int judge(Dots &a)
{
    if (a.index[0] == 0 && a.index[1] == 0 && a.index[2] == 0) {
        return 1;
    } else {
        return 0;
    }
}

void average(Dots &a, Dots &b, Dots &c, Dots &d, Dots &target)
{
    int result_index[3] = {0};
    int count = 0;
    for (int i = 0; i < 3; i++) {
        if (judge(a) == 0)  {result_index[i] += a.index[i]; count++;}
        if (judge(b) == 0)  {result_index[i] += b.index[i]; count++;}
        if (judge(c) == 0)  {result_index[i] += c.index[i]; count++;}
        if (judge(d) == 0)  {result_index[i] += d.index[i]; count++;}
    }
    count /= 3;

    if (count) {
        for (int i = 0; i < 3; i++) {
            if (result_index[i] % count) {
                target.index[i] = result_index[i] / count + 1;
            } else {
                target.index[i] = result_index[i] / count;
            }
        }
    }
}