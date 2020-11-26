#include<stdio.h>
#include<conio.h>
struct Node
{
int info;
struct Node *left;
struct Node *right;
};
typedef struct Node* node;
node getnode()
{
node t=(node)malloc(sizeof(struct Node));
return (t);
}
node insert(int,node);
struct hoff
{
char ch;
int info;
};
int l1,l2,s;
void sort(int [],int);
int small(int a[],int n,int);
void main()
{
int n,i,j=0,t,index;
struct hoff item[10];
int dummy[10];
node root=NULL;
clrscr();
printf("\n How many nodes \n");
scanf("%d",&n);
t=n;
printf("\nEnter %d nodes  \n",n);
for(i=0;i<n;i++)
{
scanf("%s",&item[i].ch);
scanf("%d",&item[i].info);
}

for(i=0;i<n;i++)
{
dummy[i]=(int)item[i].info;
}
sort(dummy,n);
printf("\n max 2\n");
for(j=0;j<n;j++)
{
printf("%d\t",dummy[j]);
}
for(j=0;j<n;j+=2)
{
index=small(dummy,t,t+1);
l1=s;
t--;
index=small(dummy,t,index);
l2=s;
root=insert(l1+l2,root);
root=root->left;
}
printf("\n tree \n");
for(j=0;j<n/2;j++)
{
printf("\t%d",root->info);
}
getch();
}
int small(int a[],int n,int index)
{
int s=a[0],i,j;
for(i=1;i<n;i++)
{
 if(i!=index)
 {
 if(a[i]<s)
 {
 s=a[i];
 j=i;
 }
 }
}
return j;
}


node insert(int sum,node root)
{
node temp;
temp->info=sum;
temp->left->info=l1;
temp->right->info=l2;
 if(root==NULL)
 {
 return temp;
 }
 temp->left=root;
 return temp;
}


void sort(int a[],int n)
{
int i,j,temp;
for(i=1;i<n;i++)
	{
	 for(j=1;j<=n-i;j++)
	 {
		if(a[j-1]>a[j])
		{
		temp=a[j-1];
		a[j-1]=a[j];
		a[j]=temp;
		}
	 }
	}
}