#include<stdio.h>
void main()
{
unsigned int a;
int i;
clrscr();
printf("\nenter a number\n");
scanf("%u",&a );
for(i=0;i<16;i++)
{

printf("%d",(a<<i&1<<15)?1:0);
}
}