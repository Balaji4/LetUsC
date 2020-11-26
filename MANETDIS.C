#include<stdio.h>
#define MAX 10
struct dist_vect
{
int dist[MAX];
int from[MAX];
};
int main()
{
int adj[MAX][MAX],n,i,j,hop[10][10]={{0}},k,count;
struct dist_vect arr[10];
printf("Enter the number of nodes\n");
scanf("%d",&n);
printf("Enter adjecency matrix\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
scanf("%d",&adj[i][j]);
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
arr[i].dist[j]=adj[i][j];
arr[i].from[j]=j;
}
}
count=0;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
for(k=0;k<n;k++)
{
if(arr[i].dist[j]>adj[i][k]+arr[k].dist[j])
{
arr[i].dist[j]=adj[i][k]+arr[k].dist[j];
arr[i].from[j]=k;
count++;
if(count==0)hop[i][j]=1;
else hop[i][j]=count+hop[k][j];
}
}
count=0;
}
}
for(i=0;i<n;i++)
{
printf("State value of router under %d",i+1);
printf("\nNode\tvia node\tdistance\tnumber of hops\n");
for(j=0;j<n;j++)
{
if(i==j)
printf("\n%d\t%d\t%d\n",j+1,arr[i].from[j]+1,arr[i].dist[j]);
else
printf("\n%d\t%d\t\t%d\t\t%d\n",j+1,arr[i].from[j]+1,arr[i].dist[j],hop[i][j]+1);
}
}
}