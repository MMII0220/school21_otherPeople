
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
  if (!input(data, &n)) {
    return 0;
  }
  output(data, n);
  output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

  return 0;
}

int input(int *a, int *n) {
  char end;
  int input_n = scanf("%d%c", n, &end);
  if (input_n != 2 || (end != '\n' && end != ' ' && end != '\0') || *n <= 0 ||
      *n > NMAX) {
    printf("n/a");
    return 0;
  }
  for (int *p = a; p - a < *n; p++) {
    int input_arr = scanf("%d%c", p, &end);
    if (input_arr != 2 ||
        (end != '\n' && end != ' ' && end != '\0' && end != EOF)) {
      printf("n/a");
      return 0;
    }
  }
  return 1;
}

void output(int *a, int n) {
  for (int *p = a; p - a < n - 1; p++) {
    printf("%d ", *p);
  }
  printf("%d\n", *(a + n - 1));
}

int max(int *a, int n) {
  int max = a[0];
  for (int *p = a + 1; p - a < n; p++) {
    if (*p > *(p - 1))
      max = *p;
  }
  return max;
}

int min(int *a, int n) {
  int min = a[0];
  for (int *p = a + 1; p - a < n; p++) {
    if (*p < *(p - 1))
      min = *p;
  }
  return min;
}

double mean(int *a, int n) {
  double res = 0.0;
  for (int i = 0; i < n; i++)
    res += a[i];
  return res / n;
}

double variance(int *a, int n) {
  double res = 0.0;
  double mean_v = mean(a, n);
  for (int i = 0; i < n; i++)
    res += (a[i] - mean_v) * (a[i] - mean_v);
  return res / n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
  printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
