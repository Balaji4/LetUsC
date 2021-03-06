/* my sort */
#include<stdio.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<dos.h>
void mergesort(int a[],int l,int h);
void merge(int a[],int l,int m,int h);
void mysortalgo(int[],int);
void main()
{
int a[4000],n,i,b[4000];
clock_t start,end,mystart,myend;
clrscr();
randomize();
l:n=rand()%30;
if(n<=1)
goto l;
for(i=0;i<n;i++)
{
b[i]=a[i]=rand()%4000;
}
printf("\n Array before sort \n");
for(i=0;i<n;i++)
{
printf(" %d",a[i]);
}
start=clock();
mergesort(a,0,n-1);
delay(200);
end=clock();
printf("\n Array after sort \n");
for(i=0;i<n;i++)
{
printf(" %d",a[i]);
}
printf("\nTime required to sort %d elements=%lf",n,(end-start)/CLK_TCK);
getch();
mystart=clock();
mysortalgo(b,n);
delay(200);
myend=clock();
printf("\n Array after sort by my algorithm\n");
for(i=0;i<n;i++)
{
printf(" %d",b[i]);
}
printf("\nTime required to sort %d elements by mysort=%lf ",n,(myend-mystart)/CLK_TCK);
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

/*void main()
{
int n,i,a[20];
clrscr();
printf("\n how many elements \n");
scanf("%d",&n);
printf("\n enter %d elements\n",n);
for(i=0;i<n;i++)
 {
 scanf("%d",&a[i]);
 }
mysortalgo(a,n);
printf("\n sorted elements\n");
for(i=0;i<n;i++)
 {
 printf(" %d",a[i]);
 }
getch();
}
*/

     void mysortalgo(int a[],int n)
{
int i,small,j,temp,big,f=0,l=n-1,b=0,s=0,index;
for(i=f;i<=l;i++)
	{
	small=a[i];
	big=a[i];
	b=0;
	s=0;
	for(j=f;j<=l;j++)
	{
       if(a[j]<=small&&b!=1)
	  {
	  small=a[j];
	  index=j;
	  s=1;
	  b=0;
	  }
       else if(a[j]>big&&s!=1)
	  {
	   big=a[j];
	   index=j;
	   b=1;
	   s=0;
	   }
	}
	if(s==1)
	{
	temp=a[f];
	a[f]=small;
	a[index]=temp;
	f++;
	}
       else if(b==1)
       {
	temp=a[l];
	a[l]=big;
	a[index]=temp;
	l--;
       }

	}
}