#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fibonacci(int N) {
  if (N == 1 || N == 2)
    return 1;
  return fibonacci(N - 1) + fibonacci(N - 2);
}
int main() {
  int N;
  printf("N=");
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)  // В цикле выводим N чисел Фибоначчи
    printf("%d ", fibonacci(i));
  getchar();
  getchar();
  return 0;
}
