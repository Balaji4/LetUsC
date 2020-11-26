#include<stdio.h>
#include<conio.h>
#include<time.h>
int n,m,v[10][10],p[10],w[10];
void read();
void opt();
void write();

void read()
{
int i;
printf("Enter the number of objects\n");
scanf("%d",&n);
printf("Enter the weights of the objectd\n");
for(i=1;i<=n;i++)
scanf("%d",&w[i]);
printf("enter the profits of the objects\n");
for(i=1;i<=n;i++)
scanf("%d",&p[i]);
printf("enter the capacity of knapsack\n");
scanf("%d",&m);
}

void write()
{
int i,j,x[10];
printf("output is\n");
for(i=0;i<=n;i++)
{
 for(j=0;j<=m;j++)
 {
  printf(" %d",v[i][j]);
 }
 printf("\n");
}
printf("optimal solution is %d\n",v[n][m]);
for(i=0;i<n;i++)
{
x[i]=0;
}
i=n;
j=m;
while(i!=0&&j!=0)
{
if(v[i][j]!=v[i-1][j])
 {
 x[i]=1;
 j=j-w[i];
 }
 i=i-1;
 }
 for(i=1;i<=n;i++)
 {
 printf("X[%d]",i);
 }
 printf("=");

 for(i=1;i<=n;i++)
 {
 printf(" %d",x[i]);
 }
}
 int max(int a,int b)
 {
 return a>b?a:b;
 }
 void opt()
 {
 int i,j;
 for(i=0;i<=n;i++)
 {
  for(j=0;j<=m;j++)
  {
  if(i==0||j==0)
   v[i][j]=0;
   else if(j<w[i])
   v[i][j]=v[i-1][j];
   else
   v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
   delay(1);
   }}}


 void main()
{
clock_t e,s;
clrscr();


read();
s=clock();
opt();
write();
e=clock();
printf("\nTime=%lf",(e-s)/CLK_TCK);
getch();
}