







#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct node
{
int info;
struct node *llink;
struct node *rlink;
};
typedef struct node * NODE;
NODE getnode()
{
NODE x;
x = (NODE) malloc (sizeof(struct node));
if(x == NULL)
{
	printf("out of memory");
	exit(0);
}
return x;
}
NODE insert (int item ,NODE root)
{
	NODE temp;
	NODE cur;
	NODE prev;
	char direction[10];
	int i;
	temp = getnode();
	temp->info = item;
	temp->llink = temp->rlink = NULL;
	if(root == NULL)
	return temp;

	printf("give the direction where want to insert");
	scanf("%s",direction);
	//toupper(direction);
	prev = NULL;
	cur = root;
	for(i=0;i<strlen(direction);i++)
	{
		if(cur == NULL)
		break;
		prev = cur;
		if(direction[i]=='L')
		cur =cur->llink;
		else
		cur = cur ->rlink;
	}

	if(cur != NULL || i != strlen(direction))
	{
	 printf("insertion not possible");
	 free(temp);
	 return root;
	}

	if(direction[i-1] == 'L')
	prev->llink = temp;
	else
	prev ->rlink = temp;
	return root;
}
	void preorder(NODE root)
	{
	if(root == NULL)     return;

		printf("%d",root->info);
		preorder(root->llink);
		preorder(root->rlink);

	}
	void main()
	{
	NODE root = NULL;
	int choice,item,flag;
	clrscr();

	for(;;)
	{
	printf("1.Insert item\n2.Get preorder\n3.Exit\n");
	printf("choose :");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		printf("enter the item to be inserted");
		scanf("%d",&item);
		root = insert(item,root);
		break;
		case 2:printf("contents are:");
		if(root == NULL) return;
		preorder(root);
		break;
		default:exit(0);
	}
	}
}



















