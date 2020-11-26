// singly list to implement set operations
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *link;
};
typedef struct node* Node;
Node insert(Node,int);
int ispresent(Node,int);
void display(Node);
Node del(Node,int);
void uni(Node,Node);
void intersect(Node,Node);
void main()
{
int i;
int ch,set,item;
Node first=NULL,second=NULL;
 clrscr();
 for(;;)
 {
 printf("\n MENU \n");
 printf("1> Insert into set \n");
 printf("2> Delete from set \n");
 printf("3> Display set\n");
 printf("4> Union of sets \n");
 printf("5> Intersection of sets \n");
 printf("6> Exit\n");
 printf("Choice: ");
 scanf("%d",&ch);
  switch(ch)
  {
  case 1:printf("\nenter element to be inserted \n");
	scanf("%d",&item);
	printf("\nenter set No: ");
	 scanf("%d",&set);
	 if(set==1)
	   {
	   first=insert(first,item);
	   }
	 else
	  {

	 second=insert(second,item);
	 }
	 break;
  case 2:printf("\nenter element to be deleted \n");
	scanf("%d",&item);
	printf("\nenter set No: ");
	 scanf("%d",&set);
	 if(set==1)
	   {
	   first=del(first,item);
	   }
	 else
	  {

	 second=del(second,item);
	 }
	 break;

  case 3:printf("\n enter set no.: ");
	 scanf("%d",&set);
	 if(set==1)
	 {
	 printf("\n SET 1\n");
	 display(first);
	 }
	 else
	 {
	 printf("\n SET 2\n");
	 display(second);
	 }
	 break;
  case 4:uni(first,second);
	 break;
  case 5:intersect(first,second);
	 break;
  default: exit(0);
  }

 }
}

Node insert(Node start, int item)
{
Node temp,cur=start,prev=NULL;
temp=(Node)malloc(sizeof(struct node));
temp->info=item;
temp->link=NULL;
 if(start==NULL)
  {
  return temp;
  }
  while(cur!=NULL)
  {
   if(cur->info==temp->info)
   {
   printf("\n item already exists \n");
   return start;
   }
   prev=cur;
   cur=cur->link;
  }
  prev->link=temp;
  return start;
 }

void display(Node start)
{
 if(start==NULL)
 {
 printf("\n This set is empty \n");
 return;
 }
 while(start!=NULL)
 {
 printf(" %d",start->info);
 start=start->link;
 }
}


Node del(Node start,int item)
{
Node temp,cur=start,prev=NULL;
if(start==NULL)
 {
 printf("\n This set is empty \n");
 return NULL;
 }
 if(start->info==item)
  {
  printf("\n Item deleted =%d",item);
  start=start->link;
  free(cur);
  return start;
  }
 while(cur!=NULL)
  {
  if(cur->info==item)
   {
   break;
   }
   prev=cur;
   cur=cur->link;
  }
  if(cur==NULL)
  {
  printf("\n Item not found \n");
  return start;
  }
  printf("\n Item deleted =%d",cur->info);
  prev->link=cur->link;
  free(cur);
  return start;

}

void uni(Node s1,Node s2)
{
Node res=NULL,t1=s1,t2=s2;
  while(t1!=NULL)
  {
   res=insert(res,t1->info);
   t1=t1->link;
  }
  while(t2!=NULL)
   {
   if(ispresent(res,t2->info))
    {
    t2=t2->link;
    continue;
    }
    res=insert(res,t2->info);
    t2=t2->link;
   }
   display(res);
}

int ispresent(Node var,int item)
{
while(var!=NULL)
 {
 if(var->info==item)
 return 1;
 var=var->link;
 }
 return 0;
}

void intersect(Node s1,Node s2)
{
Node res=NULL,t1=s1,t2=s2;
while(t1!=NULL)
{
t2=s2;
 while(t2!=NULL)
  {
  if(t1->info==t2->info)
   {
   res=insert(res,t1->info);
   }
   t2=t2->link;
  }
  t1=t1->link;
}
display(res);
}