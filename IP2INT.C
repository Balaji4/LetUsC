#include<stdio.h>
#include<string.h>
void main()
{
char ip[16]="192.186.168.111";
int i=0;
unsigned int seg[4];
clrscr();
printf("%s",ip);
seg[0]=atoi(strtok(ip,"."));
for(i=1;i<4;i++)
{
seg[i]=atoi(strtok(NULL,"."));
}
printf("\n Ip unsigned\n");
for(i=0;i<4;i++)
{
printf("%d ",seg[i]);
}
getch();
}