#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void siftDown(int *arr, int root,int bottom)
{
	int done,maxChild,temp;
	done = 0;
	while((root * 2 <= bottom) && (!done))
	{
			if(root *2 == bottom)
				maxChild = root * 2;
			else if(arr[root*2] > arr[root * 2 + 1])
				maxChild = root * 2;
			else
				maxChild = root * 2 + 1;		
			if(arr[root] < arr[maxChild])
			{
				temp = arr[root];
				arr[root] = arr[maxChild];
				arr[maxChild] = temp;
				root = maxChild;
			}	
			else
				 done = 1;
	}
}

void heapsort(int *arr, int n)
{
	 int i,temp;
	/*heapify*/
	 for(i = (n/2); i >= 0; i--)
		  siftDown(arr,i,n-1);
		 for(i = n-1;i >= 1;i--)
		 {
			  temp = arr[0];
			  arr[0] = arr[i];
			  arr[i] = temp;
			  siftDown(arr,0,i-1);
		 }
}

int main()
{
	int i,n,*arr;

	long long run_time;

	struct timeval start, end;
	
	system("clear");

	printf("Enter number of elements\n");

	scanf("%d",&n);

	arr = malloc(n * sizeof(int));

	for(i = 0;i < n;i++)

		 arr[i] = rand();

	gettimeofday (&start, NULL);

	heapsort(arr,n);	 

 	gettimeofday (&end, NULL);
	
	run_time = (end.tv_sec * 1000000) + end.tv_usec;

	run_time = run_time - ((start.tv_sec * 1000000) + start.tv_usec);
	
	/* run_time now contains the time run of the program in microseconds.
	 Divide the (float) run_time by 1000.00 to get the time in milliseconds. */
			
	printf ("Runtime: %f milliseconds.\n", (double)run_time/1000.0);

 return(0);

}
