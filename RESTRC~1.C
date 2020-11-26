#include <dos.h>
#include <graphics.h>
union REGS in, out;
void restrict (int x1,int y1,int x2, int y2)
{
	in.x.ax = 7;
	in.x.cx = x1;
	in.x.dx = x2;
	int86 (0X33,&in,&out);
	in.x.ax = 8;
	in.x.cx = y1;
	in.x.dx = y2;
	int86 (0X33,&in,&out);
}
int main ()
{
       //	detect_mouse ();
       //	showmouse_text ();
	restrict (10,0,250,50); // Change values here to create different mouse movement space.
       //	detect ();
       //	hide_mouse ();
	getch ();
	return 0;
}