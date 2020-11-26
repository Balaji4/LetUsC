#include<stdio.h>
#include<stdlib.h>
int main()
{
int **c,i,j,n,k,w;
printf("Enter the values of n and k respectively\n");
scanf("%d %d", &n, &k);

c = (int**) malloc(n*sizeof(int*));  
		for (i = 0; i <=n; i++)  
  			 c[i] = (int*) malloc(n*sizeof(int));  



printf("The binomial co-efficient of n and k is :\n");
for (i = 0; i <= n; i++)
{ 
	w = i < k ? i : k;
	for(j = 0; j <= w; j++)
	{
		if (j == 0 || j == i)
			c[i][j] = 1;
		else c[i][j] = c[i-1][j-1] + c[i-1][j];
	}
}

for(i=0;i<=n;i++)
{
for(j=0;j<n;j++)
printf("%d\t",c[i][j]);
printf("\n");
}

printf("%d\n",c[n][k]);

return(0);
}
