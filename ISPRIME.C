/*to check weather a no. is prime or not*/
#include<stdio.h>
#include<conio.h>
void main()
{
int n;
clrscr();
printf("\n enter a number\n");
scanf("%d",&n);
if(isprime(n))
 {
 printf("\n %d is prime\n");
  }
  else
  printf("\n %d is not prime \n");
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