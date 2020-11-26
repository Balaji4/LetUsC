#include<stdio.h>
int main()
{
    int i, j;
    int a = 2, b = 4;
     clrscr();
    for(i = 0, j = 0; i < a, j < b; i++, j++)
    {
      printf("CSI Bugsy 2013\n");
    }
	 for(i = 0, j = 0; (i < a)&& (j < b); i++, j++)
    {
      printf("CSI Bugsy 2013\n");
    }

      getch();
    return 0;
}