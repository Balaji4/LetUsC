#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
void dda(int x1,int y1,int x2,int y2);
void swap(double *a,double *b)
{
double temp=*a;
*a=*b;
*b=temp;
}
void swap(int *a,int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}
void main()
{
int gd=DETECT,gm,x1,y1,x2,y2;
initgraph(&gd,&gm,"");
printf("\n enter co-ordinates of line in order x1 y1 x2 y2\n");
scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
cleardevice();
dda(x1,y1,x2,y2);
getch();
closegraph();
}
void dda(int x1,int y1,int x2,int y2)
{
double x,y=y1;
double dx=x2-x1;
double dy=y2-y1;
int slopef=(dy>dx);
if(slopef)
{
swap(&x1,&x2);
swap(&y1,&y2);
swap(&dx,&dy);
}
double m=dy/dx;
//double d=2*dy,e=2*dy,ne=2*(dy-dx);
if(x2<x1)
{
swap(&x1,&x2);
swap(&y1,&y2);
}
if(y2>y1&&m<0)
{
m=abs(m);
}
else if(y2<y1&&m>=0)
{
m=-m;
}
for(x=x1;x<=x2;x++)
{
putpixel(x,y,WHITE);
y+=m;
}
}

