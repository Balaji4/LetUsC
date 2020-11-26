#include<stdio.h>
#include<conio.h>
void main()
{
int i;
clrscr();
for(i=1;i<=5;i+=2)
{
printf("%.*s\n",i,"*****");
}
for(i=5;i>0;i-=2)
{
printf("%.*s\n",i,"*****");
}
getch();
}