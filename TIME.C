#include<stdio.h>
#include<dos.h>
#include<conio.h>

struct t
{
int hr;
int min;
int sec;
};

void main()
{
struct t p,*q;
 int i;
 char ch;
q=&p;
clrscr();
printf("\n enter the current time in hour min second format\n");
scanf("%d%d%d",&q->hr,&q->min,&q->sec);
for(i=q->sec;i<60;i++)
{
  clrscr();
  printf("%d:%d:%d",q->hr,q->min,i);
  delay(1000);

}
getch();
}
