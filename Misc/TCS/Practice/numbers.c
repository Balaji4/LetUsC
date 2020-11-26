#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int mathew(int k);
int john(int k);
int valid(char[]);
int main()
{
int m,j,l,h,i,vi=0,elem[100],index,size=0,flag=0,invalid[3]={-1,-1,-1};
char low[10],high[10],indexstr[10];
printf("df");
scanf("%s %s",high,low);
scanf("%s",indexstr);
invalid[0]=valid(low);
invalid[1]=valid(high);
invalid[2]=valid(indexstr);
if(invalid[0]==-1||invalid[1]==-1||invalid[2]==-1)
 {
printf("Invalid Input");
exit(1);
}
l=atoi(low);
h=atoi(high);
index=atoi(indexstr);
printf(" -> %d %d %d",l,h,index);
for(i=l;i<=h;i++)
{
flag=0;
m=mathew(i);
if(m==mathew(i-l+1)) 
 {
 flag=1;
 }

j=john(i);
while(j!=1&&j!=4)
{
j=john(j);
}

if(j==1&&flag==1)
 {
  elem[vi]=i-l+1;
 vi++;
size++;
}
}


if(size>index)
printf("%d",elem[index]);
else 
printf("No number is present at this index");
return 0;
}

int mathew(int k)
{
return (k*(k+1)/2);
}

int john(int k)
{
int dig;
int sum=0;
while(k)
{
dig=k%10;
sum=sum+dig*dig;
k=k/10;
}

return sum;
}

int valid(char s[])
{
int i=0;
while(s[i]!='\0') 
{
if(!isdigit(s[i]))
 {
  return -1;
 }
i++;
} 
return 1;
}
