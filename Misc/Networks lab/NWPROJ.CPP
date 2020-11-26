#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>
#define MAXNODES 10
int count=1;
class node
{
public:
int x,y;
int id,clustid;
int ishead;// 0 no head, 1 head of cluster 1,2->head of cluster 2
node()
{
id=count;
count++;
}
/*node(int a,int b)
{
x=a;
y=b;
} */
void draw();
void walk(int a,int b);

};

void findhead(node[]);
void node::draw()
{
setcolor(RED);
//circle(x,y,5);
if(clustid==1&&ishead==1)//(x>=5&&x<=250&&y>=5&&y<=200&&id==10) //cluster 1 head
setfillstyle(1,GREEN);
else if(clustid==2&&ishead==2)//(x>=5&&x<=250&&y>=280&&y<=450&&id==10) //cluster 2 head
setfillstyle(1,CYAN);
else if(clustid==1)//(x>=5&&x<=250&&y>=5&&y<=200) //cluster 1
setfillstyle(1,RED);
else if(clustid==2)//(x>=5&&x<=250&&y>=280&&y<=450) //cluster 2
setfillstyle(1,BLUE);
else
setfillstyle(1,WHITE);  //does not cluster 1 or 2
fillellipse(x,y,10,10);
setcolor(BLACK);
char *pk;
sprintf(pk,"%d",id);
outtextxy(x-2,y-2,pk);
}
void node::walk(int a,int b)
{
x=a;
y=b;
if(x>=5&&x<=250&&y>=5&&y<=200)
clustid=1;
else if(x>=5&&x<=250&&y>=280&&y<=450)
clustid=2;
else
clustid=3;  //does not belong to cluster 1 or 2
}
void findhead(node p[])
{
int min1=MAXNODES+1,min2;
min2=min1;
for(int i=0;i<MAXNODES;i++)
{
if(p[i].clustid==1)
 {
  if(min1>p[i].id)
    {
    min1=p[i].id;
    }
 }
 else if(p[i].clustid==2)
  {
  if(min2>p[i].id)
   {
   min2=p[i].id;
   }
  }
}
for(i=0;i<=MAXNODES;i++)
  {
  if(p[i].id==min1)
  {
  p[i].ishead=1;
  }
  else if(p[i].id==min2)
   {
   p[i].ishead=2;
   }
   else
   p[i].ishead=0;
  }

}

void paint()
{
setcolor(WHITE);
outtextxy(10,10,"Cluster 1");
rectangle(5,5,250,200);
outtextxy(10,290,"Cluster 2");
rectangle(5,280,250,450);
}
void table()
{
line(280,5,280,450);
outtextxy(285,10,"Header Node");
      char *msg;
      sprintf(msg,"Cluster 1 header");//n[i].id);
     setfillstyle(1,GREEN);
     fillellipse(290,40,5,5);
     outtextxy(300,40,msg);
     sprintf(msg,"Cluster 2 header");//n[i].id);
     setfillstyle(1,CYAN);
     fillellipse(290,60,5,5);
     outtextxy(300,60,msg);
     sprintf(msg,"Node outside cluster 1 and 2");//n[i].id);
     setfillstyle(1,WHITE);
     fillellipse(290,80,5,5);
     outtextxy(300,80,msg);
     sprintf(msg,"Cluster 1 member");//n[i].id);
     setfillstyle(1,RED);
     fillellipse(290,100,5,5);
     outtextxy(300,100,msg);
     sprintf(msg,"Cluster 2 member");//n[i].id);
     setfillstyle(1,BLUE);
     fillellipse(290,120,5,5);
     outtextxy(300,120,msg);
//print routing table
}


int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int left, top, right, bottom;
   randomize();
   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
   paint();
 /*  left = getmaxx() / 2 - 50;
   top = getmaxy() / 2 - 50;
   right = getmaxx() / 2 + 50;
   bottom = getmaxy() / 2 + 50;

   /* draw a rectangle */
  // rectangle(left,top,right,bottom);

   node n[MAXNODES];
   for(int i=0;i<MAXNODES;i++)
   {
   //node[i]=node();
   }
   char ch='a';
   while(!kbhit())//*/ch!='z')
   {

   paint();
   table();

    for(int i=0;i<MAXNODES;i++)
    {
    if(i<MAXNODES/2)
    n[i].walk(10+rand()%230,5+rand()%180);
    else if(i>=MAXNODES/2)
    n[i].walk(10+rand()%230,290+rand()%100);

    if(n[i].id==1||n[i].id==6) //previledge nodes can move across clusters
    n[i].walk(10+rand()%230,5+rand()%430);
    findhead(n);
    n[i].draw();

    }
   delay(2000);

   ch=getch();
   cleardevice();
   } /* clean up */
//   getch();
   closegraph();
   return 0;
}


