#include<stdio.h>
void main()
{
float b=10.2;
int a,c,d;
a=(int)b;
c=(int)(b);
d=int(b);
clrscr();
printf("%d %f %d",a,b,c);
getch();
}