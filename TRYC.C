#include<stdio.h>
#include<conio.h>
#include<time.h>
void main()
{
int i=1,c=2,r=10,j;
clrscr();
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
printf(" .--.  %c%c%c  .--.\n",92,197,47);
gotoxy(c,r+4);
printf(".    .     .    .   \n");
gotoxy(c,r+5);   //r=15
printf(" .__.       .__.\n");
//gotoxy(c,r+6);
while(i<=80)
{
printf("-");
i++;
}
sleep(1);

}

getch();
}
