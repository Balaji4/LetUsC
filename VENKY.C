#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<math.h>
int  rev(char b[]);

void main()
{
char s[3],sym;
char op[2][5]={0,0};
int i=0,j=0,l=0,op1=0,op2=0;
float res;
clrscr();
printf("\n enter a string \n");
scanf("%s",s);
while(s[i]!='\0')
{
if(isdigit(s[i]))
{
op[j][l]=s[i];
i++;
l++;
}
else
{
l=0;
j++;
sym=s[i];
i++;
}
}
printf("op1is %s",op[0]);
strrev(op[0]);
//op1=(int)op[0];
op1=rev(op[0]);
printf("op1is %d",op1);
printf("%c",sym);
printf("\n op2 is %s",op[1]);
strrev(op[1]);
op2=rev(op[1]);
printf("\n op2 is %d",op2);


switch(sym)
{
case '+':res=op1+op2;
	  break;
case '-':res=op1-op2;
	  break;
case '*':res=op1*op2;
	  break;
case '/':if(op2==0)
	   {
	   printf("Divede by zero \n");
	   getch();
	   exit(1);
	   }
	 res=(float)op1/op2;
	  break;
case '%':res=(int)op1%op2;
	  break;
default:res=0;
	printf("\n Invalid operator");
	 break;
}

printf("\n result=%f",res);
getch();
}
int  rev(char b[])
{
int digit,r=0,i=0,k=0;
while(b[i]!='\0')
{
digit=((int)b[i]-'0');
r=r+digit*pow(10,k);
k++;
i++;
}
printf("r=%d",r);
return r;
}