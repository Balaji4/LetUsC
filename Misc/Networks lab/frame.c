#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct frame{
int fslno;
char finfo[20];
};
struct frame arr[10];
int n;
void sort()
{
int i,j,ex;
struct frame temp;
for(i=0;i<n;i++)
{
ex=0;
for(j=0;j<n-i-1;j++)
if(arr[j].fslno>arr[j+1].fslno)
{
temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
ex++;
}
if(ex==0) break;
}
}
void main()
{
int i;
clrscr();
printf("\n Enter the number of frames \n");
scanf("%d",&n);
for(i=0;i<n;i++)
{ arr[i].fslno=random(50);
printf("\n Enter the frame contents for sequence number %d\n",arr[i].fslno);
scanf("%s",arr[i].finfo);
}
sort();
printf("\n The frames in sequence \n");
for(i=0;i<n;i++)
printf("\n %d\t%s \n",arr[i].fslno,arr[i].finfo);
getch();
}