#include<stdio.h>

int main()
{
char a=127;
int b;
a+=128;
b=a;
if(0>b)
printf("Stm1");
else if(0<b)
printf("Stm2");
}