#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
int main()
{
	int gd=DETECT,gm;
	int x,i,j;
	initgraph(&gd,&gm,"l:");
	while(!kbhit())
	{
		j=random(300);
		{
			for(i=0;i<740;i++)
			{
				setcolor(14);
				arc(70+i,180+j,30,180,50);
				arc(70+i,130+j,210,330,50);
				moveto(27+i,155+j);
				lineto(10+i,140+j);
				lineto(10+i,170+j);
				lineto(27+i,155+j);
				circle(95+i,155+j,5);
				setfillstyle(SOLID_FILL,14);
				floodfill(80+i,160+j,14);
				floodfill(15+i,150+j,14);
				setcolor(11);
				circle(130+i,115+j,7);
				circle(133+i,130+j,5);
				circle(130+i,110+j,3);
				setfillstyle(WIDE_DOT_FILL,13);
				floodfill(131+i,156+j,11);
				floodfill(134+i,131+j,11);
				floodfill(137+i,11+j,11);
				delay(10);
				cleardevice();
			}
		}
	}
	closegraph();
	return 0;
}