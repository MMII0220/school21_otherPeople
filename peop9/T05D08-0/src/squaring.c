#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0) {
        squaring(data, n);
        output(data, n);
    } else {
        printf("n/a\n");
    }
    return 0;
}

int input(int *a, int *n) {
    int c = 0;
    if (scanf("%d", n) == 1 && *n > 0 && *n < 11) {
        for (int *p = a; p - a < *n; p++)
            if (scanf("%d", p) != 1)
                c = 1;
    } else {
        c = 1;
    } return c;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (p - a + 1 < n)
            printf(" ");
        else
            printf("\n");
    }
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++)
        *p = *p * *p;
}
