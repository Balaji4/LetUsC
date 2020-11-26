

	#include<alloc.h>
	#include<stdio.h>
	#include<conio.h>
	
	struct node
	{
	char msg[80];
	struct node *link;
	};

	struct node *getnode()
	{
	 return (struct node*)malloc( sizeof(struct node ) );
	}

	struct node * addMsg( struct node *);
	
	void displayMsg( struct node *);

	void main( )
	{
	int ch;
	struct node *H;
	H = NULL;
	while( 1 )
	{
	 clrscr();
	 printf("1. Add message\n");
	 printf("2. Display message \n");
	 scanf("%d", &ch);

		switch( ch )
		{
		case 1:
			H = addMsg( H );
			break;
		case 2:
			displayMsg( H );
			break;
		default:
			return;
		}
	getch();
	}

	}

	struct node * addMsg( struct node *H)
	{
	struct node *T , *N;

	fflush(stdin);
	printf("Enter message \n");
	N = getnode( );
	gets( N->msg );

	if( H == NULL )
	{
	  H = N;
	  H->link = H;
	}
	else
	{	
	  T = H;
		
		while( T->link != H )
		T = T->link;

	T->link = N;
	N->link = H;
	}
	
	return H;
	}

	void displayMsg( struct node *T)
	{

	_setcursortype( _NOCURSOR );

	while( !kbhit() )
	{
		clrscr();

		gotoxy( 20 , 23 );  // x = 20 , y=23

		printf("%s", T->msg);

		T = T->link;

		sleep(3);
	}

	}
	
	
	

