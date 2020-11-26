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

  void eval(float *total1,float pt,char s[],int size);

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
  scanf("%s",stud[c].name);
  printf("\n how many subjects?\n");
  scanf("%d",&stud[c].s1);
  printf("\nhow many labs \n");
  scanf("%d",&stud[c].l1);
  printf("\nenter the number of credits\n");
  scanf("%d",&stud[c].credits);
  printf("\n enter the subject grades\n");

     for(i=0;i<stud[c].s1;i++)
      scanf("%s",&stud[c].s[i]);


   eval(&stud[c].total,4,stud[c].s,stud[c].s1);

	printf("\n enter lab subjects grades \n");

	 for(j=0;j<stud[c].l1;j++)
	    scanf("%s",&stud[c].l[j]);

	    eval(&stud[c].total,1.5,stud[c].s,stud[c].l1);

	 stud[c].sgpa=stud[c].total/stud[c].credits;

  }
	 printf("\tNAME                       SGPA\n");
	 printf("\t------------------------------------\n");

  for(c=0;c<k;c++)
  {
   printf("\t%s                     %2.5f\n",stud[c].name,stud[c].sgpa);
  }

  getch();
 }



 void eval(float *total1,float pt,char s[],int size)
  {
   int i;

   for(i=0;i<size;i++)
   {
    switch(s[i])
    {
	case 's'|'S':*total1+=10*pt;
	     break;

	case 'a'|'A':*total1+=9*pt;
	     break;

	case 'b'|'B':*total1+=8*pt;
	     break;

	case 'c'|'C':*total1+=7*pt;
	     break;

	case 'd'|'D':*total1+=6*pt;
	     break;

	case 'e'|'E':*total1+=5*pt;
	     break;
	case 'f'|'F':*total1+=0;
	     break;
	}
    }
   }