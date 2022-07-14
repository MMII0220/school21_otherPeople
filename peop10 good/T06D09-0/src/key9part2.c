#include <stdio.h>

#define LEN 100

void sum(int *array1, int size1, int *array2, int size2, int *result,
         int *res_size);
int sub(int *array1, int size1, int *array2, int size2, int *result,
        int *res_size);
int input(int *num, int *len);
void output(int *num, int len);

int main() {
  int flag = 1;
  int num1[LEN], num2[LEN], rez[LEN], size1, size2, res_size;
  flag = input(num1, &size1);
  if (flag == 1) {
    flag = input(num2, &size2);
    if (flag == 1) {
      sum(num1, size1, num2, size2, rez, &res_size);
      output(rez, res_size);
      printf("\n");
      flag = sub(num1, size1, num2, size2, rez, &res_size);
      if (flag == 1) {
        output(rez, res_size);
      }
    }
  }
  if (flag == 0) {
    printf("n/a");
  }
  return flag;
}

int input(int *num, int *len) {
  int flag = 1;
  char c = ' ';
  int a;
  *len = -1;
  while (1) {
    if (flag == 0)
      break;
    scanf("%c", &c);
    if (c == '\n')
      break;
    if (c == ' ')
      continue;
    a = c - '0';
    if (a < 0 || a > 9)
      flag = 0;
    (*len)++;
    if (*len >= LEN)
      flag = 0;
    num[*len] = a;
  }
  return flag;
}

void output(int *num, int len) {
  int flag = 1, outlfag = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (num[i] == 0 && flag == 1) {
      continue;
    }
    if (num[i] != 0)
      flag = 0;
    printf("%d", num[i]);
    outlfag = 1;
    if (i != 0)
      printf(" ");
  }
  if (outlfag == 0) {
    printf("0");
  }
}

void sum(int *array1, int size1, int *array2, int size2, int *result,
         int *res_size) {
  int flag = 0;
  *res_size = 0;
  int i, j;
  for (i = size1, j = size2; i >= 0 && j >= 0; i--, j--) {
    if (flag == 0)
      result[*res_size] = array1[i] + array2[j];
    if (flag == 1) {
      flag = 0;
      result[*res_size] += array1[i] + array2[j];
    }
    if (result[*res_size] > 9) {
      flag = 1;
      result[*res_size + 1] = result[*res_size] / 10;
      result[*res_size] %= 10;
    }
    (*res_size)++;
  }
  if (i < 0) {
    for (int k = j; k >= 0; k--) {
      result[(*res_size)++] = array2[k];
    }
  }
  if (j < 0) {
    for (int k = i; k >= 0; k--) {
      result[(*res_size)++] = array1[k];
    }
  }
}

int sub(int *array1, int size1, int *array2, int size2, int *result,
        int *res_size) {
  int flag = 0, outflag = 1;
  *res_size = 0;
  int i, j;

  for (i = size1, j = size2; i >= 0 && j >= 0; i--, j--) {
    if (outflag == 0)
      break;
    if (flag == 0)
      result[*res_size] = array1[i] - array2[j];
    if (flag == 1) {
      flag = 0;
      result[*res_size] += array1[i] - array2[j];
    }
    if (result[*res_size] < 0) {
      if (*res_size >= size1)
        outflag = 0;
      flag = 1;
      result[*res_size + 1] = -1;
      result[*res_size] += 10;
    }
    (*res_size)++;
  }

  if (i < 0 && i != j)
    outflag = 0;
  if (j < 0 && outflag == 1) {
    for (int k = i; k >= 0; k--) {
      if (flag == 0)
        result[(*res_size)++] = array1[k];
      if (flag == 1) {
        flag = 0;
        result[(*res_size)++] += array1[k];
      }
    }
  }
  return outflag;
}
