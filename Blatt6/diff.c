#include <stdio.h>
#include <string.h>

int countDiffs(char* s1, char* s2) {
  int len1 = strlen(s1);
  int len2 = strlen(s2);
  int result = 0;

  if (len1 != len2) return -1;

  for (int i = 0; i < len1; i++) {
    if (s1[i] != s2[i]) result++;
  }

  return result;
}

int main(void) {
  char* s1 = "World";
  char* s2 = "workd";

  printf("%s %s => %d\n", s1, s2, countDiffs(s1, s2));

  char* s3 = "Hello";
  char* s4 = "Hello";

  printf("%s %s => %d\n", s3, s4, countDiffs(s3, s4));
  printf("%s %s => %d\n", s1, s4, countDiffs(s1, s4));

  char* s5 = "Jamaica";
  printf("%s %s => %d\n", s1, s5, countDiffs(s1, s5));


  return 0;
}