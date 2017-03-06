//Project 1
//Zachary Shumate
//CECS 420-01

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
  char *word;
  int count;

  struct Node *next;
  struct Node *prev;
}Node;


typedef struct List {
  Node *head;
  Node *tail;
}List;


void countWords(FILE *file, List *list) {
  char word [50];

  while ((fscanf(file, "%s", word)) == 1) {
    Node *n = (Node*)malloc(sizeof(Node));
    Node *test;
    n->word = strdup(word);
    n->count = 1;

    if (list->head == NULL) {
      list->head = n;
      list->tail = n;
    }
    else {
      test = list->head;

      if (strcmp(n->word, test->word) > 0) {
        while (test != NULL) {
          if (strcmp(n->word, test->word) == 0) {
            test->count++;
            free(n);
            break;
          }
          else if (strcmp(n->word, test->word) < 0) {
            test->prev->next = n;
            n->prev = test->prev;
            test->prev = n;
            n->next = test;
            break;
          }
          else if (test->next == NULL) {
            test->next = n;
            n->prev = test;
            list->tail = n;
            break;
          }
          test = test->next;
        }
      }
      else if (strcmp(n->word, test->word) == 0){
        test->count++;
        free(n);
      }
      else if (strcmp(n->word, test->word) < 0) {
        test->prev = n;
        n->next = test;
        list->head = n;
      }
    }
  }
}


void compare (int occurence, List *l1, List *l2, List *combList) {
  Node *comp = l1->head;


  while(comp != NULL) {
    if (comp->count >= occurence) {
      Node *test = l2->head;

      while(test != NULL) {
        if (!strcmp(test->word, comp->word)) {
          if (test->count >= occurence) {
            Node *n = (Node*)malloc(sizeof(n));
            n->word = comp->word;
            n->count = (comp->count + test->count);

            if (combList->head == NULL) {
              combList->head = n;
              combList->tail = n;
            }
            else {
              combList->tail->next = n;
              n->prev = combList->tail;
              combList->tail = n;
            }
          }
        }
        test = test->next;
      }
    }
    comp = comp->next;
  }
}


void saveList (FILE *file, List *list) {
  Node *n = list->head;
  while(n != NULL) {
    fprintf(file, "%s,%d\n", n->word, n->count);
    n = n->next;
  }
}


void clearList (List *list){
  Node *n;
  Node *tmp;
  n = list->head;
  while (n != list->tail) {
    tmp = n->next;
    free(n->word);
    free(n);
    n = tmp;
  }
  free(tmp);
  free(list);
}


int main(int argc, char const *argv[]) {
  List *list1 = (List*)malloc(sizeof(list1));
  List *list2 = (List*)malloc(sizeof(list2));
  List *finalList = (List*)malloc(sizeof(finalList));
  FILE *f1 = fopen(argv[1], "r");
  FILE *f2 = fopen(argv[2], "r");
  FILE *output = fopen(argv[4], "w");

  if (f1 == NULL) {
    printf("First file not found");
    return 0;
  }
  if (f2 == NULL) {
    printf("Second file not found");
    return 0;
  }

  countWords(f1, list1);
  countWords(f2, list2);

  compare(atoi(argv[3]), list1, list2, finalList);
  saveList(output, finalList);

  clearList(list1);
  clearList(list2);
  fclose(f1);
  fclose(f2);
  return 0;
}
