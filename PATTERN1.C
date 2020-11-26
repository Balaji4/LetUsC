#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include<stdlib.h>
void main()
{
 int dr,md,midx,i, midy,dx,dy,mx, my,k,x,y,ax[100], ay[100];
 int nx[100], ny[100];
 double pi,tpi,a,t;
 dr = DETECT;

 initgraph(&dr, &md, "");
 midx = getmaxx()/2; midy = getmaxy()/2;
 pi = 3.14159;
 tpi = pi * 2.0;
 k=0;
 for (a = 0.0; a<=tpi; a=a+pi/2)
 {
  x = 550 + 70 * cos(a);
  y = 200 + 70 * sin(a);

  setcolor(random(getmaxcolor()));
  putpixel(x,y,random(getmaxcolor()));
  ax[k] = x;
  ay[k] = y;
  k++;
 }



 for (a=0.0; a<=tpi; a=a+pi/50)
 {
  for (i=0; i<k; i++)
  {
  nx[i]=((ax[i]-midx)*cos(a)) - ((ay[i]-midy)*sin(a)) + midx ;
  ny[i]=((ax[i]-midx)*sin(a)) + ((ay[i]-midy)*cos(a)) + midy;
  if (i==0)
  {
   dx = nx[i]; dy = ny[i];
  }
  else
  {
   line (nx[i],ny[i], dx,dy);
   dx=nx[i]; dy = ny[i];
  }
  }
  getch();

 }


 getch();
}
