 
//This program implements an animal guessing game using a binary tree.  It starts out with a small tree, reading from a file,
//and builds the tree accordingly. After the tree has been built, the user then interacts with the program. The user is
//asked questions about their animal, if the program guesses right, then the user is prompted to play again, if the program
//guesses wrong, the user is asked for a question to distinguish their animal and then they are asked what animal they are.
//That information is then added to the tree and when the user quits. The tree is printed to a file and next time a tree 
//is built using that file, the tree will be much larger. The tree gets 'smarter' each time it is played.

#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct Animal
{
	char data[50];
	struct Animal* left;
	struct Animal* right;
	struct Animal* parent;
};

#define FLUSH while (getchar() != '\n')	 //Pre-processor defined statement which flushes the newline that is left
										 //in the input stream by scanf.

void push(struct Animal*[], int*, struct Animal*);
//Description:  Adds pointers to a stack which is later used for backtracking.
//Preconditions:  A stack, which holds pointers, is passed and top and a pointer of type Animal is passed.
//Postconditions:  No values are returned after the push occurs.
struct Animal* pop(struct Animal*[], int*);
//Description:  Removes pointers from the stack which are needed for backtracking.
//Preconditions:  A stack, which holds pointers, is passed and also top is passed to keep track how many items are in the stack.
//Postconditions:  The pointer from the top of the stack is returned.
struct Animal* build_tree(int*);
//Description:  The binary tree is built and each node is filled with info from a file.
//Preconditions:  Node count is passed to the function to keep track of how many nodes are in the tree.  
//Postconditions:  A pointer is returned which points to the root of the tree.
void print_file(struct Animal*, int*);
//Description:  The tree is traversed and the data of each node is written to the file specified.
//Preconditions:  The pointer of the root node is passed.
//Postconditions:  No values are returned.
struct Animal* user_play(struct Animal*, int*);
//Description:  The user interacts with the program until they wish to quit the program.
//Preconditions:  The pointer to the root of the node is passed and also the node count to keep track of total nodes.
//Postconditions:  The pointer to the root node is returned from the function.
int valid_char(char[]);
//Description:  Checks to see if the user didn't input bad data for a yes or no question.
//Precondition:  A character string is sent to the function to check.
//Postcondition:  An integer value is returned representing 1 for true and 0 for false.
int question_check(char[]);
//Description:  Checks to see if the user input a question mark at the end of their question.
//Precondition:   A character string is sent to the function to check.
//Postcondition:   An integer value is returned representing 1 for true and 0 for false.

int main(void)
{
	struct Animal* current;
	struct Animal* temp_root;
	int n=0;
	
	current= build_tree(&n);							//n is passed by reference.
	temp_root= current;									//After current is returned by by previous function, root_node is assigned to it.

	temp_root= user_play(temp_root,&n);
	
	print_file(temp_root, &n);	
	
	return 0;
	
}

int valid_char(char m[])
{
	int x,flag=0;										//A flag is initialized to 0.
	
	x= strlen(m);
	
	if(x>1)												//If there is more than 1 character in the string, false is returned.
		flag=0;
	else
	{
		if(m[0]=='y'|| m[0]=='Y')
			flag=1;
		if(m[0]=='n'|| m[0]=='N')
			flag=1;
	}
	return flag;
}

int question_check(char n[])
{
	int x, flag=0;
	
	x= strlen(n);
	
	if(n[x-2]=='?')										//Checks if the last character is a question mark.
		flag=1;
		
	return flag;
}
	
		
void push(struct Animal* stack[], int* top, struct Animal* current)
{												
	if(*top<99)											//A condition checks whether the stack is full. If it is, then it prints 
	{													//an error message.
		(*top)++;
		stack[*top]= current;							//If not full, the pointer is inserted into its appropriate slot.
	}
	else
		printf("\nThe stack is full.");
}



struct Animal* pop(struct Animal* stack[], int* top)
{
	struct Animal* temp;								
	
	if(*top==-1)										//A check determines whether the stack is empty, if so, then it prints
	     {
		printf("\nThe stack is empty.");				//an error message.
		return;
		}
	else
	{
		temp= stack[*top];								//If not empty, a pointer is then returned to main.
		(*top)--;
	}
	
	return temp;
}




struct Animal* build_tree(int *node_count)
{
	FILE *fin;
	char move[6], temp_info[50];
	struct Animal* current;
	struct Animal* temp;
	struct Animal* head;
	int a, count=0, r=0, i;
	struct Animal* stack[100];

	fin= fopen("c:\\work\\input.txt","r");				//The file is opened for reading in the program, a file pointer is declared.
	
	strcpy(move,"left");								//move is initialized to left.
	
