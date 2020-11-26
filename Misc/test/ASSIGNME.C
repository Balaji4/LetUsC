#include<stdio.h>
void constvol();
void constpres();
void iso();
void adiabatic();
int main()
{
int ch;
for(;;)
 {
 printf("Menu\n");
 printf("\n1:Constant Volume Process");
 printf("\n2:Constant Pressure Process");
 printf("\n3:Isothermal Process");
 printf("\n4:Adiabatic Process");
 printf("\n5:Exit");
 printf("\n\nEnter your choice\n");
 scanf("%d",&ch);
 switch(ch)
  {
  case 1:constvol();
	 break;
  case 2:constpres();
	 break;
  case 3:iso();
	 break;
  case 4:adiabatic();
	 break;
  case 5:exit(0);
  default:printf("Invalid choice entered");
  }
 }
}