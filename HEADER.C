	#include<alloc.h>
	#include<stdio.h>

	struct node
	{
	   int voterid;
	   char name[20];
	   char gender;
	   struct node *link;
	};

	struct header
	{
	 int   mc , fc;
	 struct node *H;
	};	

	struct node * getnode( )
	{	
	 return ( struct node *) malloc( sizeof( struct node ));
	}

	struct header addnew ( struct header );

	void display( struct header );
	
	void main( )
	{
	struct header HEADER;
	int ch;

	HEADER.H = NULL;
	HEADER.mc = HEADER.fc = 0;

	while(1)
	{
	clrscr();

	printf("1. New node  \n");
	printf("2. Display \n");

	scanf("%d", &ch);

	switch( ch )
	{
	case 1:
		HEADER = addnew( HEADER );
		break;
	case 2:
		display( HEADER );
		break;
	default:
		return;
	}

	getch();
	}

	}

	struct header addnew( struct header HEADER )
	{

	struct node *T;

	if( HEADER.H == NULL )
	{
	 HEADER.H = getnode();
	 T = HEADER.H;
	}
	else
	{
		T = HEADER.H;

		while( T->link != NULL) T = T->link;

		T->link = getnode();
		T = T->link;
	}

	printf("Enter node information \n");

	fflush(stdin);

	scanf("%d %s %c", &T->voterid , T->name , &T->gender );

	T->link = NULL;

	if( toupper(T->gender) == 'M' )
		HEADER.mc++;
	else
		HEADER.fc++;

	return HEADER;
	}

	void display( struct header HEADER )
	{
		struct node *T;
	
		T = HEADER.H;

		while( T!=NULL )
		{
		printf("%d \t %s \t %c \n", T->voterid , T->name, T->gender );
		T = T->link;
		}

	printf("\n Summary information \n");

	printf("Male count     : %d \n", HEADER.mc );
	printf("Female count : %d \n", HEADER.fc );
	printf("Total count     : %d\n", HEADER.mc + HEADER.fc );
	}

	


	

	
	