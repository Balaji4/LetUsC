

	#include<alloc.h>

	struct node
	{
		struct node *prev;
		int empno;
		char name[20];
		struct node *next;
	};

	struct node * getnode( )
	{
	  return ( struct node *) malloc( sizeof( struct node ));
	}

	struct node * add( struct node *H )
	{
	  struct node *N , *T;
	  N = getnode();
	  printf("Enter empno and name \n");
	  scanf("%d %s", &N->empno , N->name );

	  if( H == NULL )
	  {
	    H = N;
	    H->prev = H->next = H;
	  }
	  else
	  {
		T = H;
		while( T->next != H ) T = T->next;

		T->next = N;
		H->prev = N;
		N->next = H;
		N->prev = T;
	  }

	  return H;
	  }

	  void display ( struct node *T )
	  {
	    char ch;

	    while( 1 )
	    {
	       clrscr();
	       gotoxy( 35 , 10 );
	       printf("Employ number    : %d \n", T->empno);

	       gotoxy( 35 , 12 );
	       printf("Employ name      : %s \n", T->name );


	       printf("\n\n\n[N]ext  [P]rev  [Q]uit \n");

	       ch = getch();

	       if( ch == 'n' || ch == 'N') T = T->next;
		else if( ch == 'p' || ch == 'P') T = T->prev;
		else if( ch == 'q' || ch == 'Q' ) return;
	    }
	  }


	  void main()
	  {
	   struct node *H;
	   int ch;
	   H = NULL;
	   while(1)
	   {
		clrscr();
		printf("1. Addnew \n");
		printf("2. Display \n");
		printf("3. Exit \n");

		scanf("%d", &ch );

		switch( ch )
		{
		case 1:
			H =  add( H );
			break;
		case 2:
			display( H );
			break;
		case 3:
			exit(0);
		}

		getch();
	   }

	   }
