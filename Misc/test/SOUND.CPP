#include <dos.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
int main(void)
{
float freq;
char ch;
for(;;)
{
ch=getch();
if(ch=='e')
exit(0);
freq=pow(2,float((int(ch)-48-49)/12))*440;
   sound(freq);
   delay(100);
   nosound();
}
}