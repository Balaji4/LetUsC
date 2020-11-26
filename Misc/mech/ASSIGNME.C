#include<stdio.h>
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
 printf("\nMenu\n");
 printf("\n1:Constant Volume Process");
 printf("\n2:Constant Pressure Process");
 printf("\n3:Isothermal Process");
 printf("\n4:Adiabatic Process");
 printf("\n5:Exit");
 printf("\n\nEnter your choice\n");
 scanf("%d",&ch);
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
  //default:printf("Invalid choice entered");
  }
 }
}

void constvol()
{
double t1,t2,m,cv,dq,dw,du;
printf("\nEnter initial temperature T1 (in kelvin):");
scanf("%lf",&t1);
printf("\nEnter final temperature T2 (in kelvin):");
scanf("%lf",&t2);
printf("\nEnter mass m (in KG):");
scanf("%lf",&m);
printf("\nEnter cv (in KJ/KG):");
scanf("%lf",&cv);
dq=m*cv*(t2-t1);
dw=0;
du=dq-dw;
printf("\ndQ=%lf KJ",dq);
printf("\ndu=%lf KJ",du);
printf("\ndW=%lf",dw);
}

void constpres()
{
double p,t1,t2,v1,v2,cp,dq,m,dw,du;
printf("\nEnter pressure P(in bar):");
scanf("%lf",&p);
printf("\nEnter initial temperature T1 (in kelvin):");
scanf("%lf",&t1);
printf("\nEnter final temperature T2 (in kelvin):");
scanf("%lf",&t2);
printf("\nEnter initial volume V1 (in meter cube):");
scanf("%lf",&v1);
printf("\nEnter final volume V2 (in  meter cube):");
scanf("%lf",&v2);
printf("\nEnter mass m:");
scanf("%lf",&m);
printf("\nEnter  CP (in KJ/KG):");
scanf("%lf",&cp);
dq=m*cp*(t2-t1);
dw=(p*(v2-v1))*100;
du=dq-dw;
printf("\ndW=%lf KJ",dw);
printf("\ndQ=%lf KJ",dq);
printf("\ndu=%lf KJ\n",du);
}

void iso()
{
double p1,v1,v2,dq,du,dw;
printf("\nEnter p1 (in bar):");
scanf("%lf",&p1);
printf("\nEnter v1 (in meter cube):");
scanf("%lf",&v1);
printf("\nEnter v2 (in meter cube):");
scanf("%lf",&v2);
dq=p1*v1*log(v2/v1);
du=0;
dw=dq;
printf("\ndQ=%lf KJ",dq);
printf("\ndW=%lf KJ",dw);
printf("\ndu=%lf KJ\n",du);
}

void adiabatic()
{
double m,p1,p2,v1,v2,cpcv,wd,du,dq;
printf("\nEnter p1 (in bar):");
scanf("%lf",&p1);
printf("\nEnter p2 (in bar):");
scanf("%lf",&p2);
printf("\nEnter v1 (in meter cube):");
scanf("%lf",&v1);
printf("\nEnter v2 (in meter cube):");
scanf("%lf",&v2);
printf("\nEnter cp/cv:");
scanf("%lf",&cpcv);
printf("\nEnter mass m (in KG):");
scanf("%lf",&m);
wd=(p1*v1-p2*v2)/(cpcv-1);
dq=0;
du=dq-wd;
printf("\ndQ=%lf KJ",dq);
printf("\ndW=%lf KJ",wd);
printf("\ndu=%lf KJ\n",du);
}