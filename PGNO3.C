#include<stdio.h>
#include<string.h>
int main()
{
int i,j=0,r;
char s1[80],s2[80],sigma[80],temp[80],*p;
printf("\n Enter string  1\n");
gets(s1);
printf("\n\n Enter string 2\n");
gets(s2);
for(i=0;s1[i]!='\0';i++)
{
  if(s1[i]==' ')
  {
   p=strstr(s1," ");
   strcpy(temp,p);
   r=strcmp(temp,strstr(s2));
   if(r==0)
   {
   strcat(sigma,temp);
   }
  }
}
for(i=0;i<strlen(sigma);i++)
{
printf("%s",sigma);
}
getch();
return 0;
}

