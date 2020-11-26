#include<stdio.h>
#include<math.h>
#include<conio.h>
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
printf("\n1) To calculate variable thermal conductivity \n");
printf("2) To calculate critical thickness of insulation\n" );
printf("3) Exit\n");
scanf("%d",&choice);
printf("\n Note: Enter all units in SI \n");
switch(choice)
{
case 1:printf("enter T1\n");
      scanf("%lf",&t1);
      printf("enter T2\n");
      scanf("%lf",&t2);
      printf("enter length of slab L\n");
      scanf("%lf",&l);
      printf("enter breadth of slab b\n");
      scanf("%lf",&b);
       printf("enter thickness t\n");
       scanf("%lf",&t);
      printf("enter coefficient Ko\n");
      scanf("%lf",&ko);
       printf("enter %c\n",225);//beta
       scanf("%lf",&beta);
//      printf("enter a");
  //   scanf("%lf",&a);
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
printf("Area A=%lf m%c\n",a,253);//c for square
tm=(t1+t2)/2.0;
printf("Mean tempareture Tm=%lf %cC\n",tm,248); // char degree
km=ko*(1+beta*tm);
printf("Variable thermal conductivity Km=%lf W/m%cC\n",km,248);
rslab=t/(km*a);
printf("Resistance of Slab Rs=%lf %cC/W\n",rslab,248);
q=(t1-t2)/rslab;
printf("Amount of Heat Transfer Q=%lf W\n",q);
for(;;)
{
printf("\n1.find T(x)\n2.find x\n3.Back to main menu\n");
scanf("%d",&ch);
printf("\nNote: Enter all variables in SI units\n");
switch(ch)
{
case 1:printf("enter distance x\n");
       scanf("%lf",&x);
       tx=(-1/beta)+sqrt((pow((1/beta+t1),2)-(2/beta*x/t*(t1-t2)*(1+beta*tm))));
       printf("T(x)=%lf %cC\n",tx,248);
       break;
case 2:printf("enter temperature (at distance x) T(x)\n");
	scanf("%lf",&tx);
       x=(beta*t*(pow((1/beta+t1),2)-pow((tx+1/beta),2)))/(2*(t1-t2)*(1+beta*tm));
       printf("x=%lf m\n",x);
       break;
default:return;
}
}
}

void cti()
{
double r1,d2,r2,a,rc,tc,q1,rwire,q2,qmax,d1,ts,tb,k,h,l,t,rsphere;
int ch;
for(;;)
{
printf("1.cylinder\n2.sphere\n3.Return to main menu\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("enter inner diameter d1\n");
       scanf("%lf",&d1);
       printf("enter thickness t\n");
       scanf("%lf",&t);
       printf("enter surface temperature Ts\n");
       scanf("%lf",&ts);
       printf("enter ambient temperature Tb\n");
       scanf("%lf",&tb);
       printf("enter thermal conductivity  K\n");
       scanf("%lf",&k);
       printf("enter convection co-efficient h\n");
       scanf("%lf",&h);
       printf("enter length l\n");
       scanf("%lf",&l);
       r1=d1/2.0;
       printf("r1=%lf m\n",r1);
       d2=d1+(2*t);
       printf("t=%lf m\n",t);
       r2=d2/2.0;
       printf("r2=%lf m\n",r2);
       a=3.142*d1*l;
       printf("Area A=%lf m%c\n",a,253); //char square
       rc=k/h;
       printf("Critical radius rc=%lf m\n",rc);
       tc=rc-r1;
       printf("Critical thickness tc=%lf m\n",tc);
       q1=h*a*(ts-tb);
       printf("Heat dissipated without insulation Q1=%lf W\n",q1);
       rwire=((log(r2/r1))/(2*3.142*k*l))+(1/(h*2*3.142*r2*l));
       printf("Thermal resistance Rwire=%lf %cC/W\n",rwire,248);
       q2=(ts-tb)/rwire;
       printf("Heat dissipated with insulation Q2=%lf W\n",q2);
       qmax=(ts-tb)/((log(rc/r1)/(2*3.142*k*l))+(1/(h*2*3.142*rc*l)));
       printf("Maximum heat dissipated Qmax=%lf W\n",qmax);
       break;
case 2:printf("enter inner radius r1\n");
       scanf("%lf",&r1);
       printf("enter thickness t\n");
       scanf("%lf",&t);
       printf("enter temperature Ts\n");
       scanf("%lf",&ts);
       printf("enter ambient temperature Tb\n");
       scanf("%lf",&tb);
       printf("enter thermal conductivity K\n");
       scanf("%lf",&k);
       printf("enter convection co-efficient h\n");
       scanf("%lf",&h);
       r2=r1+t;
       printf("Outer radius r2=%lf m\n",r2);
       rc=2*k/h;
       printf("Critical radius rc=%lf m\n",rc);
       tc=rc-r1;
       printf("Critical thickness tc=%lf m\n",tc);
       a=4*3.142*r1*r1;
       printf("Area A=%lf m%c\n",a,253); //char square
       q1=h*a*(ts-tb);
       printf("Heat dissipated without insulation Q1=%lf W\n",q1);
       rsphere=((r2-r1)/(4*3.142*r1*r2))+(1/(h*4*3.142*r2*r2));
      printf("Thermal resistance Rsphere=%lf %cC/W\n",rsphere,248);
       q2=(ts-tb)/rsphere;
      printf("Heat dissipated with insulation Q2=%lf W\n",q2);
      qmax=(ts-tb)/(((rc-r1)/(4*3.142*r1*rc))+(1/(h*4*3.142*rc*rc)));
      printf("Maximum heat dissipated Qmax=%lf W\n",qmax);
       break;
default:return;
}
}
}



