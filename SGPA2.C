#include<stdio.h>
#include<conio.h>
void main()
{
 int i,j,grade[6],credit[6],credits=0;
/* char grade[8]={'\0'}; */
float total=0.0,sgpa[6],cgpa=0.0,tc=0.0;
 clrscr();
 printf("\nEnter SGPA from 1st SEM to 5th SEM ");
 for(i=0;i<=4;i++)
 {
 printf("\n SGPA for SEM %d: ",i+1);
 scanf("%f",&sgpa[i]);
 }
 printf("\nCredit Details of 6th SEM\n");
 printf("\n Enter credit and Grade of \n");
 for(i=0;i<6;i++)
 {
 printf("\n IS6%d0: ",i+1);
 scanf("%d %d",&credit[i],&grade[i]);
 printf("\n%d %d\n",credit[i],grade[i]);
 }

  for(i=0;i<6;i++)
  {
   credits+=credit[i];
   switch(grade[i])
   {
   case 10: total+=credit[i]*10;
		  break;
     case 9: total+=credit[i]*9;
		  break;
     case 8: total+=credit[i]*8;
		  break;
     case 7: total+=credit[i]*7;
		  break;
     case 5: total+=credit[i]*5;
		  break;
     case 4: total+=credit[i]*4;
		  break;
     default:total+=0;
     break;
    /* case 'S'|'s': total+=credit[i]*10;
		  break;
     case 'A'|'a': total+=credit[i]*9;
		  break;
     case 'B'|'b': total+=credit[i]*8;
		  break;
     case 'C'|'c': total+=credit[i]*7;
		  break;
     case 'D'|'d': total+=credit[i]*5;
		  break;
     case 'E'|'e': total+=credit[i]*4;
		  break;
     default:total+=0.0;
     break;                            */
    }
   }

	   sgpa[5]=total/credits;
	   printf("\n Credits=%d total=%f",credits,total);
	   printf("\nSPGA\n");
	   for(i=0;i<6;i++)
	   {
		printf("\nSGPA for SEM %d=%f",i+1,sgpa[i]);
		}
		tc=(sgpa[0]*23+sgpa[1]*23);
		tc+=sgpa[2]*25;

    for(i=3;i<6;i++)
    {
     tc+=sgpa[i]*26;
    }
    cgpa=tc/149.0;
    printf("\n CGPA=%f",cgpa);
    getch();
 }