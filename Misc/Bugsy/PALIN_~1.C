#include <stdio.h>

void main()
{
  long int n, reverse = 0, temp;
   clrscr();
   printf("Enter a number to check if it is a palindrome or not\n");
   scanf("%ld",&n);

   temp = n;

   while( temp != 0 )
   {
      reverse = reverse * 10;
      reverse = reverse + temp%10;
      temp = temp/10;
   }

   if ( n == reverse )
      printf("%ld is a palindrome number.\n", n);
   else
      printf("%ld is not a palindrome number.\n", n);

   getch();
}