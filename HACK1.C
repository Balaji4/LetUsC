#include<stdio.h>
#include<conio.h>
int main()
{
int i,j,mat[10][10],wt[10][10],n,m,k;
clrscr();
printf("n m k");
scanf("%d%d%d",&n,&m,&k);
printf("elements of mat\n");
for(i=0;i<n;i++)
 {
 for(j=0;j<m;j++)
  {
  scanf("%d",&mat[i][j]);
  }
 }
 printf("elements of weight\n");
for(i=0;i<n;i++)
 {
 for(j=0;j<m;j++)
  {
  scanf("%d",&wt[i][j]);
  }
 }
w=select(mat,wt,n,m,k);
getch();
return 0;
}

int select(int mt[][10],int wg[][10],int n,int m,int k)
{
int count,i,j;
for(i=0;i<n;i++)
 {
 for(j=0;j<m;++j)
 {

 }
}