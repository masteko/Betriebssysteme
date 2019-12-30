#include <stdio.h>
#include <stdlib.h>

int fib(int number) {
	if (number < 2) {
		return number;
	} else {
		return fib(number-2) + fib(--number);
	}
}

int fib2(int number) {
  int number1 = 0;
  int number2 = 1;
  int tmp;

  if (number < 2) {
    return number;
  } else {
    while(number > 1) {
      tmp = number1;
      number1 = number2;
      number2 += tmp;
      number--;
    }
  }

  return number2;
}

int main(int argc, char * argv[]) {
	int input;
	int number, number2;

  if (argc <= 1) {
    printf("Es wurden keine Argumente übergeben\n");
    return 1;
  }

	number = fib(atoi(argv[1]));
  number2 = fib2(atoi(argv[1]));
	printf("Die Zahl lautet: %d \n", number);
	printf("Die Zahl lautet: %d \n", number2);

	return 0;
}