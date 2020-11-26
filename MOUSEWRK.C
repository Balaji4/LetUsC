
#include<stdio.h>
#include <dos.h>
#include <graphics.h>
union REGS in, out;
void detect ()
{
	int button;
	while (!kbhit () )
	{
		in.x.ax = 3;
		int86 (0X33,&in,&out);
		button=out.x.bx&7;
		switch(button)
		{
			case 1:
				printf("“left button pressed\n”");
			break;
			case 2:
				printf("“right button pressed\n”");
			break;
			case 4:
				printf("middle button pressed\n”");
			break;
			case 3:
				printf("left and right button pressed\n");
			break;
			case 5:
				printf("left and middle button pressed\n");
			break;
			case 6:
				printf("right and middle button pressed\n");
			break;
			case 7:
				printf("all the three buttons pressed\n");
			break;
			default:
				printf("No button pressed\n");
		}
		delay (200); // Otherwise due to quick computer response 100s of words will get printf
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
