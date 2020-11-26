#include<iostream.h>
#include<conio.h>
class sample
{
int a,b;
public:void set();
friend int add(sample s);
};

void sample::set()
{
cout<<"\n Enter two values\n";
cin>>a>>b;
}

int add(sample s)
{
return (s.a+s.b);
}

//int sample::*p;
//int sample::*q;

void main()
{
sample s,*r=&s;
int sum=0;
clrscr();
//p=&sample::a;
//q=&sample::b;
s.set();
sum=add(s);
cout<<"\n  Sum="<<sum;
getch();
}