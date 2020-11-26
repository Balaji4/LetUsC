/*pattern matching using horspool algorithm*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
char s[100],p[100],c;
int i=0,j=0,n,m,sym[91],k;
clrscr();
/*------------read source--------------*/
printf("Enter source string\n");

	while( ( c=getchar() ) != '\n')
	{
		s[i] = c;
		i++;
	}
	s[i]='\0';
/*------------------------------------*/

/*----------read pattern--------------*/
printf("Enter pattern string\n");

	while( ( c=getchar() ) != '\n')
	{
		p[j] = c;
		j++;
	}
	p[j]='\0';
/*------------------------------------*/

n=strlen(s);
m=strlen(p);

/*initialize symbol table*/
for(i=0;i<91;i++)
	sym[i] = m;
/*-----------------------*/


/*generate symbol table*/
for(i=0;i<m-1;i++)
{
      j=p[i];
      sym[j-32] = m-1-i;
}
/*---------------------*/
for(i=0;i<m;i++)
{
j=p[i];
printf("%d\t",sym[j-32]);
}
printf("\n");
/*----------------------------horspool---------------------------*/
	i=0;
	while( i <=n-m )
	{

	j = m-1;
	k = j;
	k=k+i; /*maintains index of the letter in s corresponding to the position of last letter in p for this loop*/

	/*checks for matching*/
	while(j >= 0 && p[j] == s[i+j])
	{
	j--;
	}

	if(j < 0)
	{
		printf("Pattern found at position %d\n",i+1);
		exit(0);
	}

	/*move to next position in source string using the shift table*/

	i=i+sym[s[k]-32];
	/*
	printf("%c\n",s[k]);
	printf("%d\n",i);*/

	}
	printf("Pattern string not found\n");
/*---------------------------------------------------------------*/
getch();
return (0);
}


