#include <math.h>
#include <stdio.h>

int dev(int a, int b);
int rem(int a, int x);
int easy(int a);

int main(void) {
  float n;
  char c = '\n';
  if (scanf("%f%c", &n, &c) == 2 && c == '\n') {
    if (n == (int)n) {
      if (n < 0) {
        n = -n;
      }
      int max = 1;
      for (int i = 1; i <= n; ++i) {
        if (rem(n, i) == 0 && easy(i) == 1) {
          max = i;
        }
      }
      printf("%d", max);
    } else {
      printf("n/a");
    }
  } else {
    printf("n/a");
  }
  return 0;
}
int dev(int a, int b) {
  int divide = 0;
  while (a > 0) {
    a -= b;
    if (a < 0) {
      break;
    }
    divide++;
  }
  return divide;
}
int easy(int a) {
  //  int devide = dev(a, b);
  if (a == 0 || a == 1) {
    return 1;
  }
  for (int i = 2; i < a; i++) {
    if (rem(a, i) == 0) {
      return 0;
    }
  }
  return 1;
}

int rem(int a, int b) {
  int devide = dev(a, b);
  int rem = a - (b * devide);

  return rem;
}
