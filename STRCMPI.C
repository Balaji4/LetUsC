#include<string.h>
void main()
{
 char a[10],b[10];
 printf("\n enter 2 strings \n");
 gets(a);
 gets(b);
 if(!strcmpi(a,b))
 printf("\n strings r identical\n");
 else
 printf("not identical\n");
 getch();
}