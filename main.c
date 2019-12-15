#include <stdio.h>
#include <stdlib.h>
#include "Tlist.h"
#define MAXLENSTR (255)
int main()
{
   Tlist L={NULL,NULL};
   char ch;
   int n;
   realty buf;
   char str[MAXLENSTR];
   while (1){
       printf("> ");
       scanf("%c",&ch);
       while (getchar() != '\n');
       switch(ch){
               case 'n':{
                  n=loadformfile(&L);
                  printf("Nacitalo sa %d\n zaznamov",n);
                  break;
               }
               case 'v':{
                  print_All_List(L);
                  break;
               }
               case 'k':{
                  free_list(&L);
                  return 0;
               }
               case 'p':{
                   printf("Position: ");
                   scanf("%d",&n);
                   gets(buf.Category);
                   gets(buf.Location);
                   gets(buf.Street);
                   gets(str);
                   buf.Square=atoi(str);
                   gets(str);
                   buf.Price=atoi(str);
                   gets(buf.Description);
                   while (getchar() != '\n');
                   insert_list(&L,n,buf);
                  break;
               }
               
               
    return 0;
}
