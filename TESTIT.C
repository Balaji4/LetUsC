#include<stdio.h>
#define max(x) ((x)*(x))

main()

{
 float s=10,u=30,t=2,a,b,c,d;
clrscr();

b=max(t);

c=2*(s-u*t);

d=c/b;

a=2*(s-u*t)/(max(t));

printf("\n %f \t %f \t %f \t %f ",a,b,c,d);
//printf("\n %d \t %d \t %d \t %d ",a,b,c,d);
getch();
return 0;
}