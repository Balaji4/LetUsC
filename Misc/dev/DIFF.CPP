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
friend void diff(set,set,set &);
friend void inter(set,set,set &);
friend void comp(set,set&);
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
 cout<<"\n Enter denominator(x) for element "<<i+1<<endl;
 cin>>x[i];
 }

}

 void comp(set a,set &bb)
{
int k=0;
bb.n=a.n;
for(int i=0;i<a.n;i++)
 {
   bb.x[k]=a.x[i];
   bb.num[k]=1-a.num[i];
   k++;
}
}

void diff(set a,set b,set &d)
{
set bb;
comp(b,bb);
inter(a,bb,d);
}
void inter(set a,set b,set &uni)
{
int k=0;
uni.n=a.n;
for(int i=0;i<a.n;i++)
 {
  if(a.x[i]==b.x[i])
   {
   uni.x[k]=a.x[i];
   uni.num[k]=((a.num[i]<b.num[i])?a.num[i]:b.num[i]);
   k++;
   }
}
}

void set::display()
{
cout<<" ";
for(int i=0;i<n;i++)
cout<<num[i]<<"/"<<x[i]<<"\t";
}
int main()
{
set a,b,bb,d;
clrscr();
cout<<" For set A\n";
a.read();
cout<<" For set B\n";
b.read();
cout<<"\n set A={";
a.display();
cout<<"}\n";
cout<<" set B={";
b.display();
cout<<"}\n";
comp(b,bb);
cout<<" Complement set for B: B'={";
bb.display();
cout<<"}\n";
cout<<" A|B ={";
diff(a,b,d);
d.display();
cout<<"}\n";
getch();
return 0;
}