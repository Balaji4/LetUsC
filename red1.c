#include<stdio.h>

#include<stdlib.h>
	
#include<unistd.h>

#define n 20


int r=0,c=n;

int avgq=n*3/4;
	
int sum=0,num=2;

int front=0,rear=-1;

struct pkt
{
	int cb;
	
	int pktno;

	int sadd;

	int dadd;


       
};

struct pkt pk[100];


typedef struct pkt p;



p q[100];

int arr[10];


void display();

int insert(struct pkt ele,p q[]) 
{
	int ack=0;
	
	
	
	printf("\nthe avg queue length=%d\n",avgq);	
	
	if(r==0)

	{
			
	r++;
	
	avgq=(avgq+r)/num;
		
	sum=avgq;		
	}
	
	else
	{
	r++;

	sum+=r;
		
	num++;	
		
	avgq=sum/num;
        }
				
	if(r>avgq)

	{	int i=1;
	
		printf("\ncongestion has occured \n");

		ele.cb=1;	
	
		ack=1;
		
		r--;
		
	
		printf("\nthe Discared packets is \n");
	
	
		printf("\ncb\t\t:%d\t\npktno\t\t%d\nsadd\t\t:%d\t\ndadd\t\t:%d\n",ele.cb,ele.pktno,ele.sadd,ele.dadd);	
					
		return ack;
		
			
	}
     
	rear=(rear+1)%avgq;	
	
	printf("\n packet queued is  %d\n",ele.pktno);

	q[rear].pktno=ele.pktno;    
	
	q[rear].sadd=ele.sadd;

	q[rear].dadd=ele.dadd;

	

	return 0;
   }




int delete(p q[])
{
	 
		
	p item;	
	
	if(r==0)
	
	    {	
		printf("the queue is empty\n");
	
		exit(0);
	    }
	
			
	item.cb=q[front].cb;

	item.pktno=q[front].pktno;
	
	item.sadd=q[front].sadd;

	item.dadd=q[front].dadd;
	
	front=(front+1)%avgq;
	
	r--;

	c--;

        printf("\nContent of the delivered packet is \n");

	printf("Cb\t\tPktno\t\tsadd\t\t\t dadd \t\t\t\t \n");

	printf("%d\t\t%d\t\t%d\t\t%d\t\t\t",item.cb,item.pktno,item.sadd,item.dadd);


	return c;
}
 
void display()
{

   int count,f=front;

   if(r==0)

       printf("\nqueue is empty\n");

   else

	printf("\nthe packets in the queue are \n");

	printf("\n----------------------------------------------------------------------------------------------------------------------\n");
       			
	printf("\nCb\t\t|Pktno\t\t|Sadd\t\t|Dadd\t\t|\n");
	
	printf("\n----------------------------------------------------------------------------------------------------------------------\n");
       		
	for(count=1;count<=r;count++)
	
	{
	
	printf("\n%d\t\t%d\t\t%d\t\t%d\t\t",q[f].cb,q[f].pktno,q[f].sadd,q[f].dadd);

	f=(f+1)%avgq;
	}
	printf("\n----------------------------------------------------------------------------------------------------------------------\n");
     	
		
}



int main()
{

	
	 int i=0,ackn=0,j=0;
      
 printf("the total size of the queue is %d\n",n);


 printf("packet will be sent now \n");

    for(i=0;i<10;i++)
	{
						   

			   pk[i].cb=0;	
	
			   pk[i].pktno=i+1;
				
			   pk[i].sadd=rand()%10;

			   pk[i].dadd=rand()%20;

			   
			
	}			 
		    for(i=0;i<20;i++)
				
				
                     {
				  ackn = insert(pk[i],q);	
	
					if(ackn==1)

					{
						arr[j++]=i;          			
                                         }
		}
	
			display();
			
			
           		
		while(ackn==1)
	

		{
	
	
	          	for(i=j;i>=1;i--)
	
   			{		                           	
          			
				ackn=insert(pk[arr[j-i]],q);
								
			        display();	
	
				delete(q);
			}

                }
			/*for(i=j;i>=1;i--)
	
			{
				ackn=insert(pk[arr[j-i]],q);
			}*/	
	
	
			

return 0;

}




	
