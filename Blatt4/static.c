#include <stdio.h>

int overflow(int n) {
  static int s = 0;
  int result = (s+n) / 10;
  s= (s + n) % 10;
  return result;
}


int main(void) {
  printf("%d\n", overflow(5));
  printf("%d\n", overflow(6));
  printf("%d\n", overflow(12));
  printf("%d\n", overflow(7));
  printf("%d\n", overflow(2));
}