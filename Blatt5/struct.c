#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int dividend;
  int divisor;
} Fraction;

int ggt(int a, int b) {
  while(b != 0) {
    int h = a % b;
    a = b;
    b = h;
  }
  return a;
}

void reduce(Fraction *f) {
  int divisor = ggt(f->dividend, f->divisor);
  f->dividend /= divisor;
  f->divisor /= divisor;
}

void readFraction(Fraction *fraction) {
  printf("Geben Sie die Daten für den Ersten Bruch ein:\n");
  scanf("%d %d", &fraction->dividend, &fraction->divisor);

  reduce(fraction);
}

void printingData(Fraction *fraction) {
  printf("Bruch lautet: %d/%d\n", fraction->dividend, fraction->divisor);
}

Fraction* multiplyFractions(Fraction *first, Fraction *second) {
  Fraction *result = malloc(sizeof(Fraction));
  result->dividend = first->dividend * second->dividend;
  result->divisor = first->divisor * second->divisor;

  reduce(result);

  return result;
}

Fraction* addFractions(Fraction *first, Fraction *second) {
  Fraction *result = malloc(sizeof(Fraction));

  result->dividend = first->dividend * second->divisor + second->dividend * first->divisor;
  result->divisor = first->divisor * second->divisor;

  reduce(result);

  return result;
}

int compareFractions(Fraction *first, Fraction *second) {
  return (first->dividend == second->dividend && first->divisor == second->divisor);
}

int main(void) {
  Fraction f1;
  Fraction f2;

  readFraction(&f1);
  readFraction(&f2);

  Fraction* f4 = multiplyFractions(&f1, &f2);
  Fraction* f5 = addFractions(&f1, &f2);

  printingData(&f1);
  printingData(&f2);
  printingData(f4);
  printingData(f5);

  free(f4);
  free(f5);
}