#include<stdio.h>
int main()
{
char stg[25]="\0";
int i,j=0,res[25],count=0;
float  prod=1;
printf("\n enter a string\n");
scanf("%s",stg);
for(i=0;stg[i]!='\0';i++)
{
 switch(stg[i])
 {
 case 'a':
 case 'b':
 case 'c':res[j]=2;
	  j++;
	  count++;
	  break;
 case 'd':
 case 'e':
 case 'f': res[j]=3;
	   count++;
	   j++;
	   break;
 case 'g':
 case 'h':
 case 'i': res[j]=4;
	   j++;
	   count++;
	   break;
 case 'j':
 case 'k':
 case 'l': res[j]=5;
	   j++;
	    count++;
	   break;
 case 'm':
 case 'n':
 case 'o': res[j]=6;
	   j++;
	   count++;
	   break;
 case 'p':
 case 'q':
 case 'r':
 case 's': res[j]=7;
	   j++;
	   count++;
	   break;
 case 't':
 case 'u':
 case 'v': res[j]=8;
	   j++;
	   count++;
	   break;
 case 'w':
 case 'x':
 case 'y':
 case 'z': res[j]=9;
	   j++;
	   count++;
	   break;
 default:break;
 }
}

for(j=0;j<count;j++)
{
prod=prod*res[j];
printf("%d*",res[j]);
}
printf("=%f",prod);
return 0;
}