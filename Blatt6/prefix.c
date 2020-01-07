#include <stdio.h>

char* repeat(char* text) {
  int len = strlen(text);
  int newSize = (len * len + len) / 2 + 1;
  char* result = malloc(sizeof(char) * newSize);
  int idx = 0;

  for (int i = 0; i < len; i++) {
    for(int j = 0; j <= i; j++) {
      result[idx++] = text[j];
    }
  }
  result[idx] = 0;
  return result;
}

int main(void) {
  char* string = "System";
  char* result = repeat(string);

  printf("%s\n", result);
  free(result);
}