#include <math.h>
#include <stdio.h>

#define NMAX 30
#define EPS 1e-6

int input(int *a, int *n);
void output(int n);
int find(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
int sigma_comparison(int val, int *a, int n);
int mean_comparison(int val, int *a, int n);

int main() {
  int n, data[NMAX];
  if (!input(data, &n)) {
    return 0;
  }
  output(find(data, n));
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

void output(int n) { printf("%d", n); }

int find(int *a, int n) {
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0 && a[i] != 0 && mean_comparison(a[i], a, n) &&
        sigma_comparison(a[i], a, n))
      return a[i];
  }
  return 0;
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

int sigma_comparison(int val, int *a, int n) {
  double s = mean(a, n) + 3 * sqrt(variance(a, n));
  if (fabs(val - s) <= EPS || val - EPS < s)
    return 1;
  else
    return 0;
}

int mean_comparison(int val, int *a, int n) {
  val *= 1.0;
  double m = mean(a, n);
  if (fabs(val - m) <= EPS || val + EPS > m)
    return 1;
  else
    return 0;
}
