#include<stdio.h>
#include<stdlib.h>
int main()
{

int n,**a,i,j,k;
clrscr();
printf("Enter the number of vertices\n");
scanf("%d",&n);

a=(int **) malloc (sizeof (int) * n);
	for(i=0;i<n;i++)
	a[i]=(int *) malloc ( sizeof(int) * n);


printf("Enter the adjacency matrix\n");
for(i = 0; i < n; i++)
{
	for(j = 0; j < n; j++)
	{
		scanf("%d",&a[i][j]);
	}
}

for(k=0;k<n;k++)

	for (i=0;i<n;i++)

		for(j=0;j<n;j++)

			a[i][j] = a[i][j] || (a[i][k] && a[k][j]);

printf("\n the transitive closure is \n");
for(i = 0; i < n; i++)
{
	for(j = 0; j < n; j++)
	{
		printf("%d\t",a[i][j]);
	}
	printf("\n");
}
getch();
return(0);
}


