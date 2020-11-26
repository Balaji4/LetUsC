//Floyds 

#include<stdio.h>
void dist();
void readdata();
void writedata();
int min(int,int);

int n,cost[10][10],d[10][10];
int main()
{
	readdata();
	dist();
	writedata();
	return 0;
}

int min(int a,int b)
{
	return a<b?a:b;
}

void readdata()
{
	int i,j;
	printf("\n Enter the no of nodes:");
	scanf("%d",&n);
	printf("\n Enter the cost adjacency matrix:");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
			d[i][j]=cost[i][j];
		}

}

void writedata()
{
	int i,j,x=65;
	printf("\n The distence Between Nodes:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		
			printf("%c -> %c = %d\t",x+i,x+j,d[i][j]);
		printf("\n\n");
		
	}
}

void dist()
{
	int i,j,k;
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
		
