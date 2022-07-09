#include <math.h>
#include <stdio.h>

double agnesi(double num);
double bernoulli(double num);
double hyperbola(double num);

int main() {
  double pi = 3.14159265358979323846;
  double interval = (double)(2 * pi) / 41;
  double arg = -pi;
  while (arg <= pi) {
    if (bernoulli(arg) == -1) {
      printf("%.7lf | %.7lf | - | %.7lf\n", arg, agnesi(arg), hyperbola(arg));
    } else {
      printf("%.7lf | %.7lf | %.7lf | %.7lf\n", arg, agnesi(arg),
             bernoulli(arg), hyperbola(arg));
    }
    arg = arg + interval;
  }
}

double agnesi(double num) { return pow((1 + pow(num, 2)), -1); }
double bernoulli(double num) {
  double sqrt1 = sqrt(1 + 4 * pow(num, 2));
  double diff = pow(num, 2) + 1;
  if (sqrt1 >= diff) {
    return sqrt(sqrt1 - pow(num, 2) - 1);
  } else {
    return -1;
  }
}
double hyperbola(double num) {
  if (num != 0) {
    return pow(num * num, -1);
  } else {
    return -1;
  }
}
