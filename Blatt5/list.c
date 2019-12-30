#include <stdio.h>
#include <stdlib.h>

typedef struct element {
  int value;
  struct element *next;
} Element;

typedef struct {
  Element *head;
} List;

void insert(List *list, int value) {
  Element *new = (Element*)malloc(sizeof(Element));
  new->value = value;
  new->next = list->head;
  list->head = new;
}

void addElement(Element *prev, Element *curr, Element* new) {
  if(NULL == curr) {
    prev->next = new;
    return;
  }
  if (curr->value < new->value) {
      addElement(curr, curr->next, new);
  } else {
    prev->next = new;
    new->next = curr;
  }
}

Element* add(List *list, int value) {
  Element *new = (Element*)malloc(sizeof(Element));
  new->value = value;
  Element* current = list->head;

  if (NULL == current) {
    list->head = new;
  } else  {
    if (current->value > value) {
      new->next = current;
      list->head = new;
    } else {
      addElement(current, current->next, new);
    }
  }

  return new;
}

int listSize(const List *list) {
  int result = 0;
  Element *current = list->head;

  while(NULL != current) {
    result++;
    current = current->next;
  }
  return result;
}

int contains(const List *list, int value) {
  Element *current = list->head;

  while(NULL != current) {
    if (current->value == value) {
      return 1;
    }
    current = current->next;
  }

  return 0;
}

void freeElements(Element* el) {
  if(NULL != el) {
    freeElements(el->next);
  }
  free(el);
}

void freeList(List *list) {
  freeElements(list->head);
  free(list);
}

void printList(List *list) {
  Element* current = list->head;
  printf("Liste: ");
  while(NULL != current) {
    printf("%d, ", current->value);
    current = current->next;
  }
  printf("\b\b  \n");
}

int main(void) {
  List *list = (List*)malloc(sizeof(List));
  int s0 = listSize(list);
  printf("size: %d\n", s0);
  insert(list, 4);
  int c1 = contains(list, 3);
  int c2 = contains(list, 4);
  printf("contains 4: %d\n", c2);
  int s1 = listSize(list);
  printf("size: %d\n", s1);
  add(list, 3);
  add(list, 1);
  add(list, 1);
  add(list, 10);
  add(list, 5);
  add(list, 5);
  add(list, 1);
  add(list, 10);
  int s2 = listSize(list);
  printf("size: %d\n", s2);

  printList(list);
  freeList(list);
}