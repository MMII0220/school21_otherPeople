#include <stdio.h>

int find_fib(int num);

int enter_number();

int main() {
  int number = enter_number();
  if (number == -1) {
    return 0;
  }
  int fib = find_fib(number);
  printf("%d", fib);
  return 0;
}

int find_fib(int num) {
  if ((num == 0) || (num == 1)) {
    return num;
  }
  return (find_fib(num - 1) + find_fib(num - 2));
}

int enter_number() {
  int num;
  char enter;
  if ((scanf("%d%c", &num, &enter) == 2) && (enter == '\n') && (num >= 0)) {
    return num;
  } else {
    printf("n/a");
    return -1;
  }
}
