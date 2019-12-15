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

int loadformfile(Tlist *l){  //5
  int n=0;
  FILE *f;
  char sym[100];
  realty buf;
  f=fopen(FILENAME,"r");
  if(!f){
    perror("Zaznamy neboli nacitane\n");
    return n;
  }
  free_list(l);
  while(fscanf(f,  "%100[^\n]\n",sym) == 1){
    if(fscanf(f, "%50[^\n]\n", &buf.Category));
    if(fscanf(f, "%50[^\n]\n", &buf.Location));
    if(fscanf(f, "%100[^\n]\n", &buf.Street));
    if(fscanf(f, "%d\n", &buf.Square));
    if(fscanf(f, "%d\n", &buf.Price));
    if(fscanf(f, "%200[^\n]\n", &buf.Description));
    ++n;
    push_back(l,buf);
  }
fclose(f)  ;
return n;
}

void print_All_List(Tlist l){  //6
 const node* buff = l.first;
 int n=1;
 for (; buff; buff = buff->next,n++) {
        printf("%d.\n",n);
        printf("kategoria ponuky: %s\n", buff->value.Category);
        printf("miesto ponuky: %s\n", buff->value.Location);
        printf("ulica: %s\n", buff->value.Street);
        printf("rozloha: %d\n", buff->value.Square);
        printf("cena: %d\n", buff->value.Price);
        printf("popis: %s\n", buff->value.Description);
    }
    printf("\n");
}

#endif // TLIST_H_INCLUDED
