#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
void main()
{
int h[3][7]={1,0,1,1,1,0,0,
1,1,0,1,0,1,0,
0,1,1,1,0,0,1};
int r[7]; /* Holds input information */
int s[3]; /* The syndrome matrix */
int index; /* Holds the error bit position */
int i,j,sum;
printf("Enter the 7-bit information(0's and 1's) with blank spaces between each bit\n");
for (i=0;i<7;i++)
scanf("%d",&r[i]);
for(j=0;j<3;j++)
{
sum=0;
for(i=0;i<7;i++)
sum+=h[j][i]*r[i];
sum=sum%2;
s[j]=sum;
}
/* Now we check if the syndrome matrix s[] is a null vector or
not. If it is, then the accepted info is error-free. Or else
we need to detect and correct the error */
if(s[0]==0 && s[1]==0 && s[2]==0)
{
printf("\nError-free information\n");
printf("The data bits are\n");
for(i=0;i<4;i++)
printf("%d",r[i]);
printf("\n");
exit(0);
}

/* Error bit position detection and correction
/* We compare the syndrome s[] matrix with each column of the
h[][] matrix until a match is found. The matching column
determines the index of the error bit and we can compliment
the bit at that position to get the corrected data */
for(j=0;j<7;j++)
{
if(s[0]==h[0][j] && s[1]==h[1][j] && s[2]==h[2][j])
{
index=j;
break;
}
}
printf("\nThe error is in the bit no- %d\n",index+1);
/* compliment the error bit */
if(r[index]==0)
r[index]=1;
else
r[index]=0;
printf("The corrected information is\n");
for(i=0;i<7;i++)
printf("%d",r[i]);
printf("\nThe data bits are\n");
for(i=0;i<4;i++)
printf("%d",r[i]);
getch();
}