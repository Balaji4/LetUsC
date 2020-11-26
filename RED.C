#include<stdio.h>
#include<stdlib.h>
int r=0,n=10;
int thr;
int front=0,rear=-1;
int sum=0,avgq=0;
struct pkt{
	int cb;      //congestion bit;
	int pktno;
	int sadd;
	int dadd;
	int priority;
};
struct pkt pk[100];
typedef struct pkt p;
p q[100];
int arr[10];
int display();
void deletenode(int);
void insert(struct pkt ele,p q[])
{
int i,j,k,t;
r++;
avgq=(sum+r)/2;
sum=avgq;
printf("\nPACKET ADDED: %d\npriority:%d\n",ele.pktno,ele.priority);
printf("LENGTH OF QUEUE = %d\n",sum+1);
getch();
if(avgq>=thr)
	{
	printf("\nWARNING: PACKET OVERFLOW AND CONGESTION MAY OCCUR\n");
	getch();
	ele.cb=1;
	r--;
	printf("\nPACKET IS DISCARDED TO AVOID CONGESTION\n");
	j=ele.priority;
	k=(rear+1)%thr;
	t=front;
	for(i=1;i<=r;i++)
	{
	if(q[t].priority>j){j=q[t].priority;k=t;}
	t=(t+1)%thr;
	}
	if(k==(rear+1)%thr)
	{
	ele.cb=1;
	//printf("\ncb\t\t:%d\t\npktno\t\t%d\nsadd\t\t:%d\t\ndadd\t\t:%d\npriority\t:%d\n\n",ele.cb,ele.pktno,ele.sadd,ele.dadd,ele.priority);
	//getch();
	return;
	}
	q[k].cb=1;
	//printf("\ncb\t\t:%d\t\npktno\t\t:%d\nsadd\t\t:%d\t\ndadd\t\t:%d\npriority\t:%d\n\n",q[k].cb,q[k].pktno,q[k].sadd,q[k].dadd,q[k].priority);
	q[k].cb=0;
	deletenode(k);
	rear=(rear+1)%thr;
	q[rear].pktno=ele.pktno;
	q[rear].sadd=ele.sadd;
	q[rear].dadd=ele.dadd;
	q[rear].priority=ele.priority;
	//getch();
	return;
	}
rear=(rear+1)%thr;
q[rear].pktno=ele.pktno;
q[rear].sadd=ele.sadd;
q[rear].dadd=ele.dadd;
q[rear].priority=ele.priority;
return;
}

void delete(p q[])
{
p ele;
if(r==0)
{
	printf("THE QUEUE IS EMPTY\n");
	getch();
	return;
}
ele.cb=q[front].cb;
ele.pktno=q[front].pktno;
ele.sadd=q[front].sadd;
ele.dadd=q[front].dadd;
ele.priority=q[front].priority;
front=(front+1)%thr;
r--;
printf("\nCONTENT OF DELIVERED PACKET \n");
printf("PACKETNO.\t\t:%d\nSOURCE\t\t:%d\t\nDESTINATION\t\t:%d\nPRIORITY\t:%d\n",ele.cb,ele.pktno,ele.sadd,ele.dadd,ele.priority);
avgq=(sum+r)/2;
sum=avgq;
getch();
}

void deletenode(int k)
{
 p ele;
 int t;
  while(k!=rear)
  {
	t=(k+1)%thr;
	ele.cb=q[k].cb;
	ele.pktno=q[k].pktno;
	ele.sadd=q[k].sadd;
	ele.dadd=q[k].dadd;
	ele.priority=q[k].priority;
	q[k].cb=q[t].cb;
	q[k].pktno=q[t].pktno;
	q[k].sadd=q[t].sadd;
	q[k].dadd=q[t].dadd;
	q[k].priority=q[t].priority;
	q[t].cb=ele.cb;
	q[t].pktno=ele.pktno;
	q[t].sadd=ele.sadd;
	q[t].dadd=ele.dadd;
	q[t].priority=ele.priority;
	k=(k+1)%thr;
	}
	rear=(rear-1)%thr;
  }

int display()
{
   int count,f=front,temp=0;
   if(r==0)
     { printf("\nqueue is empty\n"); getch(); return 0;}
   else
   {
	printf("the packets in the queue are \n");
	printf("**************************************************************************\n");
	printf("Pktno\t|\tSrcadd\t|\tDestadd\t|\tPriority|\n");
	printf("**************************************************************************\n");
	for(count=1;count<=r;count++)
	{
	printf("%d\t|\t%d\t|\t%d\t|\t%d\t|\n",q[f].pktno,q[f].sadd,q[f].dadd,q[f].priority);
	temp=q[f].pktno;
	f=(f+1)%thr;
	}
	printf("**************************************************************************\n");
	getch();
   }
   return temp;
}

int main()
{
 int i=0,nop,k=0,qty,choice;
 clrscr();
 //printf("enter size of the queue:");
 //scanf("%d",&n);
 thr=8;
 printf("THE THRESHOLD LENGTH OF THE QUEUE IS %d\n",thr);
 getch();
 for(;;)
 {
 clrscr();
 printf("1.ADD PACKETS\n2.DELIVER THE PCKTS\n3.DISPLAY PACKETS IN QUEUE\n4.EXIT\nPLS ENTER:");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:nop=1;
 //printf("ENTER NO. OF PACKETS TO BE ADDED:");
 //scanf("%d",&nop);
 qty=k;
 for(i=qty;i<nop+qty;i++)
	{
	    pk[i].cb=0;
	    pk[i].pktno=k+1;
	    pk[i].sadd=rand()%10;
	    pk[i].dadd=rand()%20;
	    pk[i].priority=random(nop+qty);
	    k++;
	 }
for(i=qty;i<nop+qty;i++)
     {
      insert(pk[i],q);
     }
     break;
case 2:
printf("ENTER PCKTS TO BE DELIVERED:");
scanf("%d",&nop);
for(i=nop;i>=1;i--) delete(q);
break;
case 3:k=display();
break;
default:exit(0);
}
}
}
