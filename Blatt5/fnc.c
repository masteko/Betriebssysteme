#include <stdio.h>

void printString(char* c) {
  printf("%s\n",c);
}

void printStringLength(char* c) {
  int len = 0;

  while(*c != '\0') {
    c++;
    len++;
  }

  printf("%d\n", len);
}

int testPattern(char* source, void(*fun)(char*)) {

}

int main(void) {
 char* test = "teststring";
 printString(test);
 printStringLength(test);
 printString(test);
}