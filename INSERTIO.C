#include<stdio.h>
#include<conio.h>
void main()
{
int a[20],n,i,j,v;
clrscr();
printf("\n  How many elements \n");
scanf("%d",&n);
printf("\n Enter %d elements \n",n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("\n Array before sort \n");
for(i=0;i<n;i++)
{
printf(" %d",a[i]);
}
	for(i=1;i<=n-1;i++)
	{
	v=a[i];
	 j=i-1;
	 while(j>=0&&a[j]>v)
	 {
		a[j+1]=a[j];
		j=j-1;
	 }
		a[j+1]=v;


	}

printf("\n Array after sort \n");
for(i=0;i<n;i++)
{
printf(" %d",a[i]);
}
getch();
}