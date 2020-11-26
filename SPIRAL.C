#include<stdio.h>
#include<conio.h>
void spiral(int [][10],int,int);
void main()
{
int row,col,a[10][10],i,j;
clrscr();
printf("enter size of matrix\n");
scanf("%d %d",&row,&col);
printf("\n enter the elements of matrix\n");
for(i=0;i<row;i++)
 {
 for(j=0;j<col;j++)
 {
 scanf("%d",&a[i][j]);
 }
  }
  printf("\nMatrix elements\n");
  for(i=0;i<row;i++)
 {
 for(j=0;j<col;j++)
 {
 printf(" %d ",a[i][j]);
 }
 printf("\n");
  }
  printf("\n matrix in spiral form\n");
spiral(a,row,col);
getch();
}
void spiral(int m[][10],int row,int col)
{
int i,j,k;
 for(i=row-1,j=0;i>0;i--,j++)
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
 if(row%2==1)
 {
 //middle  if odd size
 printf(" %d ",m[(row-1)/2][(col-1)/2]);
 }

}
