#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 20
#define INFINITY 999
#include<conio.h>
enum boolean {FALSE,TRUE};
void prim(int c[][MAX],int t[MAX],int n);
int mincost=0; //initialize minimum cost to 0
int main()
{
int n,c[MAX][MAX],t[2*(MAX-1)];
int i,j;
clrscr();
printf("\nTo find min path spanning tree");
printf("\nEnter no of nodes:");
scanf("%d",&n);
printf("\nEnter the cost adjacency matrix");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&c[i][j]); //distance between the nodes
prim(c,t,n); //algorithm to find the minimum spanning tree
for(i=0;i<2*(n-1);i+=2)
printf("\n(%d %d)",t[i]+1,t[i+1]+1); //nodes of the spanning tree
printf("\nmincost=%d",mincost);
getch();
return 0;
}
//using prim's algorithm for finding shortest path
void prim(int c[][MAX],int t[MAX],int n)
{
int i,j;
enum boolean v[MAX];
int k,s,min,v1,v2;
for(i=0;i<n;i++)
v[i]=FALSE;
v[0]=TRUE;
k=0;
t[k]=1;
s=0;
k++;
while(k<n)
{
min=INFINITY;
for(i=0;i<n;i++)
for(j=1;j<n;j++)
//while there is no path b/w any 2 nodes and dist is less than minimum
if(v[i]==TRUE && v[j]==FALSE && c[i][j]<min)
{
min=c[i][j];
v1=i;
v2=j;
}
mincost=mincost+min; //add the mindist to the mincost
if(min==INFINITY)
{
printf("graph disconnected");
exit(0);
}
v[v2]=TRUE;
k++;
t[s++]=v1;
t[s++]=v2;
}
}