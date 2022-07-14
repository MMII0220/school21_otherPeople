#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
  int n, data[NMAX];
  if (input(data, &n) != -1) {
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
  } else {
    printf("n/a");
  }
  return 0;
}

int input(int *a, int *n) {
  if (scanf("%d", n) == 1 && *n > 0 && *n <= NMAX) {
    for (int *p = a; p - a < *n; p++) {
      if (scanf("%d", p) != 1) {
        return -1;
      }
    }
  } else {
    return -1;
  }
  return 0;
}

void output(int *a, int n) {
  for (int *p = a; p - a < n; p++) {
    printf("%d ", *p);
  }
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
  printf("\n%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}

int max(int *a, int n) {
  int max_v = a[0];
  for (int *p = a; p - a < n; p++) {
    if (*p > max_v) {
      max_v = *p;
    }
  }
  return max_v;
}

int min(int *a, int n) {
  int min_v = a[0];
  for (int *p = a; p - a < n; p++) {
    if (*p < min_v) {
      min_v = *p;
    }
  }
  return min_v;
}

double mean(int *a, int n) {
  double mean_v = 0;
  for (int *p = a; p - a < n; p++) {
    mean_v += (double)*p / (double)n;
  }
  return mean_v;
}

double variance(int *a, int n) {
  double variance_v = 0;
  double variance_1st = 0;
  double variance_2nd = 0;
  for (int *p = a; p - a < n; p++) {
    variance_1st += ((double)*p * (double)*p) / (double)n;
    variance_2nd += (double)*p / n;
  }
  variance_v = variance_1st - variance_2nd * variance_2nd;

  return variance_v;
}