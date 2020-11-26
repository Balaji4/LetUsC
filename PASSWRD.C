#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
void main()
{
 char p[5]={"abcde"},cp[5],ch;
 int i,j,k;
 clrscr();
l: printf("\n enter password\n");
 for(i=0;i<5;i++)
 {
  cp[i]=getch();
   printf("*");
  }

 if(!strncmpi(cp,p,5))
  {
   printf("\npassword entered is correct\n");
   delay(500);
   printf("\nloading");
   for(j=0;j<5;j++)
   {
    delay(500);
    printf(".\a");
    }
  }
    else
   {
   printf("\n password entered is not correct\n");
   printf("\n would you like to continue y/n?");
   ch=getch();
      if(ch=='y'||ch=='Y')
      {
	  goto l;
      }
      else
      printf("\nokay");
   }

    getch();
}
