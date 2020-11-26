#include<stdio.h>
#include<conio.h>
void spiral(int [][10],int);
void main()
{
int n,a[10][10],i,j;
clrscr();
printf("enter size of matrix\n");
scanf("%d",&n);
printf("\n enter the elements of matrix\n");
for(i=0;i<n;i++)
 {
 for(j=0;j<n;j++)
 {
 scanf("%d",&a[i][j]);
 }
  }
  printf("\nMatrix elements\n");
  for(i=0;i<n;i++)
 {
 for(j=0;j<n;j++)
 {
 printf(" %d ",a[i][j]);
 }
 printf("\n");
  }
  printf("\n matrix in spiral form\n");
spiral(a,n);
getch();
}
void spiral(int m[][10],int n)
{
int i,j,k;
 for(i=n-1,j=0;i>0;i--,j++)
 {       // top row
	for(k=j;k<i;k++)
	 {
	 printf(" %d ",m[j][k]);
	 }

	 //last col
	 for(k=j;k<i;k++)
	 {
	 printf(" %d ",m[k][i]);
	 }
	 //last row
	 for(k=i;k>j;k--)
	 {
	 printf(" %d ",m[i][k]);
	 }
	 //first column
	 for(k=i;k>j;k--)
	 {
	 printf(" %d ",m[k][j]);
	 }
 }
 if(n%2==1)
 {
 //middle  if odd size
 printf(" %d ",m[(n-1)/2][(n-1)/2]);
 }

}
