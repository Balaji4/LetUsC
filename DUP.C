#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
	char s[20],a[20]={'\0'};
	int i,j,l,flag=0,k=0;
	printf("\nEnter string: ");
	gets(s);
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		for(j=0;j<i+1;j++)
		{
			if(s[i]==a[j])
			{
				flag=1;
				break;
			}
			if(flag==0)
			a[k++]=s[i];
		}
	}
	puts(a);
	getch();
}