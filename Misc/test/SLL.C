#include<stdio.h>

struct node
{
 int info;
 struct node *link;
};

typedef struct node * Node;

Node insert_f(int item,Node first)
{
 Node temp = (Node)malloc(sizeof(struct node));
 temp->info = item;
 temp->link = first;
 return temp;
}

Node delete_f(Node first)
{
 Node temp;
 if(first==NULL)
 {
 printf("List is empty");
 return first;
 }
 temp=first;
 temp = temp->link;
 printf("Item deleted =%d",first->info);
 free(first);
 return temp;
}

Node insert_r(int item,Node first)
{
 Node cur=first;
 Node temp= (Node)malloc(sizeof(struct node));
 temp->info = item;
 temp->link=NULL;
 if(first==NULL)
  {
   return temp;
  }
 while(cur->link!=NULL)
 {
  cur=cur->link;
 }
 cur->link=temp;
 return first;
}

Node delete_r(Node first)
{
 Node prev,cur;
 if(first==NULL)
 {
  printf("List is empty");
  return first;
 }
 cur = first;
 prev = NULL;
 if(first->link==NULL)
  {
   printf("Item deleted=%d",first->info);
   free(first);
   return NULL;
  }
  while(cur->link!=NULL)
  {
   prev = cur;
   cur = cur->link;
  }
  prev->link = NULL;
  printf("\nItem deleted=%d",cur->info);
  free(cur);
  return first;
}

void display(Node first)
{
 Node temp = first;
 printf("\n");
 if(first==NULL)
 {
  printf("[]");
 return;
 }
 while(temp!=NULL)
  {
   printf("[%d]=>",temp->info);
   temp=temp->link;
  }
}

void search(int item, Node first)
{
 Node temp=first;
 int pos=0;
 if(first==NULL)
 {
  printf("\nList is empty");
  return;
 }
 while(temp!=NULL)
  {
  if(temp->info==item)
   break;
  temp = temp->link;
  pos++;
  }
  if(temp==NULL)
   {
   printf("\n%d Not found",item);
   }else {
   printf("\n Found %d at %d",item,pos);
   }
}

Node delete_specified(int item,Node first)
{
 Node prev,cur;
 if(first==NULL)
 {
 printf("\n List is empty");
 return first;
 }
 prev=NULL;
 cur=first;
 if(first->info==item)
 {
 cur = cur->link;
 printf("\n Item deleted=%d",first->info);
 free(first);
 return cur;
 }

 while(cur!=NULL)
 {
  if(cur->info==item)
   break;
  prev = cur;
  cur=cur->link;
 }
 if(cur==NULL)
  {
   printf("\n %d not found",item);
   return first;
  }else {
  prev->link = cur->link;
  printf("\n Item deleted =%d",cur->info);
  free(cur);
  return first;
  }

}

Node reverse(Node first)
{
 Node temp,cur;

 cur=NULL;
 while(first!=NULL)
 {
  temp=first->link;
  first->link = cur;
  cur=first;
  first = temp;
 }
 return cur;
}

Node sort(Node first)
{
Node q=first,p=first->link;
 //int i,j,pos;
 //int n = size(first);
 int data;
 if(first==NULL)
 {
  printf("\n List is empty");
  return first;
 }

 while(q!=NULL)
  {
   p=q->link;
   while(p!=NULL)
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
 return first;
}





int size(Node first)
{
 Node temp=first;
 int count=0;
 if(first==NULL)
  {
  return 0;
  }
 while(temp!=NULL)
 {
 temp=temp->link;
 count++;
 }
 return count;
}

void main()
{
 Node first = NULL;
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
	   first = insert_f(item,first);
	   break;

   case 2: printf("Enter Item to be inserted in rear\n");
	   scanf("%d",&item);
	   first = insert_r(item,first);
	   break;

   case 3: first = delete_f(first);
	   break;

   case 4: first = delete_r(first);
	   break;

   case 5: display(first);
	   break;

   case 6: printf("\nEnter item to be searched");
	   scanf("%d",&item);
	   search(item,first);
	   break;

   case 7: printf("\n Enter info to be deleted");
	   scanf("%d",&item);
	   first = delete_specified(item,first);
	   break;

   case 8: first = reverse(first);
	   display(first);
	   break;

   case 9: first = sort(first);
	   display(first);
	   break;

   default: exit(0);
 }
 }
}