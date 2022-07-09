#include <stdio.h>

float x, y;

int main() {
    char j;
    if (scanf("%f%f%c", &x, &y, &j) != 3 || j != '\n')
        printf("n/a");
    else if (x * x + y * y < 25)
        printf("GOTCHA\n");
    else {
        printf("MISS\n");
    }
    return 0;
}
