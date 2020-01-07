#include <stdio.h>

// void rotateLeft(char* text) {
//   int len = 0;
//   while (text[len++] != '\0');
//   --len;

//   for (int i = 0; i < len / 2; i++) {
//     char tmp = text[i];
//     int idx = len - i - 1;
//     char tmp2 = text[idx];
//     text[i] = tmp2;
//     text[idx] = tmp;
//   }
// }

void rotateLeft(char* text) {
  int len = 0;
  while (text[len++] != '\0');
  --len;

  char test[len + 1];

  for (int i = 0; i < len; i++) {
    char tmp = text[i];
    int idx = len - i - 1;
    test[i] = text[idx];
  }
  test[len] = '\0';
  printf("%s\n", test);
}

int main(void) {
  char* string = "Hallos";
  rotateLeft(string);
  // printf("%s\n", string);
}