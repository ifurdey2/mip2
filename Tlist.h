#ifndef TLIST_H_INCLUDED
#define TLIST_H_INCLUDED

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define FILENAME "reality.txt"

typedef struct {
  char  Category[50];
  char  Location[50];
  char  Street[100];
  int  Square;
  int  Price;
  char  Description[200];
}realty;

typedef struct Node {
    realty value;
    struct Node* next;
} node;

typedef struct List {            //2
    node* first;
    node* last;
} Tlist;

#endif // TLIST_H_INCLUDED
