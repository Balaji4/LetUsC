#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
  int inf;
  struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
  NODE first;
  first=(NODE)malloc(sizeof(struct node));
  return first;
}
NODE insert_front(int item,NODE head)
{
  NODE temp;
  temp=getnode();
  temp->inf=item;
  temp->link=head->link;
  head->link=temp;
  head->inf+=1;
  return head;
}
NODE insert_rear(int item,NODE head)
{
NODE temp,cur;
temp=getnode();
temp->inf=item;
cur=head->link;
while(cur->link!=head)
  cur=cur->link;
cur->link=temp;
temp->link=head;
head->inf+=1;
return head;
}
NODE read_num(NODE head)
{
   char c;

while((c=getche())!='\r')
{
  if(isdigit(c))
    head=insert_front(c-'0',head);
  else
{
   printf("Invalid integer\n");
  exit(0);
}
}
printf("\n");
return head;
}
void disp(NODE head)
{
  int k,n,*a;
  NODE cur;
if(head->link==head)
{
  printf("Number does not exists\n");
  return;
}
n=head->inf;
a=(int *)malloc(n*sizeof(int));
for(cur=head->link,k=0;cur!=head;cur=cur->link)
  a[k++]=cur->inf;
while(--k!=-1)printf("%d",a[k]);
printf("\n");
}
NODE add_long(NODE h1,NODE h2,NODE h3)
{
NODE c,c1,c2,h;
int sum,carry,digit;
carry=0;
c1=h1->link;
c2=h2->link;
while(c1!=h1&&c2!=h2)
{
 sum=c1->inf+c2->inf+carry;
 digit=sum%10;
 carry=sum/10;
 h3=insert_rear(digit,h3);
 c1=c1->link;
 c2=c2->link;
}
if(c1!=h1)
  c=c1,h=h1;
else
  c=c2,h=h2;
while(c!=h)
{
  sum=c->inf+carry;
  digit=sum%10;
  carry=sum/10;
  h3=insert_rear(digit,h3);
  c=c->link;
}
if(carry==1)
h3=insert_rear(carry,h3);
return h3;
}
main()
{
 NODE h1,h2,h3;
 h1=getnode();
 h2=getnode();
 h3=getnode();
 h1->link=h1;
 h2->link=h2;
 h3->link=h3;
 h1->inf=h2->inf=h3->inf=0;
 printf("Enter the first number\n");
 h1=read_num(h1);
 printf("Enter the second number\n");
 h2=read_num(h2);
 h3=add_long(h1,h2,h3);
 printf("Num1=");
 disp(h1);
 printf("Num2=");
 printf("Sum=");
 disp(h3);
}
