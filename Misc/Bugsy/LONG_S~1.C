#include<stdio.h>
#include<string.h>
int LCSub(char * str1, char *str2)
{
int i,j;
int num[80][80];
	int maxlen = 0;
        if ((strcmp(str1,"\0")==0) || (strcmp(str2,"\0")==0))
                return 0;
 

 
        for (i = 0; str1[i] !='\0';  i++)
        {
                for (j = 0;   str2[j]!='\0'; j++)
                {
                        if (str1[i] != str2[j])
                                num[i][j] = 0;
                        else
                        {
                                if ((i == 0) || (j == 0))
                                        num[i][ j] = 1;
                                else
                                        num[i][ j] = 1 + num[i - 1][ j - 1];
 
                                if (num[i][j] > maxlen)
                                {
                                        maxlen = num[i][j];
                                }
                        }
                }
        }
        return maxlen;
}

void main()
{
char s1[80],s2[80];
int max;
clrscr();
printf("\n enter string 1\n");
gets(s1);
printf("\n enter string 2\n");
gets(s2);
max=LCSub(s1,s2);
printf("\n longest substring is of length=%d",max);
getch();
}