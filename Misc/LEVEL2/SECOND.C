#include<stdio.h>
void main()
{
int n;
system("cls");
//printf("enter a number");
//scanf("%d",&n);
for(n=1;n<10000;n*=10)
printf("%5d%-5d\n",n,n);
getch();
}