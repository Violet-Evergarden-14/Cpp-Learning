#include <stdio.h>


int A(int i) {
    if (i == 6 || i == 8) { return 1; }
    return 0;
}

int B(int i) {
    if (i == 2) { return 1; }
    return 0;
}

int C(int i) {
    if (i == 7) { return 1; }
    return 0;
}

int D(int i) {
    if (i != 2) { return 1; }
    return 0;
}

int E(int i) {
    if (A(i)) { return 0; }
    return 1;
}

int F(int i) {
    if (i != 6 && i != 8 ) { return 1; }
    return 0;
}

int G(int i) {
    if (i != 3) { return 1; }
    return 0;
}

int H(int i) {
    if (A(i)) { return 1; }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);

    int target, index = 0, m;
    int sum;
    for (target = 1; target <= 8; target++) {
        sum = A(target) + B(target) + C(target) + D(target) + E(target) + F(target) + G(target) + H(target);
        if (sum == n) {
            index++;
            m = target;
        }
    }
    
    if (index == 1) {
        printf("%c", 'A' - 1 + m);
    } else {
        printf("DONTKNOW");
    }
    

    return 0;
}
