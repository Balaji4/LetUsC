#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include<stdlib.h>
void main()
{
 int dr,md,midx, midy, mx, my,i,j,k,x,y,x1,y1;
 double pi,tpi,a,t;
 dr = DETECT;


 initgraph(&dr, &md, "c:\\tc\\bgi");
 midx = getmaxx()/2; midy = getmaxy()/2;
 pi = 3.14159;
 tpi = pi * 2.0;
 t=100;

for (t = 0; t < 40 * 5; t += .1)
{
  x = midx+ (t+t * cos(t));
  y = midy+ (t * sin(t));
  x1 = midx+ (t * cos(t));
  y1 = midy+ (t+t * sin(t));
  putpixel(x,y,random(getmaxcolor()));
  putpixel(x1,y1,random(getmaxcolor()));

  setcolor(random(getmaxcolor()));
  if (t==0.0)
  circle(x,y,50);

  if (kbhit()) break;
}


 getch();

}
