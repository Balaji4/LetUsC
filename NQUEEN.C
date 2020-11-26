#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0

void print_solution(int n,int x[])
{
	char c[10][10],i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			c[i][j]='X';
		}
	}
	for(i=1;i<=n;i++)
	{
		c[i][x[i]]='Q';
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%c\t",c[i][j]);
		}
		printf("\n");
	}
}

int place(int x[],int k)
{
	int i;
	for(i=1;i<k;i++)
	{
		if(x[i]==x[k] || i-x[i]==k-x[k] ||i+x[i]==k+x[k])
		{
			return FALSE;
		}
	}
	return TRUE;
}

void queens(int n)
{
	int x[10],count=0,k=1;
	x[k]=0;
	while(k!=0)
	{
		x[k]+=1;
	
		while((x[k]<=n) && (!place(x,k)))
		{
			x[k]+=1;
		}
		if(x[k]<=n)
		{
			if(k==n)
			{
				count++;
				printf("Solution %d is\n",count);
				print_solution(n,x);
			}
			else
			{
				k++;
				x[k]=0;
			}	
		}
		else
		{
			k--;
		}
	}
}

int main()
{
	int n;
	printf("Enter the number of queens");
	scanf("%d",&n);
	queens(n);
	return 0;
}