#include<stdio.h>
#include<conio.h>
typedef struct
{
  char name[10];
  char s[10];
  char l[5];
  int s1;
  int l1;
  float total;
  float sgpa;
  int credits;
 }grade;
void main()
{
  grade stud[10];
 int i,j,k,c;
 clrscr();
 printf("\n how many students\n");
 scanf("%d",&k);
 for(c=0;c<k;c++)
 {
 stud[c].total=0.0;
 stud[c].sgpa=0.0;
 printf("\n enter your name\n");
 scanf("%s",&stud[c].name);
 printf("\n how many subjects?\n");
 scanf("%d",&stud[c].s1);
 printf("\nhow many labs \n");
 scanf("%d",&stud[c].l1);
 printf("\nenter the number of credits\n");
 scanf("%d",&stud[c].credits);
 printf("\n enter the subject grades\n");
  for(i=0;i<stud[c].s1;i++)
  {
   scanf("%s",&stud[c].s[i]);
  }

   for(i=0;i<stud[c].s1;i++)
   {
    switch(stud[c].s[i])
    {
     case 'S'|'s':stud[c].total+=4*10;
		  break;
     case 'A'|'a':stud[c].total+=4*9;
		  break;
     case 'B'|'b':stud[c].total+=4*8;
		  break;
     case 'C'|'c':stud[c].total+=4*7;
		  break;
     case 'D'|'d':stud[c].total+=4*6;
		  break;
     case 'E'|'e':stud[c].total+=4*5;
		  break;
     default:stud[c].total+=0;
     break;
    }
   }
	printf("\n enter lab subjects grades \n");
	 for(j=0;j<stud[c].l1;j++)
	   {
	    scanf("%s",&stud[c].l[j]);
	   }
	  for(j=0;j<stud[c].l1;j++)
	  {
	    switch(stud[c].l[j])
	    {
	      case 'S'|'s':stud[c].total+=1.5*10;
		  break;
	      case 'A'|'a':stud[c].total+=1.5*9;
		  break;
	      case 'B'|'b':stud[c].total+=1.5*8;
		  break;
	      case 'C'|'c':stud[c].total+=1.5*7;
		  break;
	      case 'D'|'d':stud[c].total+=1.5*6;
		  break;
	      case 'E'|'e':stud[c].total+=1.5*5;
		  break;
	      default:stud[c].total+=0;
		      break;
	    }
	   }
	 stud[c].sgpa=stud[c].total/stud[c].credits;
   /* printf("SGPA=%f",stud[c].sgpa);*/
  }
	 printf("\tNAME                       SGPA\n");
	 printf("\t------------------------------------\n");
  for(c=0;c<k;c++)
  {
   printf("\t%s                     %2.5f\n",stud[c].name,stud[c].sgpa);
  }

  getch();
 }