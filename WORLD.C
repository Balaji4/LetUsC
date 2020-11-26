#include<stdio.h>
#include<conio.h>
#include<dos.h>
int a[3][11]={{6,6,6,6,6,6,7,8,9,10,15},{5,5,5,5,5,5,7,8,9,13,16},{5,6,7,9,10,11,12,13,14,15,16}};
void main()
{
int ch=254,r=0,c=0,i,j,k;
clrscr();
for(i=0;i<50;i++)
{
 r=0;
for(j=0;j<16;j++)
{
if(r<=2)
{
for(c=0;c<11;c++)
{
gotoxy(j,a[r][c]);      //a[r][c]->row
printf("%c",ch);
}
r++;
}
}
delay(1000);
clrscr();
}
getch();
}
