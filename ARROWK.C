#include<stdio.h>
#include<conio.h>
#include<dos.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
char   getkey()
{
union REGS i,o;
while(!kbhit())
;
i.h.ah=0;
int86(22,&i,&o);
return(o.h.ah);
}

void main()
{
char ch;
clrscr();
ch=getkey();
//printf("%c",ch);
switch(ch)
{
case 'H':printf("UP key\n");
	 break;
case 'P':printf("Down key\n");
	 break;
case 'M':printf("RIGHT key\n");
	 break;
case 'K':printf("Left key\n");
	 break;
default:printf("not working \n");
}
getch();
}

/*#include <conio.h>

int main(void)
{
   cprintf("Press any key to continue:");
   while (!kbhit()) /* do nothing
   {
   printf("--");
   }
   cprintf("\r\nA key was pressed...\r\n");
   return 0;
} */