	fgets(temp_info, sizeof(temp_info), fin);			//fgets scans in the first string from the file, places it in variable.
	
	current= malloc(sizeof(struct Animal));				//The root node is created and info is placed in it.				
	strcpy(current->data, temp_info);
	current->left= NULL;
	current->right= NULL;
	current->parent= NULL;
	temp= current;
	head= current;
	(*node_count)++;

	while(!feof(fin))											//The loop continues until the end of the file is reached.
	{
		fgets(temp_info, sizeof(temp_info), fin);				
		a= strlen(temp_info);
		
		if(strcmp(move,"left")==0)								//If move is equal to left, then it is a question and it is then
		{														//pushed onto the stack.
			push(stack, &r, current);
			current->left= malloc(sizeof(struct Animal));
			current= current->left;
			strcpy(current->data, temp_info);
			current->left= NULL;
			current->right= NULL;
			current->parent= temp;
			(*node_count)++;
		}
		else
		{
			current= pop(stack, &r);							//If move is equal to right, then the stack is popped to the previous pointer.
			current->right= malloc(sizeof(struct Animal));
			current= current->right;
			strcpy(current->data, temp_info);
			current->left= NULL;
			current->right= NULL;
			current->parent= temp;
			(*node_count)++;
		}
		
		count=0;
		
		for(i=0;i<a;i++)										//for loop determines whether the string is a question.
		{
			if(temp_info[i]=='?')
			{
				count++;
			}
		}
		
		if(count>0)												//If it is a question, then move is equal to left, else, move is right.
			strcpy(move,"left");
		else
			strcpy(move,"right");
	}
	
	fclose(fin);												//The input file is closed after use.
	
	return head;												//The root node pointer is returned to main.
}




void print_file(struct Animal* temp_root, int *node_count)
{
	struct Animal* current;
	int r=0, count2=0, h, j;
	FILE *fout;
	struct Animal* stack[100];
	int print_node=0;
	char move[6], data[50];
	
	fout= fopen("c:\\work\\input.txt","w");						//The file is opened to which the output will be saved to.
	
	
	strcpy(move,"left");										//move is initialized to left.

	current= temp_root;											//The root is printed first, then it enters a while loop to print the
	fputs(current->data, fout);									//rest of the tree.
	print_node++;												//print_node keeps track of how many nodes have been printed.

	while(print_node<*node_count)	
	{	
		count2=0;
		
		if(strcmp(move,"left")==0)
		{
			push(stack, &r, current);
			current= current->left;
			
			fputs(current->data, fout);	
				
		}
		else
		{
			current= pop(stack, &r);
			current= current->right;
			
			fputs(current->data, fout);
			
		}
	
	
		h= strlen(current->data);
		strcpy(data, current->data);
		
		for(j=0;j<h;j++)										//If the string is a question, move is always equal to left.
		{
			if(data[j]=='?')
				count2++;
		}
	
		if(count2>0)
			strcpy(move,"left");
		else
			strcpy(move,"right");
	
		print_node++;
	}
	
	fclose(fout);												//The file is closed after it has been written to.
}




struct Animal* user_play(struct Animal* temp_root, int *node_count)
{
	struct Animal* current;
	struct Animal* temp;
	char ques_choice, ans_choice, answer, game_choice;
	int count1=0, count_wrong=0, i;
	char b[50], x[50], temp_answer[50], new_question[50], new_answer[50]; 
	char move[6], game_choice1[20], answer1[20], ques_choice1[20], ans_choice1[20];
	
	do
	{
		printf("\nWould you like to play the animal guessing game?");		//The program begins to interact with the user.
		printf("\nPress 'Y' to continue, 'N' to QUIT:    ");			
		scanf("%s", &game_choice1);
	}while(valid_char(game_choice1)==0);
	
	game_choice= game_choice1[0];
	
