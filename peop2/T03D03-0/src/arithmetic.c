#include <stdio.h>

int sum(int a, int b);
int min(int a, int b);
int mul(int a, int b);
int del(int a, int b);

int main() {
    int x, y;
    char j;
    if (scanf("%d%d%c", &x, &y, &j) != 3 || j != '\n')
        printf("n/a");
    else {
        if (y != 0)
            printf("%d %d %d %d\n", sum(x, y), min(x, y), mul(x, y), del(x, y));
        else
            printf("%d %d %d n/a\n", sum(x, y), min(x, y), mul(x, y));
    }
    return 0;
}

int sum(int a, int b) { return a + b; }

int min(int a, int b) { return a - b; }

int mul(int a, int b) { return a * b; }

int del(int a, int b) { return a / b; }
