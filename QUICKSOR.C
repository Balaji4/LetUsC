#include <stdio.h>
#include<conio.h>
int split ( int*, int, int ) ;
void quicksort ( int *, int, int ) ;
void main( )
{
int a[20],i,n;
clrscr();
printf("\n  How many elements \n");
scanf("%d",&n);
printf("\n Enter %d elements \n",n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("\n Array before sort \n");
for(i=0;i<n;i++)
{
printf(" %d",a[i]);
}

	quicksort ( a, 0, n-1 ) ;
	printf ( "\nArray after sorting:\n") ;
	for ( i = 0; i <n; i++)
		printf ( " %d", a[i]) ;
	getch();
}

void quicksort ( int a[ ], int lower, int upper )
{
	int i;
	if ( upper > lower )
	{
	i = split ( a, lower, upper ) ;
	quicksort ( a, lower, i - 1 ) ;
	quicksort ( a, i + 1, upper ) ;
	}
}

int split ( int a[ ], int lower, int upper )
{
	int i, p, q, t ;
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
	}
	}
	t = a[lower] ;
	a[lower] = a[q] ;
	a[q] = t ;
	return q ;
}