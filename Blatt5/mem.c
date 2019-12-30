#include <stdio.h>
#include <stdlib.h>

int incrementSize = 5;

int main(void) {
  int size = 5;
  int* arr = calloc(size, sizeof(int));
  int input;
  int count = 0;
  int sum = 0;

  do {
    printf("Gib eine Zahl ein:\n");
    scanf("%d", &input);

    if (count >= size) {
      size += incrementSize;
      arr = realloc(arr, size * sizeof(int));
    }

    if (input > 0) {
      arr[count] = input;
      sum += input;
      count++;
    }
  } while (input != -1);

  double mean = sum / count;
  printf("Der Mittelwert lautet %.2f\n", mean);
  free(arr);
}