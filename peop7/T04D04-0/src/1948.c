#include <stdio.h>
#include <stdlib.h>

int is_prime(int x) {
  int prod;
  for (int i1 = 2; i1 < x; i1++) {
    for (int i2 = 2; i2 < x; i2++) {
      prod = i1 * i2;
      if (prod > x)
        break;
      if (prod == x)
        return 0;
    }
  }

  return 1;
}
int is_divisor(int input_value, int divisor) {
  do {
    input_value -= divisor;
  } while (input_value > 0);
  if (input_value == 0)
    return 1;
  else
    return 0;
}
int main() {
  int number;
  int maxim = 1;
  scanf("%d", &number);
  number = abs(number);
  for (int i = 2; i < number / 2 + 1; i++) {
    if (is_prime(i) == 1 && is_divisor(number, i)) {
      maxim = i;
    }
  }
  printf("%d", maxim);
}
