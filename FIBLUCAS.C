#include<stdio.h>
#include<conio.h>
int fib(int,int,int);
void main()
{
int i,n,m,j,ch;
l:clrscr();
printf("\n 1:Generate fibonacci series");
printf("\n 2:Generate lucas series");
printf("\n 3:exit");
printf("\n\n enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("\n How many number of fiboncci series you want?\n");
       scanf("%d",&m);
       printf("\n fibonacci series upto %d numbers is as follows\n",m);
       for(i=1;i<=m;i++)
       {
	printf("\t%d",fib(i,0,1));
       }
       break;
case 2:printf("\n How many number of lucas series you want?\n");
       scanf("%d",&n);
       printf("\n lucas series upto %d numbers is as follows\n",n);
       for(j=1;j<=n;j++)
       {
       printf("\t%d",fib(j,2,1));
       }
       break;
case 3:exit(1);
default:printf("\n invalid choice entered\n");
	break;
}
getch();
goto l;
}

int fib(int n,int s1,int s2)
{
if(n==1)
return s1;
else if(n==2)
return s2;
else return(fib((n-1),s1,s2)+fib((n-2),s1,s2));
}