#include<stdio.h>
#include<conio.h>
#include<dos.h>
void main()
{
int ch=186,ch2=177,x=25,y=38,i,j;
clrscr();
for(j=1;j<25;j+=2)
{
 clrscr();
 gotoxy(2,j);
printf("%c",ch);
gotoxy(78,j);

//printf("%c",ch);
gotoxy(y,x);

//printf("%c",ch2);
delay(100);
for(i=0;i<25;i+=2)
{

gotoxy(78,i);
printf("%c",ch);
gotoxy(2,i);
printf("%c",ch);
delay(100);

}
}
getch();
}