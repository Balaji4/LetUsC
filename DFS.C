#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct graph
{
	int n;
	int a[10][10];
};
struct graph g;
void readMatrix()
{
	int i,j;
	printf("Enter the number of nodes\n");
	scanf("%d",&g.n);
	printf("Enter the cost adjacency matrix\n");
	for(i=0;i<g.n;i++)
		for(j=0;j<g.n;j++)
		scanf("%d",&g.a[i][j]);
}
void dfs(int u,int s[])
{
	int v;
	s[u]=1;
	for(v=0;v<g.n;v++)
		if(g.a[u][v]==1 && s[v]==0)
			dfs(v,s);
}


int connectivity()
{
	int i,j,flag=0,s[10];
	for(j=0;j<g.n;j++)
	{
		for(i=0;i<g.n;i++)
			s[i]=0;
		dfs(j,s);
		for(i=0;i<g.n;i++)
		{
			if(s[i]==0)
				flag=1;
		}
		if(flag==0)
			return 1;
	}
	return 0;
}
int main()
{
	int flag;
	clrscr();
	readMatrix();

	flag=connectivity();
	if(flag==1)
		printf("The graph is connected\n");
	else
		printf("The graph is not connected\n");
		getch();
	return 0;
}
