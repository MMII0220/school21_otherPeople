#include <stdio.h>

int decode() {
  char in;
  int value = 0;
  int count = 0;
  scanf("%c", &in);

  while (in != '\n') {
    if (in != ' ') {
      if (count == 2)
        return -1;
      if (in >= '0' && in <= '9') {
        value *= 16;
        value += (in - '0');
      } else if (in >= 'A' && in <= 'F') {
        value *= 16;
        value += 10 + (in - 'A');
      }
      count++;
    } else {
      if (count == 2) {
        printf("%c ", value);
        count = 0;
        value = 0;
      } else {
        return -1;
      }
    }
    scanf("%c", &in);
  }

  if (count == 2) {
    printf("%c", value);
    return 0;
  } else {
    return -1;
  }
}

int encode() {
  char in;
  char prev_char = ' ';
  scanf("%c", &in);

  while (in != '\n') {
    if (in == ' ') {
      if (prev_char != ' ') {
        printf("%X ", prev_char);
      } else {
        return -1;
      }
    } else {
      if (prev_char != ' ')
        return -1;
    }
    prev_char = in;
    scanf("%c", &in);
  }
  return 0;
}

int encode_decode(int argc, const char *argv[]) {
  if (argc != 2)
    return -1;

  char mode = argv[1][0];
  if (mode == '1') {
    return decode();
  } else if (mode == '0') {
    return encode();
  } else {
    return 0;
  }
}

int main(int argc, const char *argv[]) {
  if (encode_decode(argc, argv))
    printf("n/a");
}
