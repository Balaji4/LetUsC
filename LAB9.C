
	#include<alloc.h>
	
	struct node
	{
		int usn , semis;
		char name[20];
		struct node *link;
	};

	struct node * getnode( )
	{	
	return ( struct node *) malloc( sizeof ( struct node ));
	}
	
	struct node *addFront( struct node *);
	struct node *addLast( struct node *);
	int getCount( struct node *);
	struct node *addPosition( struct node * , int );
	struct node * deleteById( struct node * , int );
	void updateInfo( struct node * , int );
	void displayAll( struct node *);
	void main( )
	{
	struct node *H;
	int ch , usn , pos;
	H = NULL;
	while( 1)
	{
	clrscr();
	printf("1. Add @ front \n");
	printf("2. Add @ last \n");
	printf("3. Add @ position \n");
	printf("4. Delete on usn \n");
	printf("5. Update on usn \n");
	printf("6. Display all \n");
	printf("7. Exit ");
	scanf("%d", &ch );

	switch( ch )
	{
	case 1:
		H = addFront( H );
		break;
	case 2:
		H = addLast( H );
		break;
	case 3:		
		printf("Enter position = ");
		scanf("%d", &pos);
		H = addPosition( H, pos);
		break;
	case 4:
		printf("Enter usn = ");
		scanf("%d", &usn);
		H = deleteById( H , usn );
		break;
	case 5:
		printf("Enter usn = ");
		scanf("%d", &usn);
		updateInfo	( H , usn );
		break;
	case 6:
		displayAll( H );		
		break;
	case 7:
		exit(0);
	}

	getch();

	}	// while

	}	// main

	struct node * addFront( struct node *H )
	{
	 struct node *N;
	 N = getnode( );
	 printf("Enter usn , name and semister \n");
	 scanf("%d %s %d", &N->usn , N->name , &N->semis);
	 N->link = H;
	 H =N;
	 return H;
	}

	struct node * addLast( struct node *H )
	{
	  struct node *T;
	  if( H == NULL )
	  {
		H = getnode( );
		T = H;
	  }
	  else
	  {
		T = H;	
		while( T->link != NULL ) T=T->link;
		
		T->link = getnode( );
		T =T->link;
	}
	
	 printf("Enter usn , name and semister \n");
	 scanf("%d %s %d", &T->usn , T->name , &T->semis);
	 T->link = NULL;
	 return H;
	}

	int getCount( struct node *T )
	{	
	int c = 0;

		while( T != NULL )
		{
		c++;
		T =T->link;
		}
	return c;
	}

	struct node *addPosition( struct node *H , int pos)
	{
		struct node *T, *N;
		int i;

		  if( pos > getCount(H))
		 {
			  printf("out of range");
			  return H;
		  }

	  	else if( pos == 1 )
		       H = addFront( H );
		else
		    {
			T = H;
			for(i=1; i<=pos-2; i++) T = T->link;
	
			 N = getnode( );
			 printf("Enter usn , name and semister \n");
			 scanf("%d %s %d", &N->usn , N->name , &N->semis);
			 N->link = T->link;
			 T->link = N;
		     }
	  return H;
	  }

	  struct node * deleteById( struct node *H , int usn )
	  {
		struct node *T, *temp;
		char found = 'N';

		if( H->usn == usn )	// found at 1st node
		{
			found = 'Y';
			T = H;
			H = H->link;
			free( T);
		}
		else
		{
			T = H;
			while( T!= NULL)
			{
				if( T->link->usn  == usn )
				{
					temp = T->link;
					T->link = temp->link;
					free ( temp );
					found = 'Y';
					break;
				}

			T = T->link;
			}
		}

		if( found == 'Y' )
		printf("Deleted successfully");
		else
		printf("Not found");

		return H;
	}


	void updateInfo( struct node *H , int usn )
	{
		struct node *T;
		char found = 'N';
		T=  H;
		while( T != NULL )
		{
			  if( T->usn == usn )
			  {
				    found = 'Y';
				    printf("Record found \n");
				    printf("Id       :  %d\n", T->usn);
				    printf("name  : %s \n", T->name);		
				    printf("Semister : %d\n", T->semis);
		
				    printf("Enter new semister \n");
				    scanf("%d", &T->semis );	
				    break;
			    }

		  T = T->link;
		}

		if( found == 'N' )
		printf("Not found");
		
	}

	void displayAll( struct node *T )
	{
	  printf("Linked list contents are as follows \n");

		while( T != NULL )
		{
		printf("%p : %d \t %-20s \t %d :  %p --> \n", T , T->usn , T->name , T->semis , T->link );
		T =T->link;
		}
	}
