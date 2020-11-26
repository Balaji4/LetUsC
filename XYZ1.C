#include <stdio.h>

int split ( int*,int*, int, int ) ;
void quicksort ( int *,int *, int, int ) ;

void main( )
{
	int a[100],b[100],n;
	int i ;
	clrscr();
	printf("enter the size\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("x%d,y%d \n",i,i);
	scanf("%d %d",&a[i],&b[i]);
	}
	quicksort ( a,b, 0, n-1 ) ;
	printf ( "\nArray after sorting:\n") ;
	for ( i = 0; i < n; i++)
		printf ( "%d %d\t", a[i],b[i]) ;
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