#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
  int n, data[NMAX];
  if (!input(data, &n)) {
    return 0;
  }
  squaring(data, n);
  output(data, n);
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
  printf("%d", *(a + n - 1));
}

void squaring(int *a, int n) {
  for (int *p = a; p - a < n; p++) {
    *p *= *p;
  }
}
