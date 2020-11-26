#include<stdio.h>
#include<conio.h>
void sort(int*,int);
void main()
{
int i,j,a[20],b[10]={0,0,0,0,0},n,count=0,d,c[10]={0,0,0,0,0,0,0,0,0,0};
d=0;
clrscr();
printf("\n how many values?\n");
scanf("%d",&n);
printf("\nenter %d numbers\n",n);
 for(i=0;i<n;i++)
 {
 scanf("%d",&a[i]);
 }
 sort(a,n);
 printf("\n numbers that are repeated are\n");
	  j=0;
  for(i=0;i<n;i++)
  {     d=0;
    if(a[i]==a[i+1])
    {
     printf("\t%d",a[i]);
       b[j]=a[i];
       count++;
       j++;
       d++;
    }
     c[j]=d;
   }
   for(i=0;i<count;i++)
   {
   printf("\n%d is repeated %d times" ,b[i],c[i]+2);
   }
   printf("\n repeated numbers are=%d",count);
  getch();
}
  void sort(int *k,int m)
  {
   int i,j,t;
   for(i=0;i<=m-1;i++)
   {
     for(j=0;j<m-1;j++)
      {
	if(*(k+i)<*(k+j))
	{
	t=*(k+i);
	*(k+i)=*(k+j);
	*(k+j)=t;
	}
       }
      }
     }