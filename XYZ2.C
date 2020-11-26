#include<stdio.h>

int split ( int*,int *, int, int ) ;
void quicksort ( int *,int *, int, int ) ;
void max(int *,int *,int,int);
void main( )
{
	int a[100],b[100],n;
	int i,x1,x2,y1,y2,pro,s1x[100],s2x[100],s1y[100],s2y[100];
	int p=0,q=0,g,h;
	clrscr();
	printf("enter the size\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("x%d,y%d \n",i,i);
	scanf("%d %d",&a[i],&b[i]);
	}
	quicksort ( a,b, 0, n-1 ) ;
	//for +ve -ve
	x1=a[0];
	y1=b[0];
	x2=a[n-1];
	y2=b[n-1];

	for(i=0;i<n;i++)
{
	pro=x1*y2+a[i]*y1+x2*b[i]-a[i]*y2-x2*y1-x1*b[i];
	if(pro>0)
	{
	s1x[p]=a[i];
	s1y[p]=b[i];
	g=p;
	}
	else if(pro<0)
	{
	s2x[q]=a[i];
	s2y[q]=b[i];
	h=q;
	}
}
       //for positive, neg, code ends

       //for max points

       max(int s1x,int s1y,int x1,int y1,int x2,int y2,int g);







      /////////////////////

	getch();

}
void quicksort ( int a[ ],int b[ ], int lower, int upper )
{
	int i;
	if ( upper > lower )
	{
	i = split ( a,b, lower, upper ) ;
	quicksort ( a,b, lower, i - 1 ) ;
	quicksort ( a,b, i + 1, upper ) ;
	}
}
int split ( int a[ ],int b[ ], int lower, int upper )
{
	int i, p, q, t,t1 ;
	p = lower + 1 ;
	q = upper ;
	i = a[lower] ;
	while ( q >= p )
	{
	while ( a[p] < i )
	p++ ;
	while ( a[q] > i )
	q-- ;
	if ( q > p )
	{
	t = a[p] ;
	a[p] = a[q] ;
	a[q] = t ;
	t1 = b[p] ;
	b[p] = b[q] ;
	b[q] = t1 ;

	}
	}
	t = a[lower] ;
	a[lower] = a[q] ;
	a[q] = t ;
	t1 = b[lower] ;
	b[lower] = b[q] ;
	b[q] = t1 ;

	return q ;
}
////max function
void max(int x[],int y[],int x1,int y1,int x2,int y2,int g)
{
int i,a,b,c,dist
a=y2-y1;
b=x1-x2;
c=y1*(x2-x1)-x1*(y2-y1);
for(i=0;i<g;i++)
{
 dist=(a*a[i]+b*b[i]+c)/(sqrt(a*a+b*b));















