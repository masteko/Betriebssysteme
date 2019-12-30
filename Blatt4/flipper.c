#include <stdio.h>

void convert(char *arr) {
  while(*arr != '\0') {
    char c = *arr;

    if (c >= 'A' && c <= 'Z') {
      c += 32;
    } else if(c >= 'a' && c <= 'z') {
      c -= 32;
    }

    *arr = c;

    arr++;
  }
}

int main(void) {
  char input[255];
  scanf("%s", input);
  convert(input);
  printf("Result: %s\n", input);
}