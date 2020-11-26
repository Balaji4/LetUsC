#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>

struct node
{
 char c;
 struct node *right;
 struct node *left;
}*s[40],*temp,*root;

char prefix[30],ch;
int top=-1,max=50,len;

void infix(struct node *);
void post(struct node *);
void treegen();
struct node* pop();
void push(struct node *);

void main()
{
clrscr();
printf("Enter a Prefix Expression : ");
scanf("%s",prefix);
treegen();
printf("\nThe Infix Expression : ");
infix(root);
printf("\nThe Postfix Expression is : ");
post(root);
getch();
}

void infix(struct node *ptr)
{
 if(ptr!=NULL)
 {
  infix(ptr->left);
  printf("%c",ptr->c);
  infix(ptr->right);
 }
return;
}

void post(struct node *ptr)
{
 if(ptr!=NULL)
 {
  post(ptr->left);
  post(ptr->right);
  printf("%c",ptr->c);
  }
return;
}

void treegen()
{
 int i;
 len=strlen(prefix);
 i=len-1;
 while(i>=0)
 {
  switch(prefix[i])
  {
   case '+':
   case '-':
   case '*':
   case '/':
   case '^':
	   temp=(struct node*)malloc(sizeof(struct node));
	   temp->c=prefix[i];
	   temp->left=pop();
	   temp->right=pop();
	   push(temp);
	   break;
   default:
	   temp=(struct node*)malloc(sizeof(struct node));
	   temp->c=prefix[i];
	   temp->right=NULL;
	   temp->left=NULL;
	   push(temp);

  }
i--;
 }
root=s[top];
}


void push(struct node *p)
{
 if(top==max)
  printf("Overflow\n");
 else
  {
  s[++top]=p;
  }
return;

}

struct node* pop()
{
 if(top==-1)
  printf("Underflow\n");
 else
  return(s[--top]);
}

