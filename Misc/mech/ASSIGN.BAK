#include<iostream.h>
#include<conio.h>
#include<math.h>
void constvol();
void constpres();
void iso();
void adiabatic();
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
 cout<<"\n5:Exit";
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
  default:return 0;
  //case 5:return 0;
  //default:cout<<"Invalid choice entered");
  }
 }
}

void constvol()
{
double t1,t2,m,cv,dq,dw,du;
cout<<"\nEnter initial temperature T1 (in kelvin):";
cin>>t1;
cout<<"\nEnter final temperature T2 (in kelvin):";
cin>>t2;
cout<<"\nEnter mass m (in KG):";
cin>>m;
cout<<"\nEnter cv (in KJ/KG):";
cin>>cv;
dq=m*cv*(t2-t1);
dw=0;
du=dq-dw;
cout<<"\ndQ="<<dq<<" KJ";
cout<<"\ndu="<<du<<" KJ";
cout<<"\ndW="<<dw;
}

void constpres()
{
double p,t1,t2,v1,v2,cp,dq,m,dw,du;
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
dq=m*cp*(t2-t1);
dw=(p*(v2-v1))*100;
du=dq-dw;
cout<<"\ndW="<<dw<<" KJ";
cout<<"\ndQ="<<dq<<" KJ";
cout<<"\ndu="<<du<<" KJ\n";
}

void iso()
{
double p1,v1,v2,dq,du,dw;
cout<<"\nEnter p1 (in bar):";
cin>>p1;
cout<<"\nEnter v1 (in meter cube):";
cin>>v1;
cout<<"\nEnter v2 (in meter cube):";
cin>>v2;
dq=p1*v1*log(v2/v1);
du=0;
dw=dq;
cout<<"\ndQ="<<dq<<" KJ";
cout<<"\ndW="<<dw<<" KJ";
cout<<"\ndu="<<du<<" KJ\n";
}

void adiabatic()
{
double m,p1,p2,v1,v2,cpcv,wd,du,dq;
cout<<"\nEnter p1 (in bar):";
cin>>p1;
cout<<"\nEnter p2 (in bar):";
cin>>p2;
cout<<"\nEnter v1 (in meter cube):";
cin>>v1;
cout<<"\nEnter v2 (in meter cube):";
cin>>v2;
cout<<"\nEnter cp/cv:";
cin>>cpcv;
cout<<"\nEnter mass m (in KG):";
cin>>m;
wd=(p1*v1-p2*v2)/(cpcv-1);
dq=0;
du=dq-wd;
cout<<"\ndQ="<<dq<<" KJ";
cout<<"\ndW="<<wd<<" KJ";
cout<<"\ndu="<<du<<" KJ\n";
}