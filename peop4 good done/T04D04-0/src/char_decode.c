#include <math.h>
#include <stdio.h>

int decoder();
int encoder();
void error_input();

int main(int argc, char *argv[]) {
  if ((argc == 2) && (argv[1][0] == '0')) {
    encoder();
  } else if ((argc == 2) && (argv[1][0] == '1')) {
    decoder();
  } else {
    printf("n/a");
  }
}

int encoder() {
  char letter;
  char end;
  while (1) {
    scanf("%c%c", &letter, &end);
    // printf("%c", end);
    if (end == '\n') {
      printf("%X", letter);
      return 0;
      // break;
    } else if (end != ' ') {
      error_input();
      return 0;
    }

    printf("%X ", letter);
  }
}

int decoder() {
  int number;
  char symbol;
  while (1) {
    scanf("%X%c", &number, &symbol);
    if ((number >= 0) && (number <= 126)) {
      if (symbol == '\n') {
        printf("%c", number);
        return 0;
      } else if (symbol != ' ') {
        printf("n/a");
        return 0;
      }
      printf("%c ", number);
    } else {
      // printf("n/a\n");
      error_input();
      return 0;
    }
  }
}

void error_input() {
  fflush(stdout);
  printf("\rn/a");
}
