#include<stdio.h>
void main()
{
int a[10][10],r,c,i,j,flag=0;
clrscr();
printf("\n how many rows & columns\n");
scanf("%d%d",&r,&c);
printf("\n enter %d elements\n ",r*c);
for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
   {
   scanf("%d",&a[i][j]);
   }
 }
for(i=0;i<c;i++)
 {
 flag=0;
  for(j=0;j<r;j++)
   {
   if(a[i][j]==1)
    {
    flag=1;
    continue;
    }
    else {
    flag=0;
    break;
    }
   }
   if(flag)
  printf("row %d contains elements which are all 1\n",i+1);
 }
 for(i=0;i<r;i++)
 {
 flag=0;
  for(j=0;j<c;j++)
   {
   if(a[j][i]==1)
    {
    flag=1;
    continue;
    }
    else {
    flag=0;
    break;
    }
   }
   if(flag)
  printf("column %d contains elements which are all 1\n",i+1);
 }
for(i=0,j=0;i<r,j<c;i++,j++)
  {
  flag=0;
    if(a[i][j]==1)
     {
     flag=1;
     continue;
     }
    else {
    flag=0;
    break;
    }
  }
  if(flag)
  printf("left to right row contians elements which are all 1\n");
 for(i=0,j=c-1;i<r,j>=0;i++,j--)

  {
  flag=0;
    if(a[i][j]==1)
     {
     flag=1;
     continue;
     }
    else {
    flag=0;
    break;
    }
  }
  if(flag)
  printf("right to left row contians elements which are all 1\n");
 getch();
 }