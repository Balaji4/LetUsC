#include<stdio.h>
#include<conio.h>
struct kruskal
{
	int m,n,c[10][10];
}k;

void obtaincostadjacencymatrix()
{
	int i,j,u,v;
    /*Initialize matrix*/
	for(i=1;i<=k.n;i++)
	{
		for(j=1;j<=k.n;j++)
		{
			k.c[i][j]=999;
		}
	}
	/*Enter cost for each edge present*/
	for(i=1;i<=k.m;i++)
	{
		printf("Enter  edge(u,v)");
		scanf("%d %d",&u,&v);
		printf("Enter its cost\n");
		scanf("%d",& k.c[u][v]);
		k.c[v][u]=k.c[u][v];
	}
}

int find(int v,int p[])
{
	if(p[v]!=v)
		v=p[v];
	return v;
}

void union_ij(int i,int j,int p[])
{
	if(i<j)
		p[j]=i;
	else
		p[i]=j;
}

void minimumspanningtree()
{
	int count,i,p[10],min,j,u,v,l,t[10][2],sum;
	count=0;
	l=0;
	sum=0;
	for(i=1;i<=k.n;i++)
		p[i]=i;
	while(count<k.n)
	{
		min=999;
		/*Find the minimum edge*/
		for(i=1;i<=k.n;i++)
		{
			for(j=1;j<=k.n;j++)
			{
				if(k.c[i][j] < min)
				{
					min=k.c[i][j];
					u=i;
					v=j;
				}
			}
		}
		if(min==999)
			break;
		i=find(u,p);
		j=find(v,p);
		if(i!=j)
		{
			t[l][0]=u;
			t[l][1]=v;
			l++;
			count++;
			sum+=min;
			union_ij(i,j,p);
		}
		k.c[v][u]=k.c[u][v]=999;
	}
	if(count==k.n-1)
	{
		printf("Cost of spanning tree=%d\n\n",sum);
		printf("Spanning tree is shown below\n");
		for(l=0;l<k.n-1;l++)
			printf("%d,%d\n",t[l][0],t[l][1]);
		return;
	}
	printf("Spanning tree do not exist\n");
}


int main()
{
	clrscr();
	printf("Enter the no of nodes\n");
	scanf("%d",&k.n);
	printf("Enter the no of edges:");
	scanf("%d",&k.m);
	obtaincostadjacencymatrix();
	minimumspanningtree();
	getch();
	return 0;
}
	

