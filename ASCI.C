#include<stdio.h>
#include<conio.h>
void main()
{
int ch;
clrscr();
printf("ASCII set\n");
for(ch=0;ch<=255;ch++)
printf(" %d %c",ch,ch);

getch();
}