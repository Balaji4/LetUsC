
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct treenode
	       {
		char c;
		struct treenode * rlink;
		struct treenode * llink;
	       }*stc[30],*temp,*root;


char prefix[20],ch;
int topt=-1,max=50,len;

void pusht(struct treenode * p);
struct treenode* popt();

void exptree();
void post(struct treenode* p);
void infix(struct treenode *);
void main()
{
 clrscr();
 printf("Enter a prefix expression	:");
 scanf("%s",prefix);
 exptree();

 printf("The postfix expression is	:");
 post(root);
 printf("\nThe infix expression is         :");
 infix(root);
 getch();
}

void post(struct treenode* p)
{
 if(p!=NULL)
 {
  post(p->llink);
  post(p->rlink);
  printf("%c",p->c);
 }
}
void exptree()
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
	     temp=(struct treenode*)malloc(sizeof(struct treenode));
	     temp->c=prefix[i];
	     temp->llink=popt();
	     temp->rlink=popt();
	     pusht(temp);
	     break;
    default :
	     temp=(struct treenode*)malloc(sizeof(struct treenode));
	     temp->c=prefix[i];
	     temp->rlink=NULL;
	     temp->llink=NULL;
	     pusht(temp);
   }
   i--;
  }
  root=stc[topt];
}


void pusht(struct treenode * p)
{
 if(topt==max)
 {
  printf("overflow");
 }
 else
 {
  stc[++topt]=p;
 }
}


struct treenode* popt()
{
 if(topt==-1)

 printf("underflow");

 else

 return(stc[topt--]);

}


void infix(struct treenode *ptr)
{
if(ptr!=NULL)
{
  infix(ptr->llink);
  printf("%c",ptr->c);
  infix(ptr->rlink);
}
 }
