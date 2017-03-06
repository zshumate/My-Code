//Project 2
//Zachary Shumate
//CECS 420-01

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Node {
  int id, arrival, burst, priority, finish, wait, progress;

  struct Node *next;
  struct Node *prev;
}Node;


typedef struct List {
  Node *head;
  Node *tail;
}List;


void removeNode(List *list, Node *n) {
  if ((list->head == n) && (list->tail == n)) {
    list->head = NULL;
    list->tail = NULL;
    free(n);
  }
  else if (list->head == n) {
    list->head = n->next;
    n->next->prev = NULL;
    free(n);
  }
  else if (list->tail == n) {
    list->tail = n->prev;
    n->prev->next = NULL;
    free(n);
  }
  else {
    n->prev->next = n->next;
    n->next->prev = n->prev;
    free(n);
  }
}


void insertNode(List *list, Node *n) {
  if (list->head == NULL) {
    list->head = n;
    list->tail = n;
  }
  else {
    list->tail->next = n;
    n->prev = list->tail;
    list->tail = n;
  }
}


void NPP(FILE *out, List *processes) {
  List *arrive = (List*)malloc(sizeof(arrive));
  Node *p = processes->head;
  Node *current = p;
  Node *test;
  int t = 0;

  insertNode(arrive, p);
  processes->head = processes->head->next;
  p->next = NULL;
  p->prev = NULL;
  p = processes->head;

  while(arrive->head != NULL) {
    while (1) {
      if (p != NULL) {
        if (p->arrival == t) {
          insertNode(arrive, p);
          processes->head = processes->head->next;
          p->next = NULL;
          p = processes->head;
        }
        else {
          break;
        }
      }
      else {
        break;
      }
    }
    if (current->progress == current->burst) {
      current->finish = t;
      current->wait = (current->finish - (current->burst + current->arrival));
      fprintf(out, "%d %d %d %d\n", current->id, current->arrival, current->finish, current->wait);
      removeNode(arrive, current);
      current = arrive->head;
      test = arrive->head;
      while (test != NULL) {
        if (test->priority < current->priority) {
          current = test;
        }
        test = test->next;
      }
    }
    if (current != NULL) {
      current->progress++;
      t++;
    }
  }
  free(arrive);
}


void PP(FILE *out, List *processes) {
  List *arrive = (List*)malloc(sizeof(arrive));
  Node *p = processes->head;
  Node *current = p;
  Node *test;
  int t = 0;

  insertNode(arrive, p);
  processes->head = processes->head->next;
  p->next = NULL;
  p->prev = NULL;
  p = processes->head;

  while(arrive->head != NULL) {
    while (1) {
      if (p != NULL) {
        if (p->arrival == t) {
          insertNode(arrive, p);
          processes->head = processes->head->next;
          p->next = NULL;
          p = processes->head;
        }
        else {
          break;
        }
      }
      else {
        break;
      }
    }
    if (current->progress == current->burst) {
      current->finish = t;
      current->wait = (current->finish - (current->burst + current->arrival));
      fprintf(out, "%d %d %d %d\n", current->id, current->arrival, current->finish, current->wait);
      removeNode(arrive, current);
    }
    current = arrive->head;
    test = arrive->head;
    while (test != NULL) {
      if (test->priority < current->priority) {
        current = test;
      }
      test = test->next;
    }
    if (current != NULL) {
      current->progress++;
      t++;
    }
  }
  free(arrive);
}


void load(FILE *file, List *list, int limit) {
  int id = -1, arrival = -1, burst = -1, priority = -1;
  while (((fscanf(file, "%d %d %d %d", &id, &arrival, &burst, &priority)) == 4) && (limit != 0)) {
    Node *n = (Node*)malloc(sizeof(Node));
    Node *test;
    n->id = id;
    n->arrival = arrival;
    n->burst = burst;
    n->priority = priority;

    if (list->head == NULL) {
      list->head = n;
      list->tail = n;
    }
    else {
      test = list->head;
      while (test != NULL) {
        if (test->next == NULL) {
          test->next = n;
          n->prev = test;
          list->tail = n;
          break;
        }
        test = test->next;
      }
    }
    limit--;
  }
}


int main(int argc, char const *argv[]) {
  List *processes = (List*)malloc(sizeof(processes));
  FILE *file = fopen(argv[1], "r");
  FILE *output = fopen(argv[2], "w");
  int limit = -1;

  if ((argc == 5)) {
    limit = atoi(argv[4]);
  }
  load(file, processes, limit);

  if (strcmp(argv[3], "NPP") == 0) {
    NPP(output, processes);
  }
  else if (strcmp(argv[3], "PP") == 0) {
    PP(output, processes);
  }

  free(processes);
  fclose(file);
  fclose(output);
  return 0;
}
