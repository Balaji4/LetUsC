#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<dos.h>
#define PI 3.1415

float startangle,endangle,a[500];
int x,y,i;
int can_draw(float theta)
{
if((theta>=startangle) && (theta<=endangle))
return 1;
return 0;
}

void circle_points(int x,int y,int xc,int yc)
{
float theta;
theta= atan((float)y/x);
theta=theta*(180/PI);
a[i++]=theta;
if (can_draw(theta))
	putpixel(xc+x,yc-y,WHITE);
if (can_draw(360-theta))
	putpixel(xc+x,yc+y,WHITE);
if (can_draw(90-theta))
	putpixel(xc+y,yc-x,WHITE);
if (can_draw(270+theta))
	putpixel(xc+y,yc+x,WHITE);
if (can_draw(180-theta))
	putpixel(xc-x,yc-y,WHITE);
if (can_draw(180+theta))
	putpixel(xc-x,yc+y,WHITE);
if (can_draw(90+theta))
	putpixel(xc-y,yc-x,WHITE);
if (can_draw(270-theta))
	putpixel(xc-y,yc+x,WHITE);
}
void midpoint(int xc,int yc,int rad)
{
float d=(5/4)-rad;
x=0,y=rad;
while(y>x)
{
if(d<0)
d+=2*x+3;
else
{
d+=(2*x)-(2*y)+5;
y--;
}
x++;
circle_points(x,y,xc,yc);
}
}
void main()
{
int gd=DETECT,gm;
int radius,xc,yc,choice,temp;
float xstart,ystart,xend,yend;
initgraph(&gd,&gm,"C://TC//BGI");
clrscr();
cleardevice();
printf("Enter your choice\n");
printf("\n 1. Draw a circle\n 2.Draw a sector\n 3.Draw a arc\n4.Exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1:	printf("Enter the center\n");
	scanf("%d%d",&xc,&yc);
	printf("\n Enter the radius\n");
	scanf("%d",&radius);
	cleardevice();
	startangle=0;endangle=360;
	midpoint(xc,yc,radius);
	getch();
	break;

case 2:  printf("Enter the center\n");
	scanf("%d%d",&xc,&yc);
	printf("\n Enter the radius\n");
	scanf("%d",&radius);
	printf("Enter the startangle\n");
	scanf("%f",&startangle);
	printf("Enter the endangle\n");
	scanf("%f",&endangle);
	cleardevice();
	if(startangle>endangle)
	{
	temp=startangle;
	startangle=endangle;
	endangle=temp;
	}
	midpoint(xc,yc,radius);
	xstart=xc+radius * cos(PI*startangle/180);
	ystart=yc-radius*sin(PI*startangle/180);
	xend=xc+radius*cos(PI*endangle/180);
	yend=yc-radius*sin(PI*endangle/180);
	line(xc,yc,xstart,ystart);
	line(xc,yc,xend,yend);
	getch();
	break;

case 3: printf("Enter the center\n");
	scanf("%d%d",&xc,&yc);
	printf("\n Enter the radius\n");
	scanf("%d",&radius);
	printf("Enter the startangle\n");
	scanf("%f",&startangle);
	printf("Enter the endangle\n");
	scanf("%f",&endangle);
	cleardevice();
	if(startangle>endangle)
	{
	temp=startangle;
	startangle=endangle;
	endangle=temp;
	}
	midpoint(xc,yc,radius);
	getch();
	break;

case 4: closegraph();
}
for(i=0;i<20;i++)
printf("%f\t",a[i]);
getch();
}