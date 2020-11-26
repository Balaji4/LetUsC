

	#include<alloc.h>

	struct node 
	{
	  int empno;
	  char name[20];

	  struct node *link;
	};
	
	struct node* getnode( )
	{
	return (struct node*)malloc( sizeof( struct node ));
	}

	struct node *addnew(struct node *);

	void display( struct node *);



	
	void main( )
	{
	struct node *H;
	int ch;
	H = NULL;

	while(1)	
	{

		clrscr();

		printf("1. Addnew\n");	
		printf("2. Display\n");
		printf("3. Exit\n");

		scanf("%d", &ch);

		switch( ch )
		{
		case 1:
			H = addnew( H );
			break;
		case 2:
			display(H);
			break;
		case 3:
			return;
		}

		getch();
	}
	}


	struct node * addnew( struct node *H)
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
	 
	  while( T->link != NULL )
	  {		
		T = T->link;
	  }

	  T->link = getnode( );
	  T = T->link;
	}

	printf("Enter empno and name\n");
	scanf("%d %s", &T->empno , T->name);

	T->link = NULL;	
	return H;
	}

	
	void display( struct node *T)
	{
	  
	printf("Linked list records as follows\n");

	while( T!=NULL )
	{
	printf("%p [ %d  %s ] -> %p\n", T , T->empno , T->name , T->link );

	T = T->link;
	}

	}






	





	

	  
	



	



	