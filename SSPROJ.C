#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
void clear(char t[],int s)
{
int i;
 for(i=0;i<s;i++)
 {
  t[i]='\0';
 }

}

void main()
{
char temp[20],*p;
int i=0,j=0,flag=1;
p=(char*)malloc(200);
clrscr();
clear(p,200);
printf("\n enter struct\n");
gets(p);
clear(temp,20);
for(i=0,j=0;p[i]!=' '&&p[i]!='\0'&&p[i]!='{';i++,j++)
 {
  temp[j]=p[i];
  }
if(strcmp(temp,"struct")==0)
printf("struct syntax correct\n");
else
{
printf("Undefinded symbol %s\n",temp);
getch();
exit(0);
}
clear(temp,20);
for(;p[i]==' '&&p[i]!='\0';i++);
//i--; struct {
for(j=0;(p[i]!='{')&&(p[i]!=' ')&&p[i]!='\0';i++,j++)
{
  temp[j]=p[i];
}
if(temp[0]=='\0'&&p[i]!='{')
{
printf("\n not a valid identifier\n");
}
flag=ident(temp,j);
if(flag==0)
printf("\n Invalid identifier \n");
else
printf("\n valid identifier \n");
getch();
free(p);
}


int ident(char t[],int s)
{
int i,flag=1;
printf(" ->%s",t);
if((isalpha(t[0]))||(t[0]=='_'))
{
flag=1;
//return 0;
}
else {
flag=0;
return flag;
}

for(i=1;t[i]!='\0';i++)
{
if(isalnum(t[i])||(t[i]=='_'))
{
flag=1;
continue;
}else
{
flag=0;
return flag;
}
}
return 1;
}

