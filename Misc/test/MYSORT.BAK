/* my sort */
#include<stdio.h>
#include<stdlib.h>
void mysortalgo(int[],int);
void print(int [],int);
void main()
{
int n,i,a[20];
randomize();
clrscr();
printf("\n how many elements \n");
scanf("%d",&n);
//n=rand()%15;
printf("\n enter %d elements\n",n);
for(i=0;i<n;i++)
 {
 scanf("%d",&a[i]);
// a[i]=rand()%1000;
 }
mysortalgo(a,n);
printf("\n sorted elements\n");
for(i=0;i<n;i++)
 {
 printf(" %d",a[i]);
 }
getch();
}

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
       printf("\n big=%d small=%d b=%d s=%d f=%d, l=%d",big,small,b,s,f,l);
       print(a,n);
	}
}
void print(int b[],int n)
{
int i;
for(i=0;i<n;i++)
 {
 printf(" %d",b[i]);
 }
}
