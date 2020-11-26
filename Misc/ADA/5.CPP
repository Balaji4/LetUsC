#include<stdio.h>
#include<conio.h>
void main()
{
float b=10.2;
int a;
int c,d;
clrscr();
a=(int)b;
c=int(b);
d=(int)(b);
printf("%d %f %d %d",a,b,c,d);
getch();
}