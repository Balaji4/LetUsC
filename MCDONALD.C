#include<graphics.h>
#include<stdio.h>
struct block
{
int left,top,right,bottom;
};
void main()
{
int gdriver=DETECT,gmode,i,j=0;
struct block b[2];
for(i=0;i<2;i++)
{
b[i].left=0+j;
b[i].top=0;
b[i].right=180+j;
b[i].bottom=200;
j=200;
}
initgraph(&gdriver,&gmode,"");
for(i=0;i<2;i++)
{
rectangle(b[i].left,b[i].top,b[i].right,b[i].bottom);
}
rectangle(0,450,635,470);
textcolor(BLACK);
textbackground(WHITE);
cprintf("This is a test\r\n");
getch();
closegraph();
}