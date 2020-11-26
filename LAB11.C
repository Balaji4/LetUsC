

	// Linked list as Q implementation is quite
	// simple and easy to implement

	// insert operation is nothing but adding@rear
	// delete operation is delete@front

	
	#include<alloc.h>
	#define MAX 5

	struct node 
	{
	  int data;
	  struct node *link;
	};

	
	struct node * getnode()
	{
	return ( struct node *) malloc( sizeof( struct node ));
	}

	struct node *ins( struct node * , int );

	struct node *del( struct node *);

	void display( struct node *);

	void main( )
	{
	struct node *H;
	int c = 0 , x , choice;
	H = NULL;

	while(1)
	{
	clrscr();
	
		printf("1. Insert \n");
		printf("2. Delete \n");
		printf("3. Display \n");
		printf("4. Exit \n");

		printf("Choice = ");
		scanf("%d", &choice);
	
		switch( choice )
		{
		case 1:
		 	if( c == MAX )
			printf("Q  Full\n");
			else
			{
			printf("Enter element= ");
			scanf("%d",&x);
			H = ins( H , x );
			c++;
			}
			break;
		case 2:
			if( c == 0 )
			printf("Q empty \n");
			else
			{
			H = del( H );
			c--;
			}
			break;
		case 3:
			if( c == 0 )
			printf("OOPS !!!! nothing to display \n");
			else
			display( H );	
			break;
		case 4:
			exit(0);
		}

		getch();

		}
	}

	struct node *ins( struct node *H , int data)
	{
	struct node *T;
		
	if( H == NULL )
	{	
		H = getnode();
		T = H;
	}
	else
	{
		T = H;

		while( T->link!=NULL)
			T = T->link;

		T->link=  getnode();
		T = T->link;
	}

	T->data = data;
	T->link = NULL;
	
	return H;
	}

	struct node *del( struct node *H)
	{
	struct node *T;

	printf("Deleted element = %d\n", H->data);
	
	T = H;

	H = H->link;
	free( T);
	return H;
	}

	void display( struct node *T )
	{	
	printf("Content of the Q \n");

	while( T!= NULL)
	{
	printf("%d\t", T->data);
	T =T->link;
	}
	
	}



	

		