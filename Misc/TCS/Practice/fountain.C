#include<stdio.h>
#include<conio.h>
void fountain();
int gcd(int,int);
int lcms(int,int*);
int lcm(int,int);
int res[10000],k=0;
int main()
{
int n,i;
clrscr();
scanf("%d",&n);
for(i=0;i<n;i++)
fountain();

for(i=0;i<k;i++)
printf("%d\n",res[i]);
getch();
return 0;
}

void fountain()
{
int lcm1,gcd1,m,l,a[10000],i;
scanf("%d",&l);
for(i=0;i<l;i++)
scanf("%d",&a[i]);
lcm1=lcms(l,a);
res[k++]=lcm1;
}

int gcd(int m,int n)
{
int r;
while(n!=0)
 {
  r=m%n;
  m=n;
  n=r;
 }
 return m;
}

int lcm(int m,int n)
{
return m*n/gcd(m,n);
}

int lcms(int n,int * a)
{
	int     i, result;
	result = 1;
	for (i = 0; i < n; i++) result = lcm(result, a[i]);
	return result;
}


