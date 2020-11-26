/* remove duplicate chars from a string */
#include<stdio.h>
#include<conio.h>
void main()
{
char str[80];
char hash[26]={0};
int i=0,j=0;
clrscr();
printf("\n enter a string\n");
gets(str);

for(;str[i]!='\0';i++)
 {
 if(isalnum(str[i]))
  {
   if(!hash[str[i]-'a'])
    {
     hash[str[i]-'a']=1;
     str[j++]=str[i];


    }
  }
  else
   {
   str[j++]=str[i];
   }
  }
    str[j]='\0';
    printf("\n String after removing duplicates\n ");
    printf("%s",str);


 getch();
}