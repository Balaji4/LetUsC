#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include <graphics.h>

void theend();

static int mask[]={/*SCREEN MASK*/
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,
/*CURSOR MASK*/
0x0000,0x0000,0x381c,0x7c3e,0x7c3e,0x7c3e,0x7c3e,
0x3bdc,0x07e0,0x0ff0,0x0ff0,0x0ff0,0x0ff0,0x07e0,
0x03c0,0x0000};


void main()
{int gdriver=DETECT,gmode,buttons;
union REGS regs;
struct SREGS sregs;
initgraph(&gdriver,&gmode,"");
regs.x.ax=0; /*INITIALIZE MOUSE*/
int86(0x33,&regs,&regs);
setcolor(LIGHTCYAN);
if(regs.x.ax==0)
{outtextxy(0,0,"NO MOUSE AVAILABLE");
getch();
theend();
}
regs.x.ax=9; /*CHANGE CURSOR SHAPE*/
regs.x.bx=5;
regs.x.cx=0;
regs.x.dx=(int)mask;
segread(&sregs);
sregs.es=sregs.ds;
int86x(0x33,&regs,&regs,&sregs);
regs.x.ax=1; /*SHOW MOUSE POINTER*/
int86(0x33,&regs,&regs);
do
{regs.x.ax=3;
int86(0x33,&regs,&regs);
buttons=regs.x.bx & 3;
}while(buttons!=3);
regs.x.ax=2; /*HIDE MOUSE POINTER*/
int86(0x33,&regs,&regs);
theend();
}

void theend()
{closegraph();}




