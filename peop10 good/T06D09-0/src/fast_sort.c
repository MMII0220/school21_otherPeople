#include <stdio.h>
#define NMAX 10

int input(int *array, int size);
void quick_sort(int *numbers, int left, int right);
void output(int *array, int size);
void sift_down(int *array, int root, int bottom);
void heap_sort(int *array, int array_size);
void cp_array(int *array1, int *array2, int size);

int main() {
  int data[NMAX], data2[NMAX];
  if (!input(data, NMAX)) {
    printf("n/a");
    return 0;
  }
  cp_array(data, data2, NMAX);

  quick_sort(data, 0, NMAX - 1);
  output(data, NMAX);
  printf("\n");

  heap_sort(data2, NMAX);
  output(data2, NMAX);

  return 0;
}

void cp_array(int *array, int *array2, int size) {
  for (int i = 0; i < size; i++) {
    array2[i] = array[i];
  }
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

void sift_down(int *array, int root, int bottom) {
  int max_child;
  int done = 0;

  while ((root * 2 <= bottom) && (!done)) {
    if (root * 2 == bottom)
      max_child = root * 2;
    else if (array[root * 2] > array[root * 2 + 1])
      max_child = root * 2;
    else
      max_child = root * 2 + 1;
    if (array[root] < array[max_child]) {
      int temp = array[root];
      array[root] = array[max_child];
      array[max_child] = temp;
      root = max_child;
    } else {
      done = 1;
    }
  }
}

void heap_sort(int *array, int array_size) {
  for (int i = (array_size / 2); i >= 0; i--)
    sift_down(array, i, array_size - 1);

  for (int i = array_size - 1; i >= 1; i--) {
    int temp = array[0];
    array[0] = array[i];
    array[i] = temp;
    sift_down(array, 0, i - 1);
  }
}
