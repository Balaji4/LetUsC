#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
#include<ctype.h>
#define maxrow 19
#define maxcol 38
#define minrow 3
#define mincol 6
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

int rw=4;
struct menuop
{
char op[20];
int posy;
}s[4];

void mfn();
char   getkey()
{
union REGS i,o;
//while(!kbhit())
//;
i.h.ah=0;
int86(22,&i,&o);
return(o.h.ah);
}
void main()
{
char ch;
int i;
clrscr();
_setcursortype(_NOCURSOR);
strcpy(s[0].op,"1: Launch Game\0");
strcpy(s[1].op,"2: Game Settings\0");
strcpy(s[2].op,"3: High Scores\0");
strcpy(s[3].op,"4: Exit\0");

s[0].posy=4;
s[1].posy=6;
s[2].posy=8;
s[3].posy=10;

textbackground(BLACK);
textcolor(WHITE);
gotoxy(15,2);
printf("MENU\n");
for(i=0;i<=3;i++)
{
gotoxy(15,s[i].posy);
printf("%s",s[i].op);
}
textcolor(RED);
window(15,rw,40,11);
cprintf("%s",s[0].op);
while(1)
{
ch=getkey();
switch(ch)
{
case 'H': if((rw-2)>=4)
	  {
	  textcolor(WHITE);
	  window(15,rw,40,11);

	 i=index();
	 cprintf("%s",s[i].op);
	  textcolor(RED);
	  rw-=2;
	  window(15,rw,40,11);

	 i=index();
	 cprintf("%s",s[i].op);
	  }//textcolor(BLACK);
	  //clrscr();
	 // window(15,4,40,11);
	 //printf("UP key\n");
	 break;
case 'P':if((rw+2)<=10)
	 {
	 textcolor(WHITE);
	 window(15,rw,40,11);

	 i=index();
	 cprintf("%s",s[i].op);
	 textcolor(RED);
	 rw+=2;
	 window(15,rw,40,11);

	 i=index();
	 cprintf("%s",s[i].op);
	 }//printf("Down key\n");
	 break;
case 'M'://printf("RIGHT key\n");
	 break;
case 'K'://printf("Left key\n");
	 break;
default:mfn();
}
}
}


int index()
{
switch(rw)
{
case 4:return 0;
case 6:return 1;
case 8:return 2;
case 10:return 3;
}
return 0;
}


void mfn()
{
 switch(rw)
 {
 case 4:printf("Launch");
       getch();
       exit(0);
 case 6:printf("game");
       getch();
       exit(0);
 case 8:printf("high");
       getch();
       exit(0);
 case 10:exit(0);
 }
}