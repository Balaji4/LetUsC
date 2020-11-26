#include<stdio.h>
#include<conio.h>

int posX, posY, posKlik;

void show_mouse(void)
{
   asm{
      mov ax,1h
      int 33h
   }
}

void set_mouse(void)
{
   asm{
      mov ax,4h
      mov cx,0
      mov dx,479
      int 33h
   }
}

void read_mouse(void)
{
   asm{
      mov ax,3h
      int 33h
      mov posX,cx // posX posisi X Mouse
      mov posY,dx // posY posisi Y Mouse
      mov posKlik,bx // posKlik keadaan Mouse, saat diklik atau tidak, dan tombol mana yang diklik
   }
}
void main()
{
clrscr();
_setcursortype(_NOCURSOR);
show_mouse();
set_mouse();
read_mouse();
gotoxy(posX,posY);
getche();
}