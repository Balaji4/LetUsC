/* Assignment question no.1 */

/* Program to evaluate a given infix expression */

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
void infconv(char [],char []);
double evaluate(char []);
double result(double,double,char);
int spre(char);
int ipre(char);
void main()
{
char infix[20],exp[20];
double res;
clrscr();
printf("enter infix expression: ");
scanf("%s",infix);
infconv(infix,exp);
res=evaluate(exp);
printf("the value of given infix expression is %f\n",res);
getch();
}

void infconv(char inf[], char exp[])
{
char s[20],symbol;
int i,j=0,top=-1;
s[++top]='#';
for(i=0;i<strlen(inf);i++)
{
symbol=inf[i];
while(spre(s[top])>ipre(symbol))
exp[j++]=s[top--];
if(spre(s[top])<ipre(symbol))
s[++top]=symbol;
else
top--;
}
while(s[top]!='#')
exp[j++]=s[top--];
exp[j]='\0';
}

int spre(char symbol)
{
switch(symbol)
{
case '+':
case '-': return 2;
case '*': 
case '/': return 4;
case '$':
case '^': return 5;
case '(': return 0;
case '#': return -1;
default : return 8;
}
}

int ipre(char symbol)
{
switch(symbol)
{
case '+':
case '-': return 1;
case '*': 
case '/': return 3;
case '$':
case '^': return 6;
case ')': return 0;
case '(': return 9;
default : return 7;
}
}

double evaluate(char exp[])
{
char symbol;
double res,st[20],op1,op2;
int i,top=-1;
for(i=0;i<strlen(exp);i++)
{
symbol=exp[i];
if(isdigit(symbol))
{
st[++top]=symbol-'0';
}
else
{
op2=st[top--];
op1=st[top--];
res=result(op1,op2,symbol);
st[++top]=res;
}
}
res=st[top--];
return res;
}

double result(double a,double b,char ch)
{
switch(ch)
{
case '+': return(a+b);
case '-': return(a-b);
case '*': return(a*b);
case '/': return(a/b);
case '$':
case '^':return(pow(a,b));
}
}

