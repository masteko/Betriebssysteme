#include <stdio.h>

int getLen(char* a) {
 int size = 0;
 while(a[size++] != '\0') { } 
 return size;
}

void copyString(char* a, char* b) {
  int idx = 0;
  while(a[idx] != '\0') {
    b[idx] = a[idx];
    idx++;
  }
  b[idx] = '\0';
}

int isPermutation(char *a, char *b) {
  int size1 = getLen(a);
  int size2 = getLen(b);

  if (size1 != size2) return 1;

  char arr[size1];
  copyString(b, arr);

  int result;

  for(int i = 0; i < size1; i++) {
    result = 1;
    for(int j = 0; j < size1; j++) {
      if (a[i] == arr[j]) {
        result = 0;
        arr[j] = '\0';
        break;
      }
    }
    if (result == 1) return 1;
  }
  return 0;
}

int main(void) {
  int v1 = isPermutation("lol", "oll");
  int v2 = isPermutation("hello", "lehho");

  printf("1. %s Ok,\n2. %s Ok\n", v1 == 1 ? "NOT" : "", v2 == 1 ? "NOT": "");
}