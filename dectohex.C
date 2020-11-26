
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//enum {A=10,B,C,D,E,F};
void check(int n,char *);
void convert(int n,char *);
int main()
{
int n1,n2;
char op1[5]="\0",op2[5]="\0";
int count[5];
clrscr();
printf("\n enter 2 decimal numbers (0<number<5000)\n");
scanf("%d%d",&n1,&n2);
//check(n1);
//check(n2);
convert(n1,op1);
convert(n2,op2);
printf("\n%s",op1);
printf("\n%s",op2);
getch();
return 0;

}




/*void check(int n)
{
 if(n<=0||n>=5000)
 {
 printf("\n out of range\n");
 exit(0);
 }
} */

void convert(int n,char *res)
{
int r,i=0,d=0;
char temp[2];
for(i=0;n!=0;i++)
{

r=n%16;
d++;
n=n/16;
switch(r)
{
case 10:res[i]='A';
	break;
case 11:res[i]='B';
	break;
case 12:res[i]='C';
	break;
case 13:res[i]='D';
	break;
case 14:res[i]='E';
	break;
case 15:res[i]='F';
	break;
default:itoa(r,temp,10);
	res[i]=temp[0];
	 break;
}

}
strrev(res);
}