#include <stdio.h>
#define NMAX 10

int input(int *array, int size);
void quick_sort(int *numbers, int left, int right);
void output(int *array, int size);

int main() {
  int data[NMAX];
  if (!input(data, NMAX)) {
    printf("n/a");
    return 0;
  }
  quick_sort(data, 0, NMAX - 1);
  output(data, NMAX);

  return 0;
}

int input(int *array, int size) {
  char c;
  for (int *position = array; (position - array) < size; position++) {
    if (position - array == size - 1) {
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

void output(int *array, int size) {
  for (int *position = array; (position - array) < size; position++) {
    printf("%d", *position);
    if ((position - array) != (size - 1)) {
      printf(" ");
    }
  }
}

void quick_sort(int *numbers, int left, int right) {
  int pivot;
  int l_hold = left;
  int r_hold = right;
  pivot = numbers[left];
  while (left < right) {
    while ((numbers[right] >= pivot) && (left < right))
      right--;
    if (left != right) {
      numbers[left] = numbers[right];
      left++;
    }
    while ((numbers[left] <= pivot) && (left < right))
      left++;
    if (left != right) {
      numbers[right] = numbers[left];
      right--;
    }
  }
  numbers[left] = pivot;
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot)
    quick_sort(numbers, left, pivot - 1);
  if (right > pivot)
    quick_sort(numbers, pivot + 1, right);
}
