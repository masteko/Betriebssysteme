#include <stdio.h>

#define length 5

int main(void) {
  int jumps = 0;
  int a[length] = {2, 3, -1, 2, -2};
  int b[length] = {0};
  int k = 0;

  while(k < length && k >= 0 && jumps <= length) {
    if (b[k] != 0) {
      jumps = -1;
      break;
    }

    b[k] = 1;
    k += a[k];
    jumps++;
  }

  printf("%d\n", jumps);
}