#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length, int *shift);
void output(int *buffer, int length);
void move_array(int *buffer, int length, int shift, int *numbers);

int main() {
  int size, shift, data[NMAX], new_data[NMAX];
  if (!input(data, &size, &shift)) {
    printf("n/a");
    return 0;
  }
  move_array(data, size, shift, new_data);
  output(new_data, size);

  return 0;
}

void move_array(int *buffer, int length, int shift, int *numbers) {
  int temp[NMAX];

  if (shift >= 0) {
    for (int i = 0; i < shift; i++) {
      temp[i] = buffer[shift - 1 - i];
    }
    int s = length - 1;
    for (int i = shift; i < length; i++) {
      temp[i] = buffer[s];
      s--;
    }
  } else {
    int s = length - 1;
    shift = shift * -1;
    for (int i = length - shift; i < length; i++) {
      temp[i] = buffer[s];
      s--;
    }
    for (int i = 0; i < length - shift; i++) {
      temp[i] = buffer[length - shift - 1 - i];
    }
  }
  int c = 0;
  for (int i = length - 1; i >= 0; i--) {
    numbers[c] = temp[i];
    c++;
  }
}

int input(int *buffer, int *length, int *shift) {
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
  if (scanf("%d%c", shift, &c) != 2 || c != '\n') {
    return 0;
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
