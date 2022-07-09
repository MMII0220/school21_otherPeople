#include <math.h>
#include <stdio.h>

double an(double x);
double ber(double x);
double gi(double x);

int main(void) {
  double pi1 = -3.14159265358979323846;
  double pi2 = pi1;
  double step = (-pi1 * 2) / 41;
  int i = 0;
  while (i < 42) {
    i++;
    printf("%.7lf | %.7lf |", pi2, an(pi2));
    if (ber(pi2) == -1) {
      printf(" - | ");
    } else {
      printf("%.7lf | ", ber(pi2));
    }
    if (gi(pi2) == -1) {
      printf(" - ");
    } else {
      printf("%.7lf ", gi(pi2));
    }

    pi2 += step;
    printf("\n");
  }
}
double an(double x) { return (pow(1, 3) / (pow(1, 2) + pow(x, 2))); }
double ber(double x) {
  double a = sqrt(pow(1, 4) + 4 * (pow(x, 2) * pow(1, 2)));
  double b = -pow(x, 2) - pow(1, 2);
  if (a + b > 0) {
    return sqrt(a + b);
  } else {
    //        printf("n/a");
    return -1;
  }
}
double gi(double x) {
  if (x != 0) {
    return (1 / (pow(x, 2)));
  } else {
    //           printf("n/a");
    return -1;
  }
}
