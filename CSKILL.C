/*
//1.1
#include<stdio.h>
int main()
{
char far *s1,*s2;
printf("%d %d",sizeof(s1),sizeof(s2));
getch();
return 0;
}
*/
/*
//1.26
#include<stdio.h>
union a
{
int i;
char s[2];
};
int main()
{
union a z;
clrscr();
z.i=512;
printf("%d %d %d",z.s[0],z.s[1],sizeof(z.s));
return 0;
}
*/
//2.11
#include<stdio.h>
int main()
{
int a=5;
char s[]="its of ten chars";
clrscr();
printf(a>10?"%5.3s":"%s",s);
return 0;

}