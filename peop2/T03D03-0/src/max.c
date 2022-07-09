#include <stdio.h>

int max(int a, int b);

int main() {
    int x, y;
    char j;
    if (scanf("%d%d%c", &x, &y, &j) != 3 || j != '\n')
        printf("n/a\n");
    else {
        printf("%d\n", max(x, y));
    }
    return 0;
}

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}
