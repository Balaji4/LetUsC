#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void main()
{
/* variable declaration */
int d[7]; /* Holds input data */
int c[7]; /* Holds the 7-bit info generated */
int i;
printf("Enter the data bits(0's and 1's) with blank spaces between them\n");
for(i=0;i<4;i++)
scanf("%d",&d[i]);
/* Now the array d[] contains the 4 data bits in binary form */
/* Next step is to find the output matrix c[] which has its
first 4 bits as in d[] and the next 3 bits as per the eqations,
b5=b1+b3+b4
b6=b1+b2+b4
b7=b2+b3+b4 */
for(i=0;i<4;i++)
c[i]=d[i];
c[4]=(d[0]+d[2]+d[3])%2; /* Binary addition */
c[5]=(d[0]+d[1]+d[3])%2;
c[6]=(d[1]+d[2]+d[3])%2;
/* Displaying the contents of the matricies c[] and d[] */
printf("\nThe data bits are\n");
for(i=0;i<4;i++)
printf("%d",d[i]);
printf("\nThe data after the addition of correction bits\n");
for(i=0;i<7;i++)
printf("%d",c[i]);
getch();
} 