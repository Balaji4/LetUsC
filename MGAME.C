#include<stdio.h>
#include<conio.h>
#include<dos.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

int row=24,col=1;
char   getkey()
{
union REGS i,o;
while(!kbhit())
;
i.h.ah=0;
int86(22,&i,&o);
return(o.h.ah);
}
void map()
{
int i;
for(i=1;i<=80;i++)
{
gotoxy(i,25);
printf("_");
}
}
void moveup()
{
int i,j;
for(i=row;i>(row-10);i--)
{
gotoxy(col,i);
printf("%c",1);
delay(100);

clrscr();
map();
}
i--;
for(;i<=row;i++)
{
gotoxy(col,i);
printf("%c",1);
delay(100);
clrscr();
map();
}
gotoxy(col,row);
printf("%c",1);
}

void moveright()
{
clrscr();
map();
col++;
if(col==80)
col=1;
gotoxy(col,row);
printf("%c",1);
}

void moveleft()
{
clrscr();
map();
if(col==1)
{
return;
}
col--;
gotoxy(col,row);
printf("%c",1);
}

void movedown()
{
}


void main()
{
char ch,ob=1;
clrscr();
_setcursortype(_NOCURSOR);
map();
gotoxy(col,row);
printf("%c",1);
while(1)
{
ch=getkey();

//printf("%c",ch);
switch(ch)
{
case 'H':moveup();
	 //printf("UP key\n");
	 break;
case 'P':movedown();//printf("Down key\n");
	 break;
case 'M':moveright();
	 //printf("RIGHT key\n");
	 break;
case 'K':moveleft();//printf("Left key\n");
	 break;
case 'l':exit(0);
default://printf("not working \n");
	exit(0);
}
}
}