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

void push_back(Tlist* l, realty val) { // ‚ÒÚ‡‚ÎˇÂÚ ˝ÎÂÏÂÌÚ ‚ ÍÓÌÂˆ 3
    node* new = malloc(sizeof(node));
    new->value = val;
    new->next = NULL;

    if (l->first == NULL) { // ÂÒÎË ÒÔËÒÓÍ ÔÛÒÚÓÈ
        l->first = l->last = new;
    }
    else {
        l->last->next = new;
        l->last = new;
    }
};

void free_list(Tlist* l){  //4
  node *tmp;
  while(l->first!=NULL){
    tmp=l->first->next;
    free(l->first);
    l->first=tmp;
  }
  l->last=NULL;
};

#endif // TLIST_H_INCLUDED
