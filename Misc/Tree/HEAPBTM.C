/* bottom up heap construction and sorting*/
#include<stdio.h>
#include<stdlib.h>
void heapify(int [],int);
void hsort(int [],int);
void main()
{
int n,a[15],i;
clrscr();
printf("\n how many elements \n");
scanf("%d",&n);
printf("\n enter %d elements\n",n);
for(i=1;i<=n;i++)
 {
 scanf("%d",&a[i]);
 }
heapify(a,n);
printf("\n heapified elements\n");
for(i=1;i<=n;i++)
 {
 printf(" %d",a[i]);
 }
hsort(a,n);
printf("\n sorted elements\n");
for(i=1;i<=n;i++)
 {
 printf(" %d",a[i]);
 }
getch();
}

void heapify(int h[],int n)
{
int i,heap=0,j,k,v;
for(i=n/2;i>=1;i--)
 {
 v=h[i];
 k=i;
 heap=0;
  while((!heap)&&(2*k<=n))
  {
  j=2*k;
  if(j<n)
   if(h[j]<h[j+1])
    j=j+1; //second child
  if(v>=h[j])
   heap=1;
  else
   {
   h[k]=h[j];
   k=j;
   }
  }
  h[k]=v;
 }
}

void hsort(int h[],int n)
{
int i;
int temp,len=n;
for(i=len;i>=1;i--)
 {
  temp=h[1];
  h[1]=h[len];
  h[len]=temp;
  len--;

  heapify(h,len);

 }
}