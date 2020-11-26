

	#include<alloc.h>
	
	struct node
	{
	struct node *prev;
	int data;
	struct node *next;
	};

	struct node *getnode()
	{
	return (struct node*) malloc( sizeof( struct node ));
	}

	struct node * addFront ( struct node * , int );
	
	struct node * addLeft( struct node * , int , int);

	struct node * del( struct node * , int );

	void display( struct node *);

	void main( )
	{
	struct node *H;
	int choice , key , data;
	H = NULL;
	while(1)
	{
		clrscr();
		printf("1. Add front \n");
		printf("2. Left of the node \n");
		printf("3. Delete node \n");
		printf("4. Display \n");

		scanf("%d", &choice);
	
		switch( choice )
		{
		case 1:
			printf("Enter data = ");
			scanf("%d",&data);
			H = addFront( H , data);
			break;
		case 2:
			printf("Enter key and data \n");
			scanf("%d %d", &key , &data);
			H = addLeft( H , key , data );
			break;
		case 3:
			printf("Enter key = ");
			scanf("%d", &key);
			H = del ( H , key );
			break;
		case 4:
			display( H );
			break;
		case 5:
			return;
		}
	
		getch();
	    }
	}
	
	struct node * addFront( struct node *H , int data )
	{
	struct node *newnode;

	newnode = getnode();
	newnode->data = data;

	newnode->next = H;
	newnode->prev = NULL;	
	H->prev = newnode;
	H = newnode;
	return H;
	}

	struct node * addLeft( struct node *H , int key , int data)
	{
	struct node *T , *newnode;

	if( H->data == key )
	  H = addFront( H , data );
	else
	{
		 T = H;
		 while( T!= NULL )
		 {
		  if( T->data == key )
		  {
		     newnode = getnode();
		     newnode->data = data;
		     newnode->next = T;
		     newnode->prev = T->prev;
		     T->prev->next = newnode;
		     T->prev = newnode;
		     break;
		   }
		   T = T->next;
		 }
	 }
	return H;	
	}
	
	struct node * del( struct node *H , int key )
	{
	  struct node *T;
	  char flag = 'N';
	  
	  if( H->data == key )
	  {
		flag = 'Y';
		T = H;
		H = H->next;
		H->prev = NULL;
		free(T);
	  }
	else
	{
		  T = H;
		  while( T!=NULL )
		  {
			if( T->data == key )
		 	{
				 flag = 'Y';
				 T->prev->next = T->next;
				 T->next->prev = T->prev;
		 		 free(T);
			 	break;
		       	 }
	
			T = T->next;
		   }
	  }

	  if( flag == 'N' )
		printf("Not found");
	else
		printf("Deleted successfully");
	  return H;	
	 }

	 void display( struct node *T )
	 {	
	  printf("Linked list data \n");

	  while( T != NULL )
	  {
	    printf("%d\t", T->data );
	    T = T->next;
	  }
	}

	 


	  
	

