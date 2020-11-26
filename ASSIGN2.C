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
void postorder(node root);
void main()
{
int n,i,item;
node root=NULL;
clrscr();
printf("\n How many nodes \n");
scanf("%d",&n);
printf("\nEnter %d nodes  \n",n);
for(i=0;i<n;i++)
{
scanf("%d",&item);
root=insert(item,root);
}
printf("\n Traversal of given tree in post-order is \n");
postorder(root);
getch();
}

node insert(int item,node root)
{
node temp,cur,prev;
temp=getnode();
temp->info=item;
temp->left=temp->right=NULL;
if(root==NULL)
{
return temp;
}
prev=NULL;
cur=root;
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
else prev->right=temp;
return root;
}

void postorder(node root)
{
if(root==NULL)
return;
postorder(root->left);
postorder(root->right);
printf("%d\t",root->info);
}
