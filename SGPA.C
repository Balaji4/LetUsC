#include<stdio.h>
#include<conio.h>
void main()
{
 char s[10],l[5];
 int i,j,s1,l1;
 float total=0.0,sgpa=0.0,credits;
 clrscr();
 printf("\n how many subjects?\n");
 scanf("%d",&s1);
 printf("\nhow many labs \n");
 scanf("%d",&l1);
 printf("\nenter the number of credits\n");
 scanf("%f",&credits);
 printf("\n enter the subject grades\n");
 for(i=0;i<s1;i++)
 {
   scanf("%s",&s[i]);
  }

  for(i=0;i<s1;i++)
  {
   switch(s[i])
   {
     case 'S'|'s': total+=4*10;
		  break;
     case 'A'|'a': total+=4*9;
		  break;
     case 'B'|'b': total+=4*8;
		  break;
     case 'C'|'c': total+=4*7;
		  break;
     case 'D'|'d': total+=4*6;
		  break;
     case 'E'|'e': total+=4*5;
		  break;
     default:total+=0;
     break;
    }
   }
	printf("\n enter lab subjects grades \n");
	 for(j=0;j<l1;j++)
	   {
	    scanf("%s",&l[j]);
	   }
	  for(j=0;j<l1;j++)
	  {
	    switch(l[j])
	    {
	      case 'S'|'s': total+=1.5*10;
		  break;
	      case 'A'|'a': total+=1.5*9;
		  break;
	      case 'B'|'b': total+=1.5*8;
		  break;
	      case 'C'|'c': total+=1.5*7;
		  break;
	      case 'D'|'d': total+=1.5*6;
		  break;
	      case 'E'|'e': total+=1.5*5;
		  break;
	      default:total+=0;
		      break;
	    }
	   }
	   sgpa=total/credits;
    printf("SGPA=%f",sgpa);
    getch();
 }