	FLUSH;
	
	
	while(game_choice=='y' || game_choice=='Y')
	{
		current= temp_root;
		printf("\nFor the following questions, Press 'Y' for yes, 'N' for no.");
		
		do
		{
			printf("\n\n%s", current->data);								//The root is always printed first and then a while loop begins.
			scanf("%s", &ques_choice1);
		}while(valid_char(ques_choice1)==0);
		
		ques_choice= ques_choice1[0];
		
		FLUSH;
		
		if(ques_choice=='y' || ques_choice=='Y')
			strcpy(move,"left");
		else
			strcpy(move,"right");
			
		while(current!=NULL)						//Makes sure that current is pointing to a node and not NULL.
		{
			count1=0;
			count_wrong=0;
			
			if(strcmp(move,"left")==0)
			{
				current= current->left;
				strcpy(x, current->data);
				
				for(i=0;i<(strlen(x));i++)
				{
					if(x[i]=='?')					//Determines if the string is a question.
						count1++;
				}
				
				if(count1>0)
				{
					do
					{
						printf("%s", current->data);
						scanf("%s", &ques_choice1);
					}while(valid_char(ques_choice1)==0);
		
					ques_choice= ques_choice1[0];
					
					FLUSH;							//If it is a question, move = right, else, move = left.
					
					if(ques_choice=='y' || ques_choice=='Y')
						strcpy(move,"left");
					else
						strcpy(move,"right");
				}
				else
				{
					printf("\nI would like to make a guess. You are a(n) %s", current->data);	//The program makes a guess when it comes to a leaf.
					
					do
					{
						printf("\nPRESS 'Y' if I guessed right, PRESS 'N' if I was wrong:  ");
						scanf("%s",&ans_choice1);
					}while(valid_char(ans_choice1)==0);
					
					ans_choice= ans_choice1[0];
					
					FLUSH;
					
					if(ans_choice=='y' || ans_choice=='Y')	//After it makes a guess, it breaks the while loop by assigning current to NULL.
						current= NULL;
					else
					{
						temp= current;
						current= NULL;
						count_wrong++;
					}
				}
			}
			else											//else statement is for if move was equal to right. It dos the same as left.
			{
				current= current->right;
				strcpy(b, current->data);
				for(i=0;i<(strlen(b));i++)
				{
					if(b[i]=='?')
						count1++;
				}
				
				if(count1>0)
				{
					do
					{
						printf("%s", current->data);
						scanf("%s", &ques_choice1);
					}while(valid_char(ques_choice1)==0);
		
					ques_choice= ques_choice1[0];
					
					FLUSH;
					
					if(ques_choice=='y' || ques_choice=='Y')
						strcpy(move,"left");
					else
						strcpy(move,"right");
				}
				else
				{
					printf("\nI would like to make a guess. You are a(n) %s", current->data);
					
					do
					{
						printf("\n\nPRESS 'Y' if I guessed right, PRESS 'N' if I was wrong:  ");
						scanf("%s",&ans_choice1);
					}while(valid_char(ans_choice1)==0);
					
					ans_choice= ans_choice1[0];
					
					FLUSH;
					
					if(ans_choice=='y' || ans_choice=='Y')
						current= NULL;
					else
					{
						temp= current;
						current= NULL;
						count_wrong++;
					}
				}
			}
		}
		
		if(count_wrong>0)			
		{															//If the program guessed wrong, the user inputs thier info into the 
			current= temp;											//new nodes which are created.
			current->left= malloc(sizeof(struct Animal));
			(*node_count)++;
			current->right= malloc(sizeof(struct Animal));
			(*node_count)++;
			strcpy(temp_answer, current->data);
			
			do
			{
				printf("\nPlease enter a question to distinguish your animal.");
				printf("\n( be sure to include a question mark ).\n");
				fgets(new_question,sizeof(new_question),stdin);
			}while(question_check(new_question)==0);				//Determines if they put a question mark.
			
			strcpy(current->data, new_question);
			printf("\nWhat type of animal are you?\n");
			fgets(new_answer,sizeof(new_answer),stdin);
			
			do
			{
				printf("\nIs your answer correct for your question?  Type 'Y' for yes, 'N' for no:   ");
				scanf("%s",&answer1);
			}while(valid_char(answer1)==0);
			
			answer= answer1[0];
			
			if(answer=='y' || answer=='Y')							//Determines whether their answer is correct to their question.
			{														//If it is correct, it is placed in left child, otherwise, right child.
				current= current->left;
				current->parent= temp;
				strcpy(current->data, new_answer);
				current->left= NULL;
				current->right= NULL;
				current= temp;
				strcpy(current->data,new_question);
				current= current->right;
				current->parent= temp;
				strcpy(current->data, temp_answer);
				current->left= NULL;
				current->right= NULL;
			}
			else
			{
				current= current->right;
				current->parent= temp;
				strcpy(current->data, new_answer);
				current->left= NULL;
				current->right= NULL;
				current= temp;
				strcpy(current->data,new_question);
				current= current->left;
				current->parent= temp;
				strcpy(current->data, temp_answer);
				current->left= NULL;
				current->right= NULL;
			}
		}
		
		do
		{
			printf("\nWould you like to play again?:   ");
			printf("\nPress 'Y' to continue, 'N' to QUIT:    ");			
			scanf("%s", &game_choice1);
		}while(valid_char(game_choice1)==0);
	
		game_choice= game_choice1[0];
		
		FLUSH;
		
	}
	
	printf("\nThank you for playing.");
	
	current= temp_root;											//current is assigned back to the root of the tree and then returned.
	
	return current;
}


	
