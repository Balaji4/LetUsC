/* BST operations */
#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node *left;
struct node *right;
int info;
};
typedef struct node* Node;
Node insert(int,Node);
Node del(int,Node);
void display(Node);
void preorder(Node );
void postorder(Node );
void inorder(Node );
int minnode(Node rt);
int maxnode(Node rt);
void search(int, Node);
void main()
{
int ch,item;
Node root=NULL;
clrscr();
for(;;)
 {
 printf("\n MENU \n");
 printf("1: Insert \n");
 printf("2: Delete \n");
 printf("3: Display \n");
 printf("4: Max Node \n");
 printf("5: Min Node \n");
 printf("6: Search\n");
 printf("7: Exit\n");
 printf("\n Enter your choice: ");
 scanf("%d",&ch);
  switch(ch)
   {
   case 1:printf("\n enter item to be inserted\n");
	scanf("%d",&item);
	root=insert(item,root);
	inorder(root);
	break;
   case 2:printf("\n enter item to be deleted\n");
	scanf("%d",&item);
	root=del(item,root);
	break;
   case 3:display(root);
	  break;
  /* case 4:item=maxnode(root);
	  if(item==-1)
	  {
	  printf("\n Tree empty no max exist\n");
	  }
	  else
	   printf("\n Max node info=%d",item);
	  break;
   case 5:item=minnode(root);
	  if(item==-1)
	  {
	  printf("\n Tree empty no min exist\n");
	  }
	  else
	    printf("\n Min node info=%d",item);
	  break;
   case 6:printf("\nenter the item to be searched\n");
	  scanf("%d",&item);
	  search(item,root);
	  break;*/
   default:exit(0);
   }
 }
}

Node insert(int item, Node rt)
 {
 Node temp,cur,prev;
 temp=(Node)malloc(sizeof(struct node*));
 if(temp==NULL)
  {
  printf("\n No free memory\n");
  return rt;
  }
 temp->info=item;
 temp->left=NULL;
 temp->right=NULL;
 if(rt==NULL)
   {
   return temp;
   }
  cur=rt;
  prev=NULL;
  while(cur!=NULL)
   {
   prev=cur;
   if(item<cur->info)
     cur=cur->left;
    else
     cur=cur->right;
   }
   if(item<prev->info)
    prev->left=temp;
   else
    prev->right=temp;
  return rt;
 }


Node del(int item,Node rt)
{
Node cur,parent,q,suc;
if(rt==NULL)
 {
 printf("\n Tree empty \n");
 return NULL;
 }
parent=NULL;
cur=rt;
while(cur!=NULL)
 {
 if(cur->info==item) break;
 parent=cur;
 if(item<cur->info)
  cur=cur->left;
 else
  cur=cur->right;
 }
 if(cur==NULL)      //case 1 no element
  {
  printf("\n %d Not found ",item);
  return rt;
  }
  if(cur->left==NULL)    // case 2 no left child of node to be deleted
  {
   q=cur->right;
  }
  else
  if(cur->right==NULL) // case 3 no right child of node to be deleted
  {
  q=cur->left;
  }
  else
  {
  suc=cur->right;
  while(suc->left!=NULL)
   {
   suc=suc->left;
   }
   suc->left=cur->left;
   q=cur->right;
  }
  if(parent==NULL)
  {
  printf("\n Item deleted =%d",item);
  free(cur);
  return q;
  }
  if(cur==parent->left)
   parent->left=q;
   else if(cur==parent->right)
   parent->right=q;
  return rt;
}
void display(Node rt)
{
int ch;
if(rt==NULL)
 {
 printf("\n Tree empty\n");
 return;
 }
printf("\n1:Preorder traversal\n");
printf("2:Postorder traversal\n");
printf("3:Inorder traversal\n");
printf("\n Choice: ");
scanf("%d",&ch);
 switch(ch)
  {
  case 1:preorder(rt);
  break;
  case 2:postorder(rt);
  break;
  case 3:inorder(rt);
  break;
  }
}
void preorder(Node rt)
{
if(rt==NULL) return;
printf(" %d",rt->info);
preorder(rt->left);
preorder(rt->right);
}

void postorder(Node rt)
{
if(rt==NULL) return;
postorder(rt->left);
postorder(rt->right);
printf(" %d",rt->info);
}
void inorder(Node rt)
{
if(rt==NULL) return;
inorder(rt->left);
printf(" %d",rt->info);
inorder(rt->right);
}
int minnode(Node rt)
{
Node cur;
if(rt==NULL)
 {
return -1;
 }
cur=rt;
while(cur->left!=NULL)
 {
 cur=cur->left;
 }
 return cur->info;
}
int maxnode(Node rt)
{
Node cur;
if(rt==NULL)
 {
 return -1;
 }
cur=rt;
while(cur->right!=NULL)
 {
 cur=cur->right;
 }
 return cur->info;
}

void search(int item, Node rt)
{
Node cur;
if(rt==NULL)
 printf("\n Tree empty no min exist\n");
cur=rt;
while(cur!=NULL)
 {
 if(cur->info==item)
  {
   printf("\nItem found");
   return;
  }
 if(item<cur->info)
  cur=cur->left;
 else
  cur=cur->right;
 }
printf("\n Item Not found\n");
}