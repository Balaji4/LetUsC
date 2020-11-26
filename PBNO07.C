
#include<stdio.h>
#include<string.h>
void reverse(int *,int);
int d2b(int,int []);
void display(int [],int);
void change(int m[],int n[],int c1,int c2,int i,int j);
void main()
{
int n1,n2,m[32],n[32],i,j,k,l,c1,c2,max,min,cg;
printf("enter 2 decimal numbers\n");
scanf("%d%d",&n1,&n2);
if(n1>10000||n1<0||n2>10000||n2<0)
{
printf("\n inputs not in the range\n");
exit(0);
}
c1=d2b(n1,m);
 reverse(m,c1);
c2=d2b(n2,n);
reverse(n,c2);

 max=c1>c2?c1:c2;
 min=c1<c2?c1:c2;

if(c1>32||c2>32)
{
printf("\n length of equivalent binary is >32");
exit(0);
}
 printf("\n M=");
 display(m,c1);
 printf("\n\n N=");
 display(n,c2);
 printf("\n enter the 'lower' and 'upper' bit positions \n");
 scanf("%d%d",&i,&j);
 if(i>c1&&i<0&&j>c2&&j<i)
 {
 printf("\n Unacceptable range\n");
 exit(0);
 }


 if((j-i)<min)
 {
 printf("\n acceptable\n");

 if(c2==max)
 change(m,n,c1,c2,i,j);
 else
 change(n,m,c2,c1,i,j);
 display(m,c1);
 printf("\n");
 display(n,c2);
 }
 else printf("\n unacceptable i & j");
 }

 int d2b(int m,int bn[])
 {
 int i=0,r,c=0;
 while(m!=0)
 {
  r=m%2;
  m=m/2;
 bn[i]=r;
 i++;
 c++;
 }
 return c;
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



void display(int r[],int size)
{
int k;
  for(k=0;k<size;k++)
 {
 printf("%d",r[k]);
 }
}


void change(int m[],int n[],int c1,int c2,int i,int j)
{
int k,l=0;
 for(k=0;k<c2;k++)
 {
  if(k==i)
  {

   while(i<=j)
   {
   n[i]=m[l];
    l++;
   i++;
   }
   break;
  }
}
}
