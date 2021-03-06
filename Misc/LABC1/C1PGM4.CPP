#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<dos.h>
void mergesort(int a[],int l,int h);
void merge(int a[],int l,int m,int h);
void main()
{
int a[4000],n,i;
clock_t start,end;
clrscr();
randomize();
l:n=rand()%30;
if(n<=1)
goto l;
for(i=0;i<n;i++)
{
a[i]=rand()%4000;
}
//printf("\n Array before sort \n");
//for(i=0;i<n;i++)
{
//printf(" %d",a[i]);
}
start=clock();
mergesort(a,0,n-1);
delay(200);
end=clock();
//printf("\n Array after sort \n");
//for(i=0;i<n;i++)
{
//printf(" %d",a[i]);
}
printf("\nTime required to sort %d elements=%lf",n,(end-start)/CLK_TCK);
getch();
}

void mergesort(int a[],int l,int h)
{
int m;
 if(l<h)
 {
   m=(l+h)/2;
   mergesort(a,l,m);
   mergesort(a,m+1,h);
   merge(a,l,m,h);
 }
}
void merge(int a[],int l,int m,int high)
{
 int h,i,j,k,b[4000];
 h=l;
 i=l;
 j=m+1;
 while(h<=m&&j<=high)
 {
     if(a[h]<=a[j])
     {
      b[i]=a[h];
      h=h+1;
     }
       else
       {
	b[i]=a[j];
	j++;
       }
	i++;
 }
	  if(h>m)
	  {
	  for(k=j;k<=high;k++)
	   {
	    b[i]=a[k];
	    i++;
	   }
	  }
	else
	  {
	   for(k=h;k<=m;k++)
	   {
	   b[i]=a[k];
	   i++;
	   }
	  }
	  for(k=l;k<=high;k++)
	  {
	  a[k]=b[k];
	  delay(1);
	  }
	  return;
}