#include <dos.h>
#include <graphics.h>

union REGS in, out;
void detect ()
{
	while (!kbhit () )
	{
		int x,y;
		in.x.ax = 3;
		int86 (0X33,&in,&out);
		if (out.x.bx == 1)
		{
			x = out.x.cx;
			y = out.x.dx;
			printf ("\nLeft || X - %d  Y - %d", x, y);
		}
		delay (200); // Otherwise due to quick computer response 100s of words will get print
	}
}

int main ()
{
      //	detect_mouse ();
       //	showmouse_text ();
	detect ();
       //	hide_mouse ();
	getch ();
	return 0;
}