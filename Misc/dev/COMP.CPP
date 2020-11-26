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
friend void calc(set,set &);
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

 void calc(set a,set &comp)
{
int k=0;
comp.n=a.n;
for(int i=0;i<a.n;i++)
 {
   comp.x[k]=a.x[i];
   comp.num[k]=1-a.num[i];
   k++;
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
set a,b,aa,bb;
clrscr();
cout<<" For set A\n";
a.read();
cout<<" For set B\n";
b.read();
calc(a,aa);
calc(b,bb);
cout<<"\n set A={";
a.display();
cout<<"}\n";
cout<<" set B={";
b.display();
cout<<"}\n";
cout<<" Complement set for A: A'={";
aa.display();
cout<<"}\n";
cout<<" Complement set for B: B'={";
bb.display();
cout<<"}\n";

getch();
return 0;
}