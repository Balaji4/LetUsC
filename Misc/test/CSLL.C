#include<stdio.h>

struct node
{
 int info;
 struct node *link;
};

typedef struct node * Node;

Node insert_f(int item,Node last)
{
 Node temp = (Node)malloc(sizeof(struct node));
 temp->info = item;
 if(last==NULL)
 {
  last=temp;
 }
 else
 {
  temp->link = last->link;
 }
 last->link = temp;
 return last;
}

Node delete_f(Node last)
{
 Node temp;
 if(last==NULL)
 {
 printf("List is empty");
 return last;
 }
 if(last->link==last)
  {
  printf("\n Item deleted=%d",last->info);
  free(last);
  return NULL;
  }

 temp=last->link;
 last->link = temp->link;
 printf("Item deleted =%d",temp->info);
 free(temp);
 return last;
}

Node insert_r(int item,Node last)
{
 Node temp = (Node)malloc(sizeof(struct node));
 temp->info = item;
 if(last==NULL)
 {
  last=temp;
 }
 else
 {
  temp->link = last->link;
 }
 last->link = temp;
 return temp;
}

Node delete_r(Node last)
{
 Node prev;
 if(last==NULL)
 {
  printf("List is empty");
  return last;
 }
 prev = last;
 if(last->link==last)
  {
   printf("Item deleted=%d",last->info);
   free(last);
   return NULL;
  }
  while(prev->link!=last)
  {
   prev = prev->link;
  }
  prev->link = last->link;
  printf("\nItem deleted=%d",last->info);
  free(last);
  return prev;
}

void display(Node last)
{
 Node temp;
 printf("\n");
 if(last==NULL)
 {
  printf("[]");
 return;
 }
 temp=last->link;
 while(temp!=last)
  {
   printf("[%d]=>",temp->info);
   temp=temp->link;
  }
  printf("[%d]",temp->info);
}

void search(int item, Node last)
{
 Node temp;
 if(last==NULL)
 {
  printf("\nList is empty");
  return;
 }
 if(last->info==item)
  {
  printf("%d found ",item);
  }
 temp = last->link;
 while(temp!=last)
  {
  if(temp->info==item)
   break;
  temp = temp->link;
  }
  if(temp==last)
   {
   printf("\n%d Not found",item);
   }else {
   printf("\n %d Found",item);
   }
}

Node delete_specified(int item,Node last)
{
 Node prev,cur;
 if(last==NULL)
 {
 printf("\n List is empty");
 return last;
 }
 prev=NULL;
 cur = last;
 if(last->info==item&&last->link==last)
 {
 printf("\n Item deleted=%d",last->info);
 free(last);
 return NULL;
 }

 while(cur!=last)
 {
  if(cur->info==item)
   break;
  prev = cur;
  cur=cur->link;
 }
 if(cur==last)
  {
   printf("\n %d not found",item);
   return last;
  }else {
  prev->link = cur->link;
  printf("\n Item deleted =%d",cur->info);
  free(cur);
  return last;
  }

}

void reverse(Node last)
{

 if(last==NULL)
 {
  return;
 }
 if(last->link==last)
 {
 printf("[%d]",last->info);
 return;
 }
 reverse(last->link);
 printf("[%d]=>",last->info);
}

Node sort(Node last)
{
Node q=last->link,p;

 int data;
 if(last==NULL)
 {
  printf("\n List is empty");
  return last;
 }

 while(q!=last)
  {
   p=q->link;
   while(p!=last)
   {
   if(q->info>p->info)
    {
    data=q->info;
    q->info = p->info;
    p->info = data;
    }
    p = p->link;
   }
   q = q->link;
  }
 return last;
}


int size(Node last)
{
 Node temp=last->link;
 int count=1;
 if(last==NULL)
  {
  return 0;
  }
 while(temp!=last)
 {
 temp=temp->link;
 count++;
 }
 return count;
}

void main()
{
 Node last = NULL;
 int ch,item;
 for(;;)
 {
  printf("\n1: Insert Front\n");
  printf("2: Insert Rear\n");
  printf("3: Delete Front\n");
  printf("4: Delete Rear\n");
  printf("5: Display\n");
  printf("6: Search\n");
  printf("7: Deleted specified\n");
  printf("8: Reverse list\n");
  printf("9: Sort list\n");
  printf("10: Exit\n");

  scanf("%d",&ch);
  switch(ch)
  {
   case 1: printf("Enter Item to be inserted in front\n");
	   scanf("%d",&item);
	   last = insert_f(item,last);
	   break;

   case 2: printf("Enter Item to be inserted in rear\n");
	   scanf("%d",&item);
	   last = insert_r(item,last);
	   break;

   case 3: last = delete_f(last);
	   break;

   case 4: last = delete_r(last);
	   break;

   case 5: display(last);
	   break;

   case 6: printf("\nEnter item to be searched");
	   scanf("%d",&item);
	   search(item,last);
	   break;

   case 7: printf("\n Enter info to be deleted");
	   scanf("%d",&item);
	   last = delete_specified(item,last);
	   break;

   case 8: reverse(last);
	   break;

   case 9: last = sort(last);
	   display(last);
	   break;

   default: exit(0);
 }
 }
}