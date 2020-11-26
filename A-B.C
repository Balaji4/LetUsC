#include<stdio.h>
void sort(int s[],int n);
void main()
{
int a[10],b[10],i,j,m,n,f=0;
clrscr();
printf("\n How many elements for set A and B\n");
scanf("%d%d",&m,&n);
printf("\n enter the  %d elements of set A\n",m);
for(i=0;i<m;i++)
{
scanf("%d",&a[i]);
}
printf("\n enter the %d elements of set B\n",n);
for(j=0;j<n;j++)
{
scanf("%d",&b[j]);
}
sort(a,m);
printf("\n elements of set A are \n");
for(i=0;i<m;i++)
{
printf("\t%d",a[i]);
}
sort(b,n);
printf("\n elements of set B are\n");
for(j=0;j<n;j++)
{
printf("\t%d",b[j]);
}

printf("\n elements of A-B are\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
if(a[i]==b[j])
{
f=1;
break;
}
}
if(f!=1)
 printf("%d\t",a[i]);
}
getch();
}
void sort(int s[],int n)
{
int i,j,t;

for(i=0;i<n;i++)
{
 for(j=0;j<n-i-1;j++)
 {
   if(s[j]>s[j+1])
   {
   t=s[j];
   s[j]=s[j+1];
   s[j+1]=t;
   }
 }
}
}


