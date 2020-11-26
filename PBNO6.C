#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void check(int n,char *);
void convert(int n,char *);
void counter(char []);
int ct[6];
int main()
{
int n1,n2;
long int prod;
char op1[5]="\0",op2[5]="\0",hexprod[10]="\0";
printf("\n enter 2 decimal numbers (0<number<5000)\n");
scanf("%d%d",&n1,&n2);
//check(n1);
//check(n2);
convert(n1,op1);
convert(n2,op2);
printf("\nEquivalent hexadecimals of given operands\n");
printf("\n%s",op1);
printf("\n%s\n\n",op2);
prod=n1*n2;
convert(prod,hexprod);
printf("\n count of ABCDEF in product\n\n");
counter(hexprod);
printf("A=%d\nB=%d\nC=%d\nD=%d\nE=%d\nF=%d\n",ct[0],ct[1],ct[2],ct[3],ct[4],ct[5]);

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


void counter(char op[])
{
int i;
for(i=0;op[i]!='\0';i++)
{
switch(op[i])
{
case 'A':ct[0]++;
	 break;
case 'B':ct[1]++;
	 break;
case 'C':ct[2]++;
	 break;
case 'D':ct[3]++;
	 break;
case 'E':ct[4]++;
	 break;
case 'F':ct[5]++;
	 break;
}
}
}