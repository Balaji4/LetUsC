#include<iostream.h>
#include<conio.h>
#define MAX 10
class set
{
float x[MAX],num[MAX];
int n;
public:set()
{
}
void read();
friend void calc(set,set,set &);
void display();
};

void set::read()
{
cout<<"\n How many  set elements\n";
cin>>n;
for(int i=0;i<n;i++)
 {
 cout<<"\n Enter numerator(membership function) for element "<<i+1<<endl;
 cin>>num[i];
 cout<<"\n Enter denominator(x) for element "<<i<<endl;
 cin>>x[i];
 }

}

 void calc(set a,set b,set &uni)
{
int k=0;
uni.n=a.n;
for(int i=0;i<a.n;i++)
 {
  if(a.x[i]==b.x[i])
   {
   uni.x[k]=a.x[i];
   uni.num[k]=((a.num[i]>b.num[i])?a.num[i]:b.num[i]);
   k++;
   }
}
}
void set::display()
{
for(int i=0;i<n;i++)
cout<<"\t"<<num[i]<<"/"<<x[i];
}

int main()
{
set a,b,u;
clrscr();
cout<<" For set A\n";
a.read();
cout<<" For set B\n";
b.read();
calc(a,b,u);
cout<<"\n set A={";
a.display();
cout<<"}\n";
cout<<" set B={";
b.display();
cout<<"}\n";
cout<<" Union set U={";
u.display();
cout<<"}\n";

getch();
return 0;
}