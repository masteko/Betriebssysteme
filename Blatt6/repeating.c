#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* repeating(char* text) {
  int len = strlen(text);
  int amount = 1;
  int size = (len/2) + 1;
  char* result = malloc(sizeof(char) * size);
  result[(size-1)] = '\0';
  result[0] = text[0];
  int counter = 0;
  int idx = 1;

  while(amount <= (len - idx)) {
    counter = 0;
    for (int i = idx; i <= (len-amount); i+=amount) {
      for (int j = 0; j < amount; j++) {
        if (result[j] == text[i+j]) {
          counter++;
        }
      }
    }
    if (counter >= amount) {
      result[amount] = text[idx];
      idx++;
      amount++;
    } else {
      if (amount == 1) {
        result[0] = text[idx];
        idx++;
      } else {
        result[amount-1] = '\0';
        return result;
      }
    }
  }

  result[amount] = '\0';
  return result;
}

int main(void) {
  // char* s3 = "12ab34ab";
  // char* s1 = "tzababab";
  char* s2 = "12312367";

  // char* r1 = repeating(s3);
  // char* r2 = repeating(s1);
  char* r3 = repeating(s2);

  // printf("%s -> %s\n", s3, r1);
  // printf("%s -> %s\n", s1, r2);
  printf("%s -> %s\n", s2, r3);
  
  // free(r1);
  // free(r2);
  free(r3);

  return 0;
}