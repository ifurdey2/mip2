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
               case 'z':{
                  printf("Location to delete entries: ");
                  gets(str);
                  while (getchar() != '\n');
                  n=delete_from_list(&L,str);
                  printf("Vymazalo sa %d zaznamov\n",n);
                  break;
               }
               case 'h':{
                   printf("V ponuke su len reality s vyssou cenou ");
                   scanf("%d",&n);
                   while (getchar() != '\n');
                   find_list(L,n);
                   break;
               }
               case 'a':{
                  printf("Location for changing data: ");
                  while (getchar() != '\n');
                  gets(str);
                  gets(buf.Category);
                  gets(buf.Location);
                  gets(buf.Street);
                  gets(str);
                  buf.Square=atoi(str);
                  gets(str);
                  buf.Price=atoi(str);
                  gets(buf.Description);
                  while (getchar() != '\n');
                  n=chenge_list(&L,str,buf);
                  printf("Aktualizovalo sa %d zaznamov\n",n);
                  break;
               }
               default:{
                         printf("Unknown team!\n");
                         break;
                      }
                   }
               }
               
    return 0;
}
