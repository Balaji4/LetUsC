#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int mystr(char [],char [],int,int);
void main()
{
char text[80],pat[80];
int n,m,sym[91],i,j,k;
clrscr();
printf("\nEnter a text\n");
gets(text);
n=strlen(text);
printf("\nEnter a pattern to be searched\n");
gets(pat);
m=strlen(pat);
for(i=0;i<91;i++)
{
sym[i]=m;
}
for(i=0;i<m-1;i++)
{
j=pat[i];
sym[j-32]=m-1-i;
}
for(i=0;i<m;i++)
{
j=pat[i];
printf("\t%d",sym[j-32]);
}

for(i=0;i<=(n-m);)
 {
   j=m-1;
   k=j;
   k=k+i;
   while(j>=0&&pat[j]==text[i+j])
   j--;
 if(j<0)
 {
 printf("found in %d ",i+1);
 getch();
 exit(0);
 }
 i+=sym[text[k]-32];
}
printf("\n not found\n");
getch();
}







