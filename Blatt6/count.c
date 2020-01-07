#include <stdio.h>

int countLetter(char* text, char letter) {
  int count = 0;
  while (*text != '\0') {
    if (text++[0] == letter) count++;
  }
  return count;
}

int main(void) {
  printf("%d hello, l\n", countLetter("hello", 'l'));
  printf("%d Hello, h\n", countLetter("Hello", 'h'));
}