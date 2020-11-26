#include<stdio.h>
#include<conio.h>
int modeelem(int a[],int n);
void main()
{
int a[20],n,i,j,temp,m;
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
	for(i=1;i<n;i++)
	{
	 for(j=1;j<=n-i;j++)
	 {
		if(a[j-1]>a[j])
		{
		temp=a[j-1];
		a[j-1]=a[j];
		a[j]=temp;
		}
	 }
	}
printf("\n Array after sort \n");
for(i=0;i<n;i++)
{
printf(" %d",a[i]);
}
m=modeelem(a,n);
printf("\n Mode element=%d",m);
getch();
}

int modeelem(int a[],int n)
{
int i,runval,runlen,modefreq,modeval;
i=0;
modefreq=0;
while(i<=n-1)
{
runlen=1;
runval=a[i];
 while((i+runlen<=n-1)&&a[i+runlen]==runval)
 {
 runlen++;
 }
 if(runlen>modefreq)
 {
 modefreq=runlen;
 modeval=runval;
 }
 i=i+runlen;
}
return modeval;
}