#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insert();
void del();
void display();
struct node
{
struct node *left;
struct node * right;
int info;
};
typedef struct node* Node;
void main()
{
int ch;
 for(;;)
 {
  printf("\ninsert element");
  printf("\n Delete element");
  printf("\n Display tree \n");
  scanf("%d",&ch);
  switch(ch)
   {
   case 1:insert();  break;
   case 2:del(); break;
   case 3:display(); break;
   default: exit(0);
  }
 }
}
void insert()
{
}
void del(){}
void display(){}