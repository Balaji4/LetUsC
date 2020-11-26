
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct list
{
int info;
struct list *link;
};

struct list* getnode()
{
struct list *t;
t=(struct list*)(malloc(sizeof(struct list)));
if(t==NULL)
{
printf("Memory not available\n");
return NULL;
}
else {
return t;
}
}

struct list* insertf(struct list *f,int item)
{
struct list *temp;
temp=getnode();
temp->info=item;
temp->link=f;
return temp;

}
struct list* insertr(struct list *f,int item)
{
 struct list *temp=f,*p;
if(temp==NULL)
{
temp=getnode();
temp->info=item;
temp->link=NULL;
return temp;
}
else
{
 while(temp!=NULL)
 {
 p=temp;
 temp=temp->link;
 }
 temp=getnode();
 temp->info=item;
 temp->link=NULL;
 p->link=temp;
 return f;
}
}

struct list* deletef(struct list *f)
{
struct list *temp;
if(f==NULL)
{
printf("List is empty\n");
return NULL;
}
else
{
temp=f;
temp=temp->link;
printf("item deleted=%d",f->info);
free(f);
return temp;
}
}

struct list* deleter(struct list *f)
{
struct list *temp,*p;
if(f==NULL)
{
printf("List is empty\n");
return NULL;
}
if(f->link==NULL)
{
printf("Item deleted=%d\n",f->info);
free(f);
return NULL;
}

else
{
p=NULL;
temp=f;
while(temp->link!=NULL)
{
p=temp;
temp=temp->link;
}

printf("item deleted=%d",temp->info);
free(temp);
p->link=NULL;
return f;
}
}

void display(struct list *f)
{
struct list *temp=f;
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
temp=temp->link;
}
}

}



int main(void)
{
   struct list *first=NULL;
   int ch,item;
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