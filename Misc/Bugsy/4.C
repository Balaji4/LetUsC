#include<stdio.h>
#include<string.h>
char * str();
void main()
{
char *a;
clrscr();
a=str();
printf("%3s",a);
getch();
}
char *str()
{
int i=10;
char b[30];
if(i++==10)
{
strcpy(b,"CSI");
}
else
{
strcpy(b,"Bugsy");
}
return b;
}