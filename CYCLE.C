#include<stdio.h>
#include<conio.h>
#include<time.h>
void run();
void rotate(char *p1);
void main()
{

clrscr();
run();
getch();
}

void run()
{
char ch1=45,ch2=46,ch3=45,ch4=46;
int i=1,c=2,r=10,j;
for(c=1;c<65;c++)
{
i=1;
clrscr();
gotoxy(c,r);
printf("          %c%c%c%c",242,22,22,243);
gotoxy(c,r+1);
printf("=====%c%c----%c",177,16,182);
gotoxy(c,r+2);
printf("     %c     %c%c     ",92,47,92);
gotoxy(c,r+3);
//rotate(&ch1);
rotate(&ch2);
if(ch4=='|')
{
ch4='.';
}
else if(ch4=='.')
{
ch4='|';
}
printf(" %c%c%c%c  %c%c%c  %c%c%c%c\n",ch2,ch1,ch1,ch2,92,197,47,ch2,ch1,ch1,ch2);
gotoxy(c,r+4);
printf("%c    %c     %c    %c   \n",ch4,ch4,ch4,ch4);
gotoxy(c,r+5);   //r=15
printf(" %c%c%c%c       %c%c%c%c\n",ch2,95,95,ch2,ch2,95,95,ch2);
//gotoxy(c,r+6);
while(i<=80)
{
printf("-");
i++;
}
delay(100);

}

}

void rotate(char *p1)
{
if(*p1=='_'||*p1=='-')
{
*p1='.';
}
else if(*p1=='.')
{
*p1='-';
}
}