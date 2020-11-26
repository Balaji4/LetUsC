#include<stdio.h>
#include<conio.h>
void main()
{
int a[20],n,i,j,s[20],count[20];
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
	for(i=0;i<n;i++)
	{
	count[i]=0;
	}

	for(i=0;i<n-1;i++)
	 {
	  for(j=i+1;j<n;j++)
	  {
	  if(a[i]<a[j])
	  {
	  count[j]++;
	  }
	  else
	  {
	  count[i]++;
	  }
	}
      }
      for(i=0;i<n;i++)
      s[count[i]]=a[i];
printf("\n Array after sort \n");
for(i=0;i<n;i++)
{
printf(" %d",s[i]);
}
getch();
}