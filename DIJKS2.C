#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int n,a[10][10],d[10],p[10];
void read();
void print();
void optimal(int src,int dest);


void optimal(int src,int dest)
{
int i,j,u,v,min;
int s[10];
for(i=0;i<n;i++)
 {
 d[i]=a[src][i];
 s[i]=0;
 p[i]=src;
 }
for(i=1;i<n;i++)
 {
 min=9999;
 u=-1;
 for(j=0;j<n;j++)
 {
  if(s[j]==0)
  {
   if(d[j]<min)
   {
    min=d[j];
    u=j;
   }
  }
 }
 s[u]=1;
 if(u==dest)
 return;
 for(v=0;v<n;v++)
 {
 if(s[v]==0)
  {
  if(d[u]+a[u][v]<d[v])
  {
  d[v]=d[u]+a[u][v];
  p[v]=u;
  }
 }
}
}
}
void read()
{
int i,j;
printf("\n Enter the no. of nodes\n");
scanf("%d",&n);
printf("\n Enter the cost adjacency matrix [enter 9999 if path does not exist] \n");
for(i=0;i<n;i++)
 {
 for(j=0;j<n;j++)
 {
 scanf("%d",&a[i][j]);
 }
 }
}

void print()
{
int srce,desti,i;
printf("\n enter the source node\n");
scanf("%d",&srce);
// for(srce=0;srce<n;srce++)
 {
  for(desti=0;desti<n;desti++)
  {
   optimal(srce,desti);
   if(d[desti]==9999)
   printf("\n %c is not reachable from %c\n",desti+65,srce+65);
   else
   {
     printf("\n The shortest path is ");
     i=desti;
     while(i!=srce)
     {
      printf("%c <--",i+65);
      i=p[i];
     }
    printf("%c=%d\n",i+65,d[desti]);
   }
  }
 }
}

 void main()
 {
 clrscr();
 read();
 print();
 getch();
 }