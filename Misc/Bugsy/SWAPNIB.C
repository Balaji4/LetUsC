#include<stdio.h>
#include<conio.h>
unsigned char swapnibble(unsigned char c)

{

  unsigned char a, b;

  a = c & 0x0F;

  b = c & 0xF0;

  a=a <<4;
  b=b >> 4;

  return(a|b); //adding the bits

}

void main()
{
unsigned char c=2,d;
clrscr();
d=swapnibble(c);
printf("c=%d d=%d",c,d);
getch();
}