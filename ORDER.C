
	#include<alloc.h>

	struct node
	{
	 char name[20];
	 int rank;	
	  struct node *link;	
	};

	struct node *getnode( )
	{
	return (struct node *)malloc( sizeof( struct node ));
	}

	struct node * add( struct node *);
	void display( struct node *);

	void main()
	{
	  struct node *H;
	  int ch;
	  H = NULL;

	   while(1)
	   {
		clrscr();

		printf("1. Add\n");
		printf("2. Display\n");
		printf("3. Exit\n");

		scanf("%d", &ch);

		switch( ch )
		{
		case 1:
			H = add( H );
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

	struct node *add ( struct node *H)
	{
	  struct node *N, *T;
	  N = getnode( );
	  printf("Enter name and rank\n");
	  scanf("%s %d", N->name , &N->rank);
	  N->link = NULL;
	
	  if( H == NULL) // list empty
	   H = N;	

	  else if(N->rank < H->rank )
	  {
		N->link = H;
		H = N;	
	  }
	  else
	  {
		T = H;

		while( T->link != NULL )
		{
		  if( T->link->rank > N->rank )
		  {
			N->link = T->link;
			T->link = N;
			break;
		  }
		T = T->link;
		}
	
		if( T->link == NULL)
		 T->link = N;
	  }

	  return H;
	  }

	  void display( struct node *T)
	  {

	  printf("List as follows\n");

	  while( T != NULL )
	  {
	   printf("%s %d\n", T->name , T->rank );
		T = T->link;
	  }

	  }

				


	
		
	

	 