/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
  int size, data[NMAX], new_data[NMAX];
  if (!input(data, &size)) {
    printf("n/a");
    return 0;
  }
  int sum = sum_numbers(data, size);
  if (sum == 0) {
    printf("n/a");
  } else {
    printf("%d\n", sum);
  }
  int size_nd = find_numbers(data, size, sum, new_data);
  output(new_data, size_nd);

  return 0;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
  int sum = 0;

  for (int i = 0; i < length; i++) {
    if (buffer[i] % 2 == 0) {
      sum = sum + buffer[i];
    }
  }

  return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
  int size = 0;
  int *position = numbers;
  for (int i = 0; i < length; i++) {
    if (buffer[i] != 0 && number % buffer[i] == 0) {
      size++;
      *position = buffer[i];
      position++;
    }
  }
  return size;
}

int input(int *buffer, int *length) {
  char c;
  if (scanf("%d%c", length, &c) != 2 || c != '\n' || *length > NMAX) {
    return 0;
  }
  for (int *position = buffer; (position - buffer) < *length; position++) {
    if (position - buffer == *length - 1) {
      if (scanf("%d%c", position, &c) != 2 || c != '\n') {
        return 0;
      }
    } else {
      if (scanf("%d%c", position, &c) != 2 || c != ' ') {
        return 0;
      }
    }
  }
  return 1;
}

void output(int *buffer, int length) {
  for (int *position = buffer; (position - buffer) < length; position++) {
    printf("%d", *position);
    if ((position - buffer) != (length - 1)) {
      printf(" ");
    }
  }
}
