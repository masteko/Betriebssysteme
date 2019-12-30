#include <stdio.h>
#include <stdlib.h>

int checkIsbn(char* c) {
  int sum = 0;
  int idx = 10;
  char* curr = c;
  while('\0' != *curr) {
    sum += (*curr++ - 48) * idx--;
  }

  return sum % 11;
}

int main(void) {
  char arr[11];
  printf("Geben Sie die ISBN ein: \n");
  scanf("%s", arr);

  int valid = checkIsbn(arr);

  if (valid == 0) {
    printf("ISBN %s ist gültig\n",arr);
  } else {
    printf("ISBN %s ist ungueltig\n", arr);
  }
}