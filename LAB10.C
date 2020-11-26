
	// Linked list as stack implementation is quite
	// simple and easy to implement

	// Push operation is nothing but adding@front
	// pop operation is delete@front

	
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

	struct node * push( struct node * , int );

	struct node * pop( struct node *);

	void display( struct node * );

	void main( )
	{
	struct node *H;
	int c = 0 , x , choice;
	H = NULL;

	while(1)
	{
	clrscr();
	
		printf("1. Push \n");
		printf("2. Pop \n");
		printf("3. Display \n");
		printf("4. Exit \n");

		printf("Choice = ");
		scanf("%d", &choice);
	
		switch( choice )
		{
		case 1:
		 	if( c == MAX )
			printf("Stack overflow\n");
			else
			{
				printf("Enter element= ");
				scanf("%d",&x);
				H = push( H , x );
				c++;
			}
			break;
		case 2:
			if( c == 0 )
			printf("Stack empty \n");
			else
			{
				H = pop( H );
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

	struct node *push( struct node *H , int data)
	{
		struct node *newnode;
		newnode = getnode();
		newnode->data = data;

		newnode->link = H;
		H = newnode;
		return H;
	}

	struct node *pop( struct node *H)
	{
	struct node *T;

	printf("Poped element = %d\n", H->data);
	
	T = H;

	H = H->link;
	free( T);
	return H;
	}

	void display( struct node *T )
	{	
	printf("Content of the stack \n");

	while( T!= NULL)
	{
	printf("%d\n", T->data);
	T = T->link;
	}
	
	}



	

		


