#include <stdio.h>
#include <math.h>
#define NMAX 30

int input(int *a, int *n);
int search(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n, double q);
void output_result(int result);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0) {
        output_result(search(data, n));
    } else {
        printf("n/a\n");
    } return 0;
}

int input(int *a, int *n) {
    int c = 0;
    if (scanf("%d", n) == 1 && *n > 0 && *n < 31) {
        for (int *p = a; p - a < *n; p++)
            if (scanf("%d", p) != 1)
                c = 1;
    } else {
        c = 1;
    } return c;
}

int search(int *a, int n) {
    int s = 0;
    double t, q;
    t = mean(a, n);
    q = variance(a, n, t);
    for (int *p = a; p - a < n; p++)
        if (*p % 2 == 0 && *p >= t && *p <= q && *p != 0 && s == 0)
            s = *p;
    return s;
}

void output_result(int result) {
    printf("%d\n", result);
}

double mean(int *a, int n) {
    double s = 0.0;
    for (int *p = a; p - a < n; p++)
        s = s + *p * 1.0 / n;
    return s;
}

double variance(int *a, int n, double q) {
    double s, s1 = 0.0, s2 = 0.0;
    for (int *p = a; p - a < n; p++) {
        s1 = s1 + *p * *p * 1.0 / n;
        s2 = s2 + *p * 1.0 / n;
    } s = q + 3 * sqrt(s1 - (s2 * s2));
    return s;
}
/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
