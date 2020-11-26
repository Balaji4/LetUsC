#include<iostream.h>
#include<conio.h>
#include<math.h>
void constvol();
void constpres();
void iso();
void adiabatic();
void poly();
int main()
{
int ch;
clrscr();
for(;;)
 {
 cout<<"\nMenu\n";
 cout<<"\n1:Constant Volume Process";
 cout<<"\n2:Constant Pressure Process";
 cout<<"\n3:Isothermal Process";
 cout<<"\n4:Adiabatic Process";
 cout<<"\n5:Polytropic Process";
 cout<<"\n6:Exit";
 cout<<"\n\nEnter your choice\n";
 cin>>ch;
 switch(ch)
  {
  case 1:constvol();
	 break;
  case 2:constpres();
	 break;
  case 3:iso();
	 break;
  case 4:adiabatic();
	 break;
  case 5:poly();
	 break;
  default:return 0;
  //case 5:return 0;
  //default:cout<<"Invalid choice entered");
  }
 }
}

void constvol()
{
double t1,t2,m,cv,dq,dw,du,p1,p2,dh,v;
cout<<"\nEnter initial temperature T1 (in kelvin):";
cin>>t1;
cout<<"\nEnter final temperature T2 (in kelvin):";
cin>>t2;
cout<<"\nEnter mass m (in KG):";
cin>>m;
cout<<"\nEnter cv (in KJ/KG):";
cin>>cv;
cout<<"\n Enter Pressure p1 (in bar)";
cin>>p1;
cout<<"\n Enter Pressure p2 (in bar)";
cin>>p2;
cout<<"\n Enter constant volume v (in meter cube)";
cin>>v;

du=m*cv*(t2-t1);
dw=-v*(p2-p1);
dh=du+(p2*v-p1*v);
dq=dw+dh;
cout<<"\ndW="<<dw<<" KJ";
cout<<"\ndu="<<du<<" KJ";
cout<<"\ndH="<<dh<<" KJ";
cout<<"\ndQ="<<dq<<" KJ";
}

void constpres()
{
double p,t1,t2,v1,v2,cp,dq,m,dw,du,dh;
cout<<"\nEnter pressure P(in bar):";
cin>>p;
cout<<"\nEnter initial temperature T1 (in kelvin):";
cin>>t1;
cout<<"\nEnter final temperature T2 (in kelvin):";
cin>>t2;
cout<<"\nEnter initial volume V1 (in meter cube):";
cin>>v1;
cout<<"\nEnter final volume V2 (in  meter cube):";
cin>>v2;
cout<<"\nEnter mass m:";
cin>>m;
cout<<"\nEnter  CP (in KJ/KG):";
cin>>cp;
du=m*cp*(t2-t1);
dw=0;
dh=du+(p*v2-p*v1);
dq=dh;
cout<<"\ndW="<<dw<<" KJ";
cout<<"\ndQ="<<dq<<" KJ";
cout<<"\ndu="<<du<<" KJ";
cout<<"\ndH="<<dh<<" KJ\n";
}

void iso()
{
double p1,p2,v1,v2,dq,dw,du,cv,dh,m;
cout<<"\nEnter p1 (in bar):";
cin>>p1;
cout<<"\nEnter p2 (in bar):";
cin>>p2;
cout<<"\nEnter v1 (in meter cube):";
cin>>v1;
cout<<"\nEnter v2 (in meter cube):";
cin>>v2;
cout<<"\nEnter CV (KJ/KG)\n";
cin>>cv;
cout<<"\nEnter mass m (in KG):";
cin>>m;
du=0;
dw=m*p1*v1*log(v2/v1);
dh=(p2*v2-p1*v1);
dq=dw+dh;
cout<<"\ndQ="<<dq<<" KJ";
cout<<"\ndW="<<dw<<" KJ";
cout<<"\ndu="<<du<<" KJ";
cout<<"\ndH="<<dh<<" KJ\n";
}

void adiabatic()
{
double m,p1,p2,v1,v2,cp,cv,gamma,dw,du,dh,dq,r,t1,t2;
cout<<"\nEnter p1 (in bar):";
cin>>p1;
cout<<"\nEnter p2 (in bar):";
cin>>p2;
cout<<"\nEnter v1 (in meter cube):";
cin>>v1;
cout<<"\nEnter v2 (in meter cube):";
cin>>v2;
cout<<"\nEnter t1 (in kelvin):";
cin>>t1;
cout<<"\nEnter t2 (in kelvin):";
cin>>t2;
cout<<"\nEnter cp:";
cin>>cp;
cout<<"\nEnter cv:";
cin>>cv;
cout<<"\n Enter r (in KJ/KG):";
cin>>r;
gamma=cp/cv;
cout<<"\nEnter mass m (in KG):";
cin>>m;
dw=(gamma/(gamma-1))*m*r*t1*(1-pow((p2/p1),(gamma-1)/gamma));
du=m*cv*(t2-t1);
dh=du+(p1*v1-p2*v2);
dq=dh+dw;

cout<<"\ndQ="<<dq<<" KJ";
cout<<"\ndW="<<dw<<" KJ";
cout<<" \ndH="<<dh<<" KJ";
cout<<"\ndu="<<du<<" KJ\n";
}

void poly()
{
double m,p1,p2,v1,v2,cp,cv,n,dw,du,dh,dq,r,t1,t2;
cout<<"\nEnter p1 (in bar):";
cin>>p1;
cout<<"\nEnter p2 (in bar):";
cin>>p2;
cout<<"\nEnter v1 (in meter cube):";
cin>>v1;
cout<<"\nEnter v2 (in meter cube):";
cin>>v2;
cout<<"\nEnter t1 (in kelvin):";
cin>>t1;
cout<<"\nEnter t2 (in kelvin):";
cin>>t2;
cout<<"\nEnter cp:";
cin>>cp;
cout<<"\nEnter cv:";
cin>>cv;
cout<<"\n Enter r (in KJ/KG):";
cin>>r;
cout<<"\nEnter mass m (in KG):";
cin>>m;
cout<<"\nEnter n:";
cin>>n;
dw=(n/(n-1))*m*r*t1*(1-pow((p2/p1),(n-1)/n));
du=m*cv*(t2-t1);
dh=du+(p1*v1-p2*v2);
dq=dh+dw;

cout<<"\ndQ="<<dq<<" KJ";
cout<<"\ndW="<<dw<<" KJ";
cout<<" \ndH="<<dh<<" KJ";
cout<<"\ndu="<<du<<" KJ\n";
}