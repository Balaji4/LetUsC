#include<stdio.h>
#include<conio.h>
struct reachable
{
	int n;
	int s[20];
	int a[20][20];
	int source;
};
struct reachable b;
void read_data()
{
	int i,j;
	printf("Enter the number of nodes\n");
	scanf("%d",&b.n);
	printf("Enter the adjacency matrix\n");
	for(i=0;i<b.n;i++)
	{
		for(j=0;j<b.n;j++)
		{
			scanf("%d",&b.a[i][j]);
		}
	}
	printf("Enter the source\n");
	scanf("%d",&b.source);
b.source=b.source-1;

}
void print_data(int q[],int r)
{
	int i;
	for(i=0;i<b.n;i++)
	{
		if(i!=b.source)
		{
		if(b.s[i]==0)
			printf("Vertex % d is not reachable\n",i+1);
		else
			printf("vertex %d is reachable\n",i+1);
		}
	}

	printf("The queue is:\n");
	for(i=0;i<=r;i++)
	printf("-> %d",q[i]+1);
	printf("\n");

}
void bfs_traversal()
{
	int f,r,q[20],u,v,i;
	for(i=1;i<=b.n;i++)
		b.s[i]=0;
	f=r=0;
	q[r]=b.source;
	while(f<=r)
	{
		u=q[f++];
		for(v=1;v<=b.n;v++)
		{
			if(b.a[u][v]==1 && b.s[v]==0)
			{
				b.s[v]=1;
				q[++r]=v;
			}
		}
	}
	print_data(q,r);
}
int main()
{
	clrscr();
	read_data();
	bfs_traversal();
	getch();

	return 0;
}


