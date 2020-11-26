#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
double x,tx;
void teex(double ,double ,double ,double ,double ,double ,double );
void cti();
//void   x(double ,double ,double ,double ,double ,double ,double ,double  );
int main()
{
double t1,t2,l,b,t,ko,beta,a;
int choice;
//double d1,d2,ts,tb,k,h;
clrscr();
for(;;)
{
cout<<"\n1) To calculate variable thermal conductivity \n";
cout<<"2) To calculate critical thickness of insulation\n";
cout<<"3) Exit\n";
cin>>choice;
cout<<"\n Note: Enter all units in SI \n";
switch(choice)
{
case 1:cout<<"enter T1\n";
      cin>>t1;
      cout<<"enter T2\n";
      cin>>t2;
      cout<<"enter length of slab L\n";
      cin>>l;
      cout<<"enter breadth of slab b\n";
      cin>>b;
       cout<<"enter thickness t\n";
       cin>>t;
      cout<<"enter coefficient Ko\n";
      cin>>ko;
      char betachar=225;
       cout<<"enter "<<betachar<<"\n";//beta
       cin>>beta;
//      cout<<"enter a");
  //   cin>>%lf",&a);
     teex(t1,t2,l,b,t,ko,beta);
    break;
case 2:
      cti();
      break;
default:exit(0);

}
}
//getch();

//return 0;
}
void teex(double t1,double t2,double l,double b,double t,double ko,double beta)
{
double tm,km,rslab,q,a;
int ch;
a=l*b;
char sq=253;
char deg=248;
cout<<"Area A="<<a<<" m"<<sq<<"\n";//c for square
tm=(t1+t2)/2.0;
cout<<"Mean tempareture Tm="<<tm<<" "<<deg<<"C\n"; // char degree
km=ko*(1+beta*tm);
cout<<"Variable thermal conductivity Km="<<km<<" W/m"<<deg<<"C\n";
rslab=t/(km*a);
cout<<"Resistance of Slab Rs="<<rslab<<" "<<deg<<" C/W\n";
q=(t1-t2)/rslab;
cout<<"Amount of Heat Transfer Q="<<q<<" W\n",q;
for(;;)
{
cout<<"\n1.find T(x)\n2.find x\n3.Back to main menu\n";
cin>>ch;
cout<<"\nNote: Enter all variables in SI units\n";
switch(ch)
{
case 1:cout<<"enter distance x\n";
       cin>>x;
       tx=(-1/beta)+sqrt((pow((1/beta+t1),2)-(2/beta*x/t*(t1-t2)*(1+beta*tm))));
       cout<<"T(x)="<<tx<<" "<<deg<<" C\n";
       break;
case 2:cout<<"enter temperature (at distance x) T(x)\n";
	cin>>tx;
       x=(beta*t*(pow((1/beta+t1),2)-pow((tx+1/beta),2)))/(2*(t1-t2)*(1+beta*tm));
       cout<<"x="<<x<<" m\n";
       break;
default:return;
}
}
}

void cti()
{
double r1,d2,r2,a,rc,tc,q1,rwire,q2,qmax,d1,ts,tb,k,h,l,t,rsphere;
int ch;

char sq=253,deg=248;
for(;;)
{
cout<<"1.cylinder\n2.sphere\n3.Return to main menu\n";
cin>>ch;
switch(ch)
{
case 1:cout<<"enter inner diameter d1\n";
       cin>>d1;
       cout<<"enter thickness t\n";
       cin>>t;
       cout<<"enter surface temperature Ts\n";
       cin>>ts;
       cout<<"enter ambient temperature Tb\n";
       cin>>tb;
       cout<<"enter thermal conductivity  K\n";
       cin>>k;
       cout<<"enter convection co-efficient h\n";
       cin>>h;
       cout<<"enter length l\n";
       cin>>l;
       r1=d1/2.0;
       cout<<"r1="<<r1<<" m\n";
       d2=d1+(2*t);
       cout<<"t="<<t<<" m\n";
       r2=d2/2.0;
       cout<<"r2="<<r2<<" m\n";
       a=3.142*d1*l;
       cout<<"Area A="<<a<<" m"<<sq<<"\n"; //char square
       rc=k/h;
       cout<<"Critical radius rc="<<rc<<" m\n";
       tc=rc-r1;
       cout<<"Critical thickness tc="<<tc<<" m\n";
       q1=h*a*(ts-tb);
       cout<<"Heat dissipated without insulation Q1="<<q1<<" W\n";
       rwire=((log(r2/r1))/(2*3.142*k*l))+(1/(h*2*3.142*r2*l));
       cout<<"Thermal resistance Rwire="<<rwire<<" "<<deg<<"C/W\n";
       q2=(ts-tb)/rwire;
       cout<<"Heat dissipated with insulation Q2="<<q2<<" W\n";
       qmax=(ts-tb)/((log(rc/r1)/(2*3.142*k*l))+(1/(h*2*3.142*rc*l)));
       cout<<"Maximum heat dissipated Qmax="<<qmax<<" W\n";
       break;
case 2:cout<<"enter inner radius r1\n";
       cin>>r1;
       cout<<"enter thickness t\n";
       cin>>t;
       cout<<"enter temperature Ts\n";
       cin>>ts;
       cout<<"enter ambient temperature Tb\n";
       cin>>tb;
       cout<<"enter thermal conductivity K\n";
       cin>>k;
       cout<<"enter convection co-efficient h\n";
       cin>>h;
       r2=r1+t;
       cout<<"Outer radius r2="<<r2<<" m\n";
       rc=2*k/h;
       cout<<"Critical radius rc="<<rc<<" m\n";
       tc=rc-r1;
       cout<<"Critical thickness tc="<<tc<<" m\n";
       a=4*3.142*r1*r1;
       cout<<"Area A="<<a<<" m"<<sq<<"\n"; //char square
       q1=h*a*(ts-tb);
       cout<<"Heat dissipated without insulation Q1="<<q1<<" W\n";
       rsphere=((r2-r1)/(4*3.142*r1*r2))+(1/(h*4*3.142*r2*r2));
      cout<<"Thermal resistance Rsphere="<<rsphere<<" "<<deg<<"C/W\n";
       q2=(ts-tb)/rsphere;
      cout<<"Heat dissipated with insulation Q2="<<q2<<" W\n";
      qmax=(ts-tb)/(((rc-r1)/(4*3.142*r1*rc))+(1/(h*4*3.142*rc*rc)));
      cout<<"Maximum heat dissipated Qmax="<<qmax<<" W\n";
       break;
default:return;
}
}
}

