#include<stdio.h>
#include<math.h>
double min(double x, double y)
{
return(x<y?x:y);
}
double max(double x,double y)
{
return(x>y?x:y);
}
double gcd(double x,double y)
{
if(x==y)
return(x);
else
return(gcd(min(x,y),max(x,y)-min(x,y)));
}
long double modexp(long double a,long double x,long double n)
{
long double r=1;
while(x>0)
{
if ((int)(fmodl(x,2))==1)
{
r=fmodl((r*a),n);
}
a=fmodl((a*a),n);
x/=2;
}
return(r);
}
int main()
{
long double p,q,phi,n,e,d,cp,cq,dp,dq,mp,mq,sp,sq,rp,rq,qInv,h;
long double ms,es,ds;
do{
printf("\n Enter prime numbers p and q:");
scanf(" %Lf %Lf",&p,&q);
}
while(p==q);
n=p*q;
phi=(p-1)*(q-1);
do{
printf("\n Enter prime value of e:");
scanf(" %Lf",&e);
}
while((gcd(e,phi)!=1)&&e>phi); /*for e being relatively prime to phi */
for(d=1;d<phi;++d)
{
if(fmod((e*d),phi)==1)
break;
}
printf("\n D within main = %Lf",d);
/* public key is {n,e} private key is d */
printf("\n Enter the message:");
scanf(" %Lf",&ms);
es=modexp(ms,e,n);
ds=modexp(es,d,n);
printf("\n Original Message : %Lf",ms);
printf("\n Encrypted Message : %Lf",es);
printf("\n Decrypted Message : %Lf\n",ds);
return(0);
}