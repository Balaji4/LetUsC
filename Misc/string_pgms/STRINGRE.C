#include<stdio.h>
#include<string.h>
void main()
{
char str[80],*temp[10];
int i,k=0;
clrscr();
printf("\n enter a string \n");
gets(str);
printf("\n Given string is %s\n",str);
strrev(str);
printf("\n reversed string is %s",str);
printf("\n reversed words are \n");
temp[0]=strtok(str," ");
strrev(temp[0]);
for(k=0;;)
{
printf(" %s",temp[k]);
k++;
temp[k]=strtok(NULL," ");
if(temp[k]==NULL)
{
break;
}
strrev(temp[k]);
}
getch();

}