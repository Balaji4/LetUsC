
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct dlist
{
int info;
struct dlist *left,*right;
};

struct dlist* getnode()
{
struct dlist *t;
t=(struct dlist*)(malloc(sizeof(struct dlist)));
if(t==NULL)
{
printf("Memory not available\n");
return NULL;
}
else {
return t;
}
}

struct dlist* insertf(struct dlist *f,int item)
{
struct dlist *temp;
temp=getnode();
temp->info=item;
temp->right=f;
temp->left=NULL;
return temp;

}
struct dlist* insertr(struct dlist *f,int item)
{
struct dlist *temp=f,*p;
if(temp==NULL)
{
temp=getnode();
temp->info=item;
temp->right=temp->left=NULL;
return temp;
}
else
{
 while(temp!=NULL)
 {
 p=temp;
 temp=temp->right;
 temp->left=p;
 }
 temp=getnode();
 temp->info=item;
 temp->right=NULL;
 p->right=temp;
 temp->left=p;
 return f;
}
}

struct dlist* deletef(struct dlist *f)
{
struct dlist *temp;
if(f==NULL)
{
printf("List is empty\n");
return NULL;
}
else
{
temp=f;
temp=temp->right;
printf("item deleted=%d",f->info);
free(f);
temp->left=NULL;
return temp;
}
}

struct dlist* deleter(struct dlist *f)
{
struct dlist *temp,*p;
if(f==NULL)
{
printf("List is empty\n");
return NULL;
}
if(f->right==NULL)
{
printf("Item deleted=%d\n",f->info);
free(f);
return NULL;
}

else
{
p=NULL;
temp=f;
while(temp->right!=NULL)
{
p=temp;
temp=temp->right;
temp->left=p;
}

printf("item deleted=%d",temp->info);
free(temp);
p->right=NULL;
return f;
}
}

void display(struct dlist *f)
{
struct dlist *temp=f;
if(temp==NULL)
{
printf("list empty, nothing to display\n");
}
else
{
printf("elements are\n");
while(temp!=NULL)
{
printf(" %d",temp->info);
temp=temp->right;
}
}

}



int main(void)
{
   struct dlist *first=NULL;

   int ch,item;
   first->right=first->left=NULL;
   clrscr();
   for(;;)
   {
   printf("\nMENU\n1:INSERT FRONT\n2:INSERT REAR\n3:DELETE FRONT\n4:DELETE REAR\n5:DISPLAY \n6:EXIT");
   printf("\nenter your choice\n");
   scanf("%d",&ch);
    switch(ch)
    {
    case 1:printf("\nenter item to be inserted in front\n");
	   scanf("%d",&item);
	   first=insertf(first,item);
	   break;
    case 2:printf("\nenter item to be inserted in rear\n");
	   scanf("%d",&item);
	   first=insertr(first,item);
	   break;
    case 3:first=deletef(first);
	   break;
    case 4:first=deleter(first);
	   break;
    case 5:display(first);
	   break;

    default:exit(0);
    }
   }
   return 0;
}

