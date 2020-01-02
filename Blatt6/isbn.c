#include <stdio.h>
#include <stdlib.h>

// ./isbn 1234567890 3680087837

int checkIsbn(char* c) {
  int sum = 0;
  int idx = 10;
  char* curr = c;
  while('\0' != *curr) {
    sum += (*curr++ - 48) * idx--;
  }

  return sum % 11;
}

int main(int argc, char** argv) {
  for (int i = 1; i < argc; i++) {
    int valid = checkIsbn(argv[i]);

    if (valid == 0) {
      printf("ISBN %s ist gültig\n",argv[i]);
    } else {
      printf("ISBN %s ist ungueltig\n", argv[i]);
    }
  }
  return 0;
}