#include<stdio.h>
#include<conio.h>
#include<math.h>
void reverse(int *z,int c);
void dectobin(int a[],int n);
void gensubset(int);
void knap(int [],int);
int item[10],w[10];
void main()
{
int max,n,i;
clrscr();
printf("\n how many items \n");
scanf("%d",&n);
printf("\n enter value and weight of each item\n");
for(i=0;i<n;i++)
{
scanf("%d%d",&item[i],&w[i]);
}
printf("\n Enter max weight of knapsack \n");
scanf("%d",&max);
gensubset(n);
getch();
}

void gensubset(int n)
{
int i,p,a[10][10];
p=pow(2,n);
printf("\n\t SUBSETS \n");
for(i=0;i<p;i++)
{
dectobin(a[i],i);
}

}




void dectobin(int a[],int n)
{
int r,i,c=0;
 i=0;
 if(n==0)
  {
 a[0]=0;
 c=1;
 goto l;
 }
 while(n!=0)
 {
  r=n%2;
  n=n/2;
 a[i]=r;
 i++;
 c++;
 }
 reverse(a,c);
 l://printf("\n its equivalent binary number is ");
 for(i=0;i<c;i++)
 {
 printf(" %d",a[i]);
 }
 knap(a,c);
 printf("\n");
 getch();
 }

 void reverse(int *z,int c)
 {
 int *q,t;
 q=z+c-1;
 while(q>z)
 {
 t=*z;
 *z=*q;
 *q=t;
 z++;
 q--;
 }
}

void knap(int b[],int c)
{
int i,tw,tv;
for(i=0;i<c;i++)
{

tw+=b[i]*w[i];
tv+=b[i]*item[i];
}

printf("\n total wt=%d  total value=%d",tw,tv);

}