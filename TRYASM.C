#include<dos.h>
#include<stdio.h>
union regs in,out;
void main()
{
asm
{
mov ax,08h
}
getch();
}