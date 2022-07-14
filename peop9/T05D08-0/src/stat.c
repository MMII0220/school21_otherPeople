#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0) {
        output(data, n);
        output_result(max(data, n),
                      min(data, n),
                      mean(data, n),
                      variance(data, n));
    } else {
        printf("n/a\n");
    } return 0;
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

int max(int *a, int n) {
    int s;
    for (int *p = a; p - a < n; p++) {
        if (p == a)
            s = *p;
        if (*p > s)
            s = *p;
    }
    return s;
}

int min(int *a, int n) {
    int s;
    for (int *p = a; p - a < n; p++) {
        if (p == a)
            s = *p;
        if (*p < s)
            s = *p;
    }
    return s;
}

double mean(int *a, int n) {
    double s = 0.0;
    for (int *p = a; p - a < n; p++) {
        s = s + *p * 1.0 / n;
    }
    return s;
}

double variance(int *a, int n) {
    double s, s1 = 0.0, s2 = 0.0;
    for (int *p = a; p - a < n; p++) {
        s1 = s1 + *p * *p * 1.0 / n;
        s2 = s2 + *p * 1.0 / n;
    }
    s = s1 - (s2 * s2);
    return s;
}

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
    printf("%d %d %.6lf %.6lf\n", max_v, min_v, mean_v, variance_v);
}
