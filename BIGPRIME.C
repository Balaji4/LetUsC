/*max prime by 2 digit and 3 digit no. */
#include<stdio.h>
#include<conio.h>
void main()
{
long int n=999,k;
clrscr();
for(n=999;n>100;n--)
{
k=n*99;
if(isprime(k))
 {
 printf("\n %ld is longest prime by multiplication of biggest 2-3 digits\n",k);
  getch();
  exit(0);
  }
}
  printf("\n no prime exists \n");
getch();
}

int isprime(int r)
{
int n=2;
for(;n<=r/2;n++)
 {
 if(r%n==0)
  return 0;
 }
 return 1;
}